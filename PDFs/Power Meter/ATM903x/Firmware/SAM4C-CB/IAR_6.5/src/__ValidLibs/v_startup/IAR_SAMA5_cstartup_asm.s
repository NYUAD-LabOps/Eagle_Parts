;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Part one of the system initialization code,
;; contains low-level
;; initialization.
;;
;; Copyright 2007 IAR Systems. All rights reserved.
;;
;; $Revision: 46842 $
;;

        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION IRQ_STACK:DATA:NOROOT(3)
        SECTION FIQ_STACK:DATA:NOROOT(3)
        SECTION CSTACK:DATA:NOROOT(3)

;
; The module in this file are included in the libraries, and may be
; replaced by any user-defined modules that define the PUBLIC symbol
; __iar_program_start or a user defined start symbol.
;
; To override the cstartup defined in the library, simply add your
; modified version to the workbench project.

        SECTION .intvec:CODE:NOROOT(2)

        PUBLIC  __vector
        PUBLIC  __iar_program_start
        EXTERN  Undefined_Handler
        EXTERN  SWI_Handler
        EXTERN  Prefetch_Handler
        EXTERN  Abort_Handler
;        EXTERN  IRQ_Handler
        PUBLIC  IRQ_Handler
        EXTERN  FIQ_Handler

        DATA

__iar_init$$done:               ; The vector table is not needed
                                ; until after copy initialization is done

__vector:                       ; Make this a DATA label, so that stack usage
                                ; analysis doesn't consider it an uncalled fun

        ARM

        ; All default exception handlers (except reset) are
        ; defined as weak symbol definitions.
        ; If a handler is defined by the application it will take precedence.
        LDR     PC,Reset_Addr           ; Reset
        LDR     PC,Undefined_Addr       ; Undefined instructions
        LDR     PC,SWI_Addr             ; Software interrupt (SWI/SVC)
        LDR     PC,Prefetch_Addr        ; Prefetch abort
        LDR     PC,Abort_Addr           ; Data abort
        DCD     0                       ; RESERVED
        LDR     PC,IRQ_Addr             ; IRQ
        LDR     PC,FIQ_Addr             ; FIQ

        DATA

Reset_Addr:     DCD   __iar_program_start
Undefined_Addr: DCD   Undefined_Handler
SWI_Addr:       DCD   SWI_Handler
Prefetch_Addr:  DCD   Prefetch_Handler
Abort_Addr:     DCD   Abort_Handler
; IRQ_Addr:       DCD   IRQ_Handler
IRQ_Addr:       DCD   IRQ_Handler
FIQ_Addr:       DCD   FIQ_Handler


; --------------------------------------------------
; ?cstartup -- low-level system initialization code.
;
; After a reset execution starts here, the mode is ARM, supervisor
; with interrupts disabled.
;



        SECTION .text:CODE:NOROOT(2)

        EXTERN  __cmain
        REQUIRE __vector
        EXTWEAK __iar_init_core
        EXTWEAK __iar_init_vfp


        ARM

__iar_program_start:
?cstartup:

;
; Add initialization needed before setup of stackpointers here.
;

;
; Initialize the stack pointers.
; The pattern below can be used for any of the exception stacks:
; FIQ, IRQ, SVC, ABT, UND, SYS.
; The USR mode uses the same stack as SYS.
; The stack segments must be defined in the linker command file,
; and be declared above.
;


; --------------------
; Mode, correspords to bits 0-5 in CPSR

MODE_MSK DEFINE 0x1F            ; Bit mask for mode bits in CPSR

USR_MODE DEFINE 0x10            ; User mode
FIQ_MODE DEFINE 0x11            ; Fast Interrupt Request mode
IRQ_MODE DEFINE 0x12            ; Interrupt Request mode
SVC_MODE DEFINE 0x13            ; Supervisor mode
ABT_MODE DEFINE 0x17            ; Abort mode
UND_MODE DEFINE 0x1B            ; Undefined Instruction mode
SYS_MODE DEFINE 0x1F            ; System mode


        MRS     r0, cpsr                ; Original PSR value

        ;; Set up the interrupt stack pointer.

        BIC     r0, r0, #MODE_MSK       ; Clear the mode bits
        ORR     r0, r0, #IRQ_MODE       ; Set IRQ mode bits
        MSR     cpsr_c, r0              ; Change the mode
        LDR     sp, =SFE(IRQ_STACK)     ; End of IRQ_STACK
        BIC     sp,sp,#0x7              ; Make sure SP is 8 aligned

        ;; Set up the fast interrupt stack pointer.

        BIC     r0, r0, #MODE_MSK       ; Clear the mode bits
        ORR     r0, r0, #FIQ_MODE       ; Set FIR mode bits
        MSR     cpsr_c, r0              ; Change the mode
        LDR     sp, =SFE(FIQ_STACK)     ; End of FIQ_STACK
        BIC     sp,sp,#0x7              ; Make sure SP is 8 aligned

        ;; Set up the normal stack pointer.

        BIC     r0 ,r0, #MODE_MSK       ; Clear the mode bits
        ORR     r0 ,r0, #SYS_MODE       ; Set System mode bits
        MSR     cpsr_c, r0              ; Change the mode
        LDR     sp, =SFE(CSTACK)        ; End of CSTACK
        BIC     sp,sp,#0x7              ; Make sure SP is 8 aligned

        ;; Turn on core features assumed to be enabled.
          FUNCALL __iar_program_start, __iar_init_core
        BL      __iar_init_core

        ;; Initialize VFP (if needed).
          FUNCALL __iar_program_start, __iar_init_vfp
        BL      __iar_init_vfp

;;;
;;; Add more initialization here
;;;

;;; Continue to __cmain for C-level initialization.

          FUNCALL __iar_program_start, __cmain
        B       __cmain



;------------------------------------------------------------------------------
;- Function             : IRQ_Handler
;- Treatments           : IRQ Controller Interrupt Handler.
;- Called Functions     : AIC_IVR[interrupt]
;------------------------------------------------------------------------------
I_BIT     DEFINE  0x80
AT91C_BASE_AIC   DEFINE   0xFFFFF000
AIC_IVR          DEFINE   0x10
AIC_EOICR        DEFINE   0x38


        SECTION .text:CODE:NOROOT(2)
        ARM
IRQ_Handler:

;- Manage Exception Entry
;- Adjust and save LR_irq in IRQ stack
            sub         lr, lr, #4
            stmfd       sp!, {lr}
;- Save and r0 in IRQ stack
            stmfd       sp!, {r0}

;- Write in the IVR to support Protect Mode
;- No effect in Normal Mode
;- De-assert the NIRQ and clear the source in Protect Mode
            ldr         r14, =AT91C_BASE_AIC
	    ldr         r0 , [r14, #AIC_IVR]
	    str         r14, [r14, #AIC_IVR]

;- Enable Interrupt and Switch in Supervisor Mode
           msr         CPSR_c, #SVC_MODE

;- Save scratch/used registers and LR in User Stack
            stmfd       sp!, { r1-r3, r12, r14}

;- Branch to the routine pointed by the AIC_IVR
            mov         r14, pc
            bx          r0

;- Restore scratch/used registers and LR from User Stack
            ldmia       sp!, { r1-r3, r12, r14}

;- Disable Interrupt and switch back in IRQ mode
            msr         CPSR_c, #I_BIT | IRQ_MODE

;- Mark the End of Interrupt on the AIC
            ldr         r14, =AT91C_BASE_AIC
            str         r14, [r14, #AIC_EOICR]

;- Restore SPSR_irq and r0 from IRQ stack
            ldmia       sp!, {r0}

;- Restore adjusted  LR_irq from IRQ stack directly in the PC
            ldmia       sp!, {pc}^
;------------------------------------------------------------------------------
;------------------------------------------------------------------------------




        END
