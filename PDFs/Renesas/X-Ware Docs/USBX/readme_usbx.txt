                        Express Logic's USBX for ARM9 

                        Using the GNU Developer Suite


1.  Installation

USBX for ARM9 is delivered on a single CD-ROM compatible disk.  
The entire distribution can be found in the sub-directory:

\usbx

To install USBX to your hard-disk, either run the supplied installer 
program Setup.exe or copy the distribution from the CD manually. 

To copy the USBX distribution manually, copy all the contents of 
the USBX sub-directory on the distribution disk. The following is an 
example MS-DOS copy command (assuming source is D: and C: is your hard-drive):

d:\usbx> xcopy /S *.* C:\threadx\arm9\gnu


2.  Building the USBX run-time Library

First make sure you are in the ThreadX directory you have created on 
your hard-drive. Also, make sure that you have setup your path and other 
environment variables necessary for the GNU development environment. 
At this point you may run the build_usbx.bat batch file. This will 
build the USBX run-time environment in the ThreadX directory.

C:\threadx\arm9\gnu> build_usbx 

You should observe assembly and compilation of a series of USBX source 
files. At the end of the batch file, they are all combined into the 
run-time library file: ux.a. This file must be linked with your 
application in order to use USBX.


3.  USBX ARM9 Demonstration

The USBX demonstration is designed to execute under the ARM9 simulation
environment using the GNU tools. The instructions that follow describe
how to get the USBX evaluation setup and running.

Building the demonstration is easy, simply execute the build_usbx_demo.bat 
batch file while inside your ThreadX directory on your hard-disk.

C:\threadx\arm9\gnu> build_usbx_demo

You should observe the compilation of demo_usbx.c and linking with tx.a 
and ux.a. The resulting file demo_usbx.out is a binary file that can be 
downloaded and executed on the ARM9 simulator or on hardware.

The USBX demonstration utilizes a simulated host and device controller 
and a simple data pump class. Additional demonstrations can be found 
in the "usbx_examples" sub-directory.


4.  USBX Configuration Options

There are several macros that define how fast the system time/date is updated 
as well as dependencies associated with the underlying operating system, which
is typically ThreadX. The macros are defined in ux_port.h. Nearly all of the
port specific logic is defined in ux_port.h. The following is a list of macros 
and their associated meaning:

        macro                                   meaning

    UX_MAX_CLASS_DRIVER             Maximum number of class drivers, 
                                    default is 8.
    UX_MAX_HCD                      Maximum number of USB Host Controllers (HCDs),
                                    default is 1.
    UX_MAX_DEVICES                  Maximum number of USB Devices Supported, 
                                    default is 8.
    UX_MAX_ED                       Maximum number of endpoints, default is 80.
    UX_MAX_TD                       Maximum number of TDs, default is 32.
    UX_MAX_ISO_TD                   Maximum number of ISO TDs, default is 128.
    UX_THREAD_STACK_SIZE            Size of USBX thread stack, default is 4KB.
    UX_THREAD_PRIORITY_ENUM         Priority of USBX ENUM thread, default is 20.
    UX_THREAD_PRIORITY_HCD          Priority of USBX HCD thread, default is 2.
    UX_NO_TIME_SLICE                Time-slice option for USBX threads, default is
                                    0 (no time-slicing).
    UX_USE_IO_INSTRUCTIONS          If defined, USBX generates code to use special 
                                    IO instructions. By default this is not defined.
    UX_NO_FILEX                     If defined, FileX is not needed to compile
                                    USBX and the user would have to create its own
                                    FileX style calls for the storage class to work.
                                    By default, this is not defined.


6.  Improving Performance

The distribution version of USBX is built without any compiler optimizations.
This makes it easy to debug because you can trace or set breakpoints inside 
of USBX itself. Of course, this costs some performance. To make it run 
faster, you can change the build_usbx.bat batch file to enable all compiler 
optimizations.  


7.  Revision History

For generic code revision information, please refer to the readme_usbx_generic.txt
file, which is included in your distribution. The following details the revision
information associated with this specific port of USBX:

07/04/2008  USBX ARM9/GNU version 5.1. This release includes the following 
            modifications:
        
            ux_port.h                                       Updated version ID string.

04/03/2008  Initial USBX version for ARM9 using the GNU tools.


Copyright(c) 1996-2008 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com
