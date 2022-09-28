                        Express Logic's USBX  

1. Revision History

For installation and usage please see the readme_usbx.txt file included
in your distribution. For port-specific version information, please refer
to the bottom of readme_usbx.txt. The USBX generic code version 
information is as follows:

06/01/2017  USBX generic code version 5.8. This release includes the following  modifications:
            
            *.*                                             Changed format of _ux_system_error_handler.
            ux_api.h                                        Added support for new classes, new prototypes, error traps.
                                                            Added timeout values for control/non control transfer.
                                                            Changed the transfer structure to add timeout values.
                                                            Added a macro to disable warning of parameter not used.
                                                            Added new trace events.
            ux_user.h                                       Added split for host/device with 2 #define.
            ux_utility_error_callback_register.c            Added to allow application to receive errors.
            ux_host_stack_transfer_request.c	            Added support for timeout values
            ux_host_class_hid.h                             Fixed TAG_LONG definition.
            ux_hcd_musb_asynchronous_endpoint_create.c      Replace TX_DISABLE definition.
            ux_hcd_musb_interrupt_endpoint_create.c         Replace TX_DISABLE definition.
            ux_hcd_musb_interrupt_handler.c                 Replace TX_DISABLE definition.
            ux_hcd_musb_request_transfer.c                  Filter for device presence.
            ux_hcd_rx_request_transfer.c                    Filter for device presence.
            ux_hcd_pic32_request_transfer.c                 Filter for device presence.
            ux_hcd_stm32_request_transfer.c                 Filter for device presence.
            ux_trace_object_register.c                      Fixed compiler warnings.
            ux_trace_object_unregister.c                    
                       
            ux_hcd_musb*.*                                  Added support for multiple devices.
            ux_host_class_pima.h                            Added _ux ux mapping
            ux_host_class_cdc_ecm.h                         Added _ux ux mapping
                        
            ux_utility_mutex_on.c                           Added mutex status check.
            ux_host_class_hid_local_item_parse.c            Changed status return mechanism.
            ux_host_class_storage_deactivate.c              Check for mounted media status when removing device


            ux_device_class_cdc_acm_ioctl.c                 Added support for changing DTR/RTS.
            ux_device_class_cdc_acm.h
            ux_device_class_cdc_acm_initialize.c                

            ux_host_stack_class_get.c                       Changed declaration for C++ compliancy.
            ux_host_stack_class_instance_create.c           Changed declaration for C++ compliancy.
            ux_host_stack_class_instance_destroy.c          Changed declaration for C++ compliancy.
            ux_host_stack_class_instance_get.c              Changed declaration for C++ compliancy.
            

            ux_hcd_rx_periodic_endpoint_destroy.c           Disable the endpoint in the controller when destroyed.
            ux_host_stack_configuration_interface_get.c     Fixed some possible NULL pointer dereferencing.
            ux_utility_error_callback_register.c            Changed calling parameters.
            ux_system_error_handler.c                       Changed calling parameters.
            ux_host_class_prolific_activate.c               Cleaned up repeated error checking.
            ux_host_class_pima_endpoints_get.c              Fixed error checking for memory allocation.


            The following files are changed for resetting calling parameters.

            ux_host_class_pima_device_info_get.c            
            ux_host_class_pima_num_objects_get.c         
            ux_host_class_pima_object_copy.c             
            ux_host_class_pima_object_delete.c
            ux_host_class_pima_object_handles_get.c
            ux_host_class_pima_object_info_get.c
            ux_host_class_pima_object_info_send.c
            ux_host_class_pima_object_move.c
            ux_host_class_pima_session_close.c
            ux_host_class_pima_session_open.c
            ux_host_class_pima_storage_ids_get.c
            ux_host_class_pima_storage_info_get.c


            ux_host_class_prolific_activate.c               Removed duplicated code.
            ux_host_class_prolific_endpoints_get.c          Fixed error checking for memory allocation.
            ux_host_class_cdc_ecm_endpoints_get.c           Fixed error checking for memory allocation.
            ux_host_class_hid_local_item_parse.c            Fixed missing breaks in HID delimiter parsing .
            ux_host_class_audio_device_type_get.c           Added missing break; statement in CS_INPUT terminal parsing.
            ux_hcd_ehci_asynchronous_endpoint_create.c      Added missing break; statement to filter low speed device.
            ux_hcd_ehci_interrupt_endpoint_create.c         Added missing break; statement to filter low speed device.
            ux_host_class_hid_transfer_request_completed.c  Fixed the callback report flag variable. 
            ux_host_class_hid_global_item_parse.c           Fixed global boundary.
            ux_host_class_hid_main_item_parse.c             Fixed collection boundary.
            ux_host_class_hid_local_item_parse.c            Fixed missing break in switch statement.
            ux_device_class_cdc_acm_read.c                  Fixed 64 bytes read with no ZLP.
            ux_host_class_hid_report_get.c                  Changed error code reporting.
            ux_host_class_hid_report_set.c                  Changed error code reporting.
            ux_host_stack_new_device_create.c               Changed error code reporting.
            ux_host_class_hid_transfer_request_completed.c  Changed error code reporting.
            ux_host_class_hid_keyboard_activate.c           Changed error code reporting.
            ux_host_class_hid_keyboard_thread.c             Changed error code reporting.
            ux_device_class_pima_thread.c                   Changed error code reporting.
            ux_device_class_pima_interrupt_thread.c         Changed error code reporting.
            ux_device_class_dpump_thread.c                  Changed error code reporting.
            ux_device_class_cdc_ecm_interrupt_thread.c      Changed error code reporting.
            ux_device_class_storage_thread.c                Changed error code reporting.
            ux_device_class_hid_interrupt_thread            Changed error code reporting.
            ux_host_class_cdc_acm_capabilities_get.c        Avoid compiler warnings by initializing stack values.
            ux_device_class_storage_read_toc.c              Set toc_length to a default state.
            ux_device_class_storage_read.c                  Moved trace event into the correct position.
            ux_host_class_asix_write.c                      Include error checking code for validity of instance.
            ux_utility_unicode_to_string.c                  Changed second source addressing.
            ux_host_class_cdc_acm_endpoints_get.c           Added better support for error checking.
            
            ux_dcd_musb_fifo_flush.c                        Fixed issues with Fifo management.
            ux_dcd_musb_interrupt_handler.c                 Fixed endpoint parsing sequence index.
            ux_host_stack_interface_instance_create.c       Fixed error code.  
            
            ux_system_initialize.c                          Added host/device split.
            ux_host_stack_initialize.c                      Added host/device split.
            ux_device_stack_initialize.c                    Added host/device split.
            
            ux_dcd_rx*.*                                    Modified all rx device driver files.
                                                    
            The following files are changed in order to modify RX host registers to support dynamic controller base.
            ux_hcd_rx_initialize.c                          
            ux_hcd_rx_register_set.c                        
            ux_hcd_rx_register_set.c                        
            ux_hcd_rx_register_write.c                      
            ux_hcd_rx_register_read.c                       
                
            ux_host_stack_cdc_acm.h                         Added API prototypes.
            
            ux_device_class_cdc_acm_read.c                  Fixed bug for multiple transactions and check for short packet/zlp.
            ux_host_class_storage_media_mount.c             Added code to return error when partition signature is not found in MBR.
            ux_host_stack_transfer_request_abort.c          Modified code to check for transfer status pending.
            ux_host_class_cdc_acm_reception_callback.c      Changed the address of the data_pointer in transfer request after adjustment.
            
            ux_dcd_at91hs_transfer_callback.c               Setting ZLP needed to be set after clearing received buffer flag.
            
            ux_host_class_audio_device_type_get.c           Added missing break.
            ux_device_stack_disconnect.c                    Call application if callback programmed.
            
            The following files are modified for changing call to function that schedules other threads.
            ux_host_class_swar_deactivate.c                 
            ux_host_class_storage_deactivate.c           
            ux_host_class_prolific_deactivate.c          
            ux_host_class_printer_deactivate.c           
            ux_host_class_pima_deactivate.c              
            ux_host_class_hub_deactivate.c               
            ux_host_class_hid_deactivate.c               
            ux_host_class_gser_deactivate.c              
            ux_host_class_cdc_ecm_deactivate.c           
            ux_host_class_cdc_acm_deactivate.c           
            ux_host_class_audio_deactivate.c             
            ux_host_class_asix_deactivate.c              

            Added support for CD-ROM support. The following files were modified or added:

            ux_device_class_storage.h
            ux_device_class_storage_activate.c
            ux_device_class_storage_control_request.c
            ux_device_class_storage_csw_send.c
            ux_device_class_storage_deactivate.c
            ux_device_class_storage_entry.c
            ux_device_class_storage_format.c
            ux_device_class_storage_get_configuration.c
            ux_device_class_storage_get_performance.c
            ux_device_class_storage_get_status_notification.c
            ux_device_class_storage_initialize.c
            ux_device_class_storage_inquiry.c
            ux_device_class_storage_mode_select.c
            ux_device_class_storage_mode_sense.c
            ux_device_class_storage_prevent_allow_media_removal.c
            ux_device_class_storage_read.c
            ux_device_class_storage_read_capacity.c
            ux_device_class_storage_read_disk_information.c
            ux_device_class_storage_read_dvd_structure.c
            ux_device_class_storage_read_format_capacity.c
            ux_device_class_storage_read_toc.c
            ux_device_class_storage_report_key.c
            ux_device_class_storage_request_sense.c
            ux_device_class_storage_start_stop.c
            ux_device_class_storage_test_ready.c
            ux_device_class_storage_thread.c
            ux_device_class_storage_verify.c
            ux_device_class_storage_write.c
            
            Added support for CDC ECM. The following files were added:
            
            ux_host_class_cdc_ecm.h
            ux_host_class_cdc_ecm_activate.c
            ux_host_class_cdc_ecm_configure.c
            ux_host_class_cdc_ecm_deactivate.c
            ux_host_class_cdc_ecm_endpoints_get.c
            ux_host_class_cdc_ecm_entry.c
            ux_host_class_cdc_ecm_interrupt_notification.c
            ux_host_class_cdc_ecm_read.c
            ux_host_class_cdc_ecm_reception_callback.c
            ux_host_class_cdc_ecm_thread.c
            ux_host_class_cdc_ecm_transmission_callback.c

            Added support for Altera device controller. The following files were added:
 
            ux_dcd_altera.h
            ux_dcd_altera_address_set.c
            ux_dcd_altera_delay.c
            ux_dcd_altera_endpoint_create.c
            ux_dcd_altera_endpoint_destroy.c
            ux_dcd_altera_endpoint_register_address_get.c
            ux_dcd_altera_endpoint_reset.c
            ux_dcd_altera_endpoint_stall.c
            ux_dcd_altera_endpoint_status.c
            ux_dcd_altera_fifo_flush.c
            ux_dcd_altera_fifo_read.c
            ux_dcd_altera_fifo_write.c
            ux_dcd_altera_frame_number_get.c
            ux_dcd_altera_function.c
            ux_dcd_altera_initialize.c
            ux_dcd_altera_initialize_complete.c
            ux_dcd_altera_interrupt_handler.c
            ux_dcd_altera_register_clear.c
            ux_dcd_altera_register_read.c
            ux_dcd_altera_register_set.c
            ux_dcd_altera_register_write.c
            ux_dcd_altera_state_change.c
            ux_dcd_altera_transfer_callback.c
            ux_dcd_altera_transfer_request.c

            Added support for the SAMA5 to the AT91HS controller. The following files were modified and added:

            ux_dcd_at91hs.h
            ux_dcd_at91hs_address_set.c
            ux_dcd_at91hs_endpoint_create.c
            ux_dcd_at91hs_endpoint_destroy.c
            ux_dcd_at91hs_endpoint_reset.c
            ux_dcd_at91hs_endpoint_stall.c
            ux_dcd_at91hs_endpoint_status.c
            ux_dcd_at91hs_fifo_read.c
            ux_dcd_at91hs_fifo_write.c
            ux_dcd_at91hs_frame_number_get.c
            ux_dcd_at91hs_function.c
            ux_dcd_at91hs_initialize.c
            ux_dcd_at91hs_initialize_complete.c
            ux_dcd_at91hs_interrupt_handler.c
            ux_dcd_at91hs_register_clear.c
            ux_dcd_at91hs_register_read.c
            ux_dcd_at91hs_register_set.c
            ux_dcd_at91hs_register_write.c
            ux_dcd_at91hs_state_change.c
            ux_dcd_at91hs_transfer_callback.c
            ux_dcd_at91hs_transfer_request.c
       
            The following files are added:
            
            ux_utility_thread_schedule_other.c
            ux_utility_error_callback_register.c
            ux_system_uninitialize.c
            ux_device_stack_uninitialize.c
            ux_device_stack_class_unregister.c
            ux_device_class_hid_uninitialize.c
            ux_device_class_cdc_acm_uninitialize.c

            
            

06/01/2014  USBX generic code version 5.7. This release includes the following 
            modifications:

            Added support for the musb generic controller. The following files were added:


            ux_dcd_musb.h
            ux_dcd_musb_address_set.c
            ux_dcd_musb_endpoint_create.c
            ux_dcd_musb_endpoint_destroy.c
            ux_dcd_musb_endpoint_reset.c
            ux_dcd_musb_endpoint_stall.c
            ux_dcd_musb_endpoint_status.c
            ux_dcd_musb_fifo_flush.c
            ux_dcd_musb_fifo_read.c
            ux_dcd_musb_fifo_write.c
            ux_dcd_musb_frame_number_get.c
            ux_dcd_musb_function.c
            ux_dcd_musb_initialize.c
            ux_dcd_musb_initialize_complete.c
            ux_dcd_musb_interrupt_handler.c
            ux_dcd_musb_register_clear.c
            ux_dcd_musb_register_read.c
            ux_dcd_musb_register_set.c
            ux_dcd_musb_register_write.c
            ux_dcd_musb_state_change.c
            ux_dcd_musb_transfer_callback.c
            ux_dcd_musb_transfer_request.c
            
            
            
            ux_hcd_musb.h
            ux_hcd_musb_asynchronous_endpoint_create.c
            ux_hcd_musb_asynchronous_endpoint_destroy.c
            ux_hcd_musb_asynch_queue_process.c
            ux_hcd_musb_asynch_schedule.c
            ux_hcd_musb_controller_disable.c
            ux_hcd_musb_delay.c
            ux_hcd_musb_ed_obtain.c
            ux_hcd_musb_ed_td_clean.c
            ux_hcd_musb_endpoint_reset.c
            ux_hcd_musb_entry.c
            ux_hcd_musb_frame_number_get.c
            ux_hcd_musb_frame_number_set.c
            ux_hcd_musb_initialize.c
            ux_hcd_musb_interrupt_endpoint_create.c
            ux_hcd_musb_interrupt_handler.c
            ux_hcd_musb_isochronous_endpoint_create.c
            ux_hcd_musb_isochronous_td_obtain.c
            ux_hcd_musb_iso_queue_process.c
            ux_hcd_musb_iso_schedule.c
            ux_hcd_musb_least_traffic_list_get.c
            ux_hcd_musb_periodic_endpoint_destroy.c
            ux_hcd_musb_periodic_schedule.c
            ux_hcd_musb_periodic_tree_create.c
            ux_hcd_musb_port_disable.c
            ux_hcd_musb_port_enable.c
            ux_hcd_musb_port_reset.c
            ux_hcd_musb_port_resume.c
            ux_hcd_musb_port_status_get.c
            ux_hcd_musb_port_suspend.c
            ux_hcd_musb_power_down_port.c
            ux_hcd_musb_power_on_port.c
            ux_hcd_musb_register_clear.c
            ux_hcd_musb_register_read.c
            ux_hcd_musb_register_set.c
            ux_hcd_musb_register_write.c
            ux_hcd_musb_regular_td_obtain.c
            ux_hcd_musb_request_bulk_transfer.c
            ux_hcd_musb_request_control_transfer.c
            ux_hcd_musb_request_interupt_transfer.c
            ux_hcd_musb_request_isochronous_transfer.c
            ux_hcd_musb_request_transfer.c
            ux_hcd_musb_td_schedule.c
            ux_hcd_musb_transfer_abort.c


            Added support for the Renesas RZ controller. The following files were added:

            ux_hcd_rz.h
            ux_hcd_rz_asynchronous_endpoint_create.c
            ux_hcd_rz_asynchronous_endpoint_destroy.c
            ux_hcd_rz_asynch_queue_process.c
            ux_hcd_rz_asynch_queue_process_bemp.c
            ux_hcd_rz_asynch_queue_process_brdy.c
            ux_hcd_rz_asynch_queue_process_nrdy.c
            ux_hcd_rz_asynch_queue_process_sign.c
            ux_hcd_rz_asynch_schedule.c
            ux_hcd_rz_buffer_empty_interrupt.c
            ux_hcd_rz_buffer_notready_interrupt.c
            ux_hcd_rz_buffer_read.c
            ux_hcd_rz_buffer_ready_interrupt.c
            ux_hcd_rz_buffer_write.c
            ux_hcd_rz_bulk_endpoint_create.c
            ux_hcd_rz_bulk_int_td_add.c
            ux_hcd_rz_controller_disable.c
            ux_hcd_rz_control_endpoint_create.c
            ux_hcd_rz_control_td_add.c
            ux_hcd_rz_current_endpoint_change.c
            ux_hcd_rz_data_buffer_size.c
            ux_hcd_rz_ed_obtain.c
            ux_hcd_rz_ed_td_clean.c
            ux_hcd_rz_endpoint_nak_set.c
            ux_hcd_rz_endpoint_reset.c
            ux_hcd_rz_entry.c
            ux_hcd_rz_fifoc_write.c
            ux_hcd_rz_fifod_write.c
            ux_hcd_rz_fifo_port_change.c
            ux_hcd_rz_fifo_read.c
            ux_hcd_rz_frame_number_get.c
            ux_hcd_rz_frame_number_set.c
            ux_hcd_rz_initialize.c
            ux_hcd_rz_interrupt_endpoint_create.c
            ux_hcd_rz_interrupt_handler.c
            ux_hcd_rz_isochronous_endpoint_create.c
            ux_hcd_rz_isochronous_td_obtain.c
            ux_hcd_rz_iso_queue_process.c
            ux_hcd_rz_iso_schedule.c
            ux_hcd_rz_least_traffic_list_get.c
            ux_hcd_rz_low_level_setup.c
            ux_hcd_rz_periodic_endpoint_destroy.c
            ux_hcd_rz_periodic_schedule.c
            ux_hcd_rz_periodic_tree_create.c
            ux_hcd_rz_port_disable.c
            ux_hcd_rz_port_enable.c
            ux_hcd_rz_port_reset.c
            ux_hcd_rz_port_resume.c
            ux_hcd_rz_port_status_get.c
            ux_hcd_rz_port_suspend.c
            ux_hcd_rz_power_down_port.c
            ux_hcd_rz_power_on_port.c
            ux_hcd_rz_power_root_hubs.c
            ux_hcd_rz_register_clear.c
            ux_hcd_rz_register_read.c
            ux_hcd_rz_register_set.c
            ux_hcd_rz_register_write.c
            ux_hcd_rz_regular_td_obtain.c
            ux_hcd_rz_request_bulk_transfer.c
            ux_hcd_rz_request_control_transfer.c
            ux_hcd_rz_request_interupt_transfer.c
            ux_hcd_rz_request_isochronous_transfer.c
            ux_hcd_rz_request_transfer.c
            ux_hcd_rz_td_add.c
            ux_hcd_rz_transfer_abort.c
            
            ux_dcd_rz.h
            ux_dcd_rz_address_set.c
            ux_dcd_rz_buffer_empty_interrupt.c
            ux_dcd_rz_buffer_notready_interrupt.c
            ux_dcd_rz_buffer_read.c
            ux_dcd_rz_buffer_ready_interrupt.c
            ux_dcd_rz_buffer_write.c
            ux_dcd_rz_current_endpoint_change.c
            ux_dcd_rz_data_buffersize.c
            ux_dcd_rz_endpoint_create.c
            ux_dcd_rz_endpoint_destroy.c
            ux_dcd_rz_endpoint_nak_set.c
            ux_dcd_rz_endpoint_reset.c
            ux_dcd_rz_endpoint_stall.c
            ux_dcd_rz_endpoint_status.c
            ux_dcd_rz_fifoc_write.c
            ux_dcd_rz_fifod_write.c
            ux_dcd_rz_fifo_port_change.c
            ux_dcd_rz_fifo_read.c
            ux_dcd_rz_frame_number_get.c
            ux_dcd_rz_function.c
            ux_dcd_rz_initialize.c
            ux_dcd_rz_initialize_complete.c
            ux_dcd_rz_interrupt_handler.c
            ux_dcd_rz_low_level_setup.c
            ux_dcd_rz_pipe_select.c
            ux_dcd_rz_register_clear.c
            ux_dcd_rz_register_read.c
            ux_dcd_rz_register_set.c
            ux_dcd_rz_register_write.c
            ux_dcd_rz_state_change.c
            ux_dcd_rz_transfer_callback.c
            ux_dcd_rz_transfer_request.c

            Added support for the Microsoft MTP extensions. Fixed bugs, the following files were added and modified:
            
            ux_device_class_pima_initialize.c
            ux_device_class_pima_object_prop_desc_get.c
            ux_device_class_pima_object_prop_value_get.c
            ux_device_class_pima_object_prop_value_set.c
            ux_device_class_pima_object_props_supported_get.c
            ux_device_class_pima_object_references_get.c
            ux_device_class_pima_object_references_set.c
            ux_device_class_pima_device_prop_desc_get.c
            ux_device_class_pima_device_prop_value_get.c
            ux_device_class_pima_device_prop_value_set.c
            ux_device_class_pima_object_data_get.c
            ux_device_class_pima_object_data_send.c
            ux_device_class_pima_object_handles_send.c
            ux_device_class_pima_object_info_get.c
            ux_device_class_pima_object_info_send.c
            ux_device_class_pima_objects_number_send.c
            ux_device_class_pima_partial_object_data_get.c
            ux_device_class_pima_response_send.c
            ux_device_class_pima_storage_format.c
            ux_device_class_pima_storage_id_send.c
            ux_device_class_pima_thread.c
            
            ux_utility_debug_log.c                      Added to provide debugging capability with log messages
            ux_system_error_handler.c                   Added to provide a error trap and error counter
                                                        Most USBX files modified to call this function when an
                                                        error happens.

            ux_host_class_storage_transport_bo.c        Fixed bug in reset sequence for BO transport
            ux_host_class_storage_deactivate.c          Fixed endpoint transfer abort calls
            ux_host_class_storage_transport.c           Fixed reset on stalled transfer.
            
            ux_device_class_cdc_ecm_bulkin_thread.c     Fixed packet release leak when link goes down.
            ux_device_class_rndis_bulkin_thread.c       "                   "                     "
            
            ux_host_stack_transfer_request_abort.c      Only wake up class semaphore on abort if transaction is pending.
            

            ux_device_stack_microsoft_extension_register.c
                                                        Added to support Microsoft Control commands 
            ux_dcd_ti18x_transfer_callback.c            Fixed bug when a SETUP packet is followed by no data payload.
            
            ux_device_class_cdc_acm.h                   Added prototypes definitions without leading _
            ux_device_class_dfu.h            
            ux_device_class_hid.h            
            ux_device_class_pima.h            
            ux_device_class_storage_entry
            ux_host_class_asix.h
            ux_host_class_audio.h
            ux_host_class_cdc_acm.h
            ux_host_class_gser.h
            ux_host_class_hid.h
            ux_host_class_hid_mouse.h
            ux_host_class_hid_keyboard.h
            ux_host_class_hid_remote_control.h
            ux_host_class_pima.h
            ux_host_class_printer.h
            ux_host_class_prolific.h
            ux_host_class_storage.h
            ux_host_class_swar.h
            
            ux_host_class_hid_mouse_activate.c          Added Hid instance in mouse instance descriptor
            ux_host_class_hid_mouse_callback.c          Changed x/y position update to use SCHAR values

            ux_api.h                                    Added SCHAR default type, and added new constants, 
                                                        macros for debug/log
            
            ux_dcd_stm32_delay.c                        Changed the delay variable and made it a #define
            ux_hcd_stm32_delay.c
            ux_dcd_stm32.h
            ux_hcd_stm32.h
            ux_dcd_stm32_interrupt_handler.c            Changed speed detection mechanism
            ux_dcd_stm32_transfer_callback.c            Forced flushing fifo when new setup packet is received
                                                        Memorize endpoint direction for STALL.
            ux_dcd_stm32_transfer_request.c             Added payload length reset
                                                        Fixed register setting.
                                                        
            ux_dcd_musb_endpoint_create.c               Fixed FIFO configuration address start
            ux_dcd_ti18x_endpoint_create.c              "                "              "                                                        
                                                        
            ux_dcd_pic32_endpoint_destroy.c             Fixed ping pong bdt flag error in removing endpoints                                                        
            ux_dcd_pic32_endpoint_stall_clear.c         Reset toggle flag when endpoint clears the STALL.
            ux_dcd_pic32_transfer_callback.c            Fixed Setup state machine.    

            ux_host_class_hid_report_descriptor_get.c   Fixed memory free when descriptor is corrupted.

            ux_pictbridge_dpsclient_input_object_prepare.c   Added functions for Abort/Continue
            ux_pictbridge_dpsclient_input_object_startjob.c  Change the XML buildup of the print info.
            ux_pictbridge_dpsclient_object_data_get.c   Change the call parameters to read data.
            ux_pictbridge_dpsclient_object_data_send.c  Add continue/abort events
            ux_pictbridge_dpsclient_object_info_get.c   Changed the way the object info is returned if not a script.
            ux_pictbridge_dpsclient_thread.c            Added callback to application if function supplied.

            ux_pictbridge.h                             Added prototypes for new functions
            ux_pictbridge_data.c                        Added ContinueJob, abort job ...
            
                                                        Added suport for new functions:
            ux_pictbridge_xml_function_input_getcapability_capability_layouts.c                                                        
            ux_pictbridge_xml_function_input_getcapability_capability_papertypes.c                                                        
            ux_pictbridge_xml_function_input_notifydevicestatus_capabilitychanged.c                                                        
            ux_pictbridge_xml_function_input_notifydevicestatus_disconnectenable.c                                                        
            ux_pictbridge_xml_function_input_notifydevicestatus_dpsprintservicestatus.c                                                        
            ux_pictbridge_xml_function_input_notifydevicestatus_errorreason.c                                                        
            ux_pictbridge_xml_function_input_notifydevicestatus_errorstatus.c                                                        
            ux_pictbridge_xml_function_input_notifydevicestatus_jobendreason.c                                                        
            ux_pictbridge_xml_function_input_notifydevicestatus_newjobok.c                                                        


10/10/2012  USBX generic code version 5.6. This release includes the following 
            modifications:
            
                                                        
            ux_api.h                                    Added new constants, and DFU class support                                             
            ux_device_stack_initialize.c                Added new USBX class names                                        
            
                                                        Changed dpump class to allow for change of alternate setting
                                                        The following files have been modified/added:
            ux_device_class_dpump.h
            ux_device_class_dpump_change.c
            ux_device_class_dpump_read.c
            ux_device_class_dpump_write.c
            ux_device_class_dpump_entry.c
            ux_host_class_dpump_ioctl.c            

                                                        Added support for the DFU device class, the following files have been added:

            ux_device_class_dfu.h
            ux_device_class_dfu_activate.c
            ux_device_class_dfu_control_request.c
            ux_device_class_dfu_deactivate.c
            ux_device_class_dfu_entry.c
            ux_device_class_dfu_initialize.c

            
                                                        Added support for the Renesas RX device controller. The following files have been added:
                                                        
            ux_dcd_rx.h
            ux_dcd_rx_address_set.c
            ux_dcd_rx_buffer_empty_interrupt.c
            ux_dcd_rx_buffer_notready_interrupt.c
            ux_dcd_rx_buffer_read.c
            ux_dcd_rx_buffer_ready_interrupt.c
            ux_dcd_rx_buffer_write.c
            ux_dcd_rx_current_endpoint_change.c
            ux_dcd_rx_data_buffersize.c
            ux_dcd_rx_endpoint_create.c
            ux_dcd_rx_endpoint_destroy.c
            ux_dcd_rx_endpoint_nak_set.c
            ux_dcd_rx_endpoint_reset.c
            ux_dcd_rx_endpoint_stall.c
            ux_dcd_rx_endpoint_status.c
            ux_dcd_rx_fifoc_write.c
            ux_dcd_rx_fifod_write.c
            ux_dcd_rx_fifo_port_change.c
            ux_dcd_rx_fifo_read.c
            ux_dcd_rx_frame_number_get.c
            ux_dcd_rx_function.c
            ux_dcd_rx_initialize.c
            ux_dcd_rx_initialize_complete.c
            ux_dcd_rx_interrupt_handler.c
            ux_dcd_rx_register_clear.c
            ux_dcd_rx_register_read.c
            ux_dcd_rx_register_set.c
            ux_dcd_rx_register_write.c
            ux_dcd_rx_state_change.c
            ux_dcd_rx_transfer_callback.c
            ux_dcd_rx_transfer_request.c

                                                        Added support for the Renesas RX host controller. The following files have been added:
                                                        
            ux_hcd_rx.h
            ux_hcd_rx_asynchronous_endpoint_create.c
            ux_hcd_rx_asynchronous_endpoint_destroy.c
            ux_hcd_rx_asynch_queue_process.c
            ux_hcd_rx_asynch_queue_process_bemp.c
            ux_hcd_rx_asynch_queue_process_brdy.c
            ux_hcd_rx_asynch_queue_process_nrdy.c
            ux_hcd_rx_asynch_queue_process_sign.c
            ux_hcd_rx_asynch_schedule.c
            ux_hcd_rx_buffer_empty_interrupt.c
            ux_hcd_rx_buffer_notready_interrupt.c
            ux_hcd_rx_buffer_read.c
            ux_hcd_rx_buffer_ready_interrupt.c
            ux_hcd_rx_buffer_write.c
            ux_hcd_rx_bulk_endpoint_create.c
            ux_hcd_rx_bulk_int_td_add.c
            ux_hcd_rx_controller_disable.c
            ux_hcd_rx_control_endpoint_create.c
            ux_hcd_rx_control_td_add.c
            ux_hcd_rx_contrxl_td_add.c
            ux_hcd_rx_current_endpoint_change.c
            ux_hcd_rx_data_buffer_size.c
            ux_hcd_rx_ed_obtain.c
            ux_hcd_rx_ed_td_clean.c
            ux_hcd_rx_endpoint_nak_set.c
            ux_hcd_rx_endpoint_reset.c
            ux_hcd_rx_entry.c
            ux_hcd_rx_fifoc_write.c
            ux_hcd_rx_fifod_write.c
            ux_hcd_rx_fifo_port_change.c
            ux_hcd_rx_fifo_read.c
            ux_hcd_rx_frame_number_get.c
            ux_hcd_rx_frame_number_set.c
            ux_hcd_rx_initialize.c
            ux_hcd_rx_interrupt_endpoint_create.c
            ux_hcd_rx_interrupt_handler.c
            ux_hcd_rx_isochronous_endpoint_create.c
            ux_hcd_rx_isochronous_td_obtain.c
            ux_hcd_rx_iso_queue_process.c
            ux_hcd_rx_iso_schedule.c
            ux_hcd_rx_least_traffic_list_get.c
            ux_hcd_rx_periodic_endpoint_destroy.c
            ux_hcd_rx_periodic_schedule.c
            ux_hcd_rx_periodic_tree_create.c
            ux_hcd_rx_port_disable.c
            ux_hcd_rx_port_enable.c
            ux_hcd_rx_port_reset.c
            ux_hcd_rx_port_resume.c
            ux_hcd_rx_port_status_get.c
            ux_hcd_rx_port_suspend.c
            ux_hcd_rx_power_down_port.c
            ux_hcd_rx_power_on_port.c
            ux_hcd_rx_power_root_hubs.c
            ux_hcd_rx_register_clear.c
            ux_hcd_rx_register_read.c
            ux_hcd_rx_register_set.c
            ux_hcd_rx_register_write.c
            ux_hcd_rx_regular_td_obtain.c
            ux_hcd_rx_request_bulk_transfer.c
            ux_hcd_rx_request_control_transfer.c
            ux_hcd_rx_request_interupt_transfer.c
            ux_hcd_rx_request_isochronous_transfer.c
            ux_hcd_rx_request_transfer.c
            ux_hcd_rx_td_add.c
            ux_hcd_rx_transfer_abort.c

                                                        Added support for the Renesas Spear320 host controller. The following files have been added:

            ux_dcd_spear.h
            ux_dcd_spear_address_set.c
            ux_dcd_spear_endpoint_create.c
            ux_dcd_spear_endpoint_destroy.c
            ux_dcd_spear_endpoint_reset.c
            ux_dcd_spear_endpoint_stall.c
            ux_dcd_spear_endpoint_status.c
            ux_dcd_spear_fifo_address_get.c
            ux_dcd_spear_fifo_read.c
            ux_dcd_spear_fifo_write.c
            ux_dcd_spear_frame_number_get.c
            ux_dcd_spear_function.c
            ux_dcd_spear_initialize.c
            ux_dcd_spear_initialize_complete.c
            ux_dcd_spear_interrupt_handler.c
            ux_dcd_spear_register_clear.c
            ux_dcd_spear_register_read.c
            ux_dcd_spear_register_set.c
            ux_dcd_spear_register_write.c
            ux_dcd_spear_state_change.c
            ux_dcd_spear_transfer_callback.c
            ux_dcd_spear_transfer_request.c

                                                        Added support for the host Generic Serial Class . The following files have been added:

            ux_host_class_gser.h
            ux_host_class_gser_activate.c
            ux_host_class_gser_command.c
            ux_host_class_gser_configure.c
            ux_host_class_gser_deactivate.c
            ux_host_class_gser_endpoints_get.c
            ux_host_class_gser_entry.c
            ux_host_class_gser_ioctl.c
            ux_host_class_gser_read.c
            ux_host_class_gser_reception_callback.c
            ux_host_class_gser_reception_start.c
            ux_host_class_gser_reception_stop.c
            ux_host_class_gser_write.c
            
            ux_dcd_stm32_interrupt_handler.c            Fixed a problem in the RESET signal treatment
            ux_dcd_stm32_transfer_callback.c            Fixed the SETUP OUT request code to include proper packet/buffer calculation.
            ux_dcd_stm32.h                              Added support for HS device side
            ux_dcd_stm32_initialize.c                   "              "               "

            ux_hcd_stm32_initialize_fscore.c            Added support for the STM32 FS2 support in Full Speed
            ux_hcd_stm32_initialize_hscore.c            Added support for the STM32 FS2 support in High Speed
            ux_hcd_stm32.h                              "                      "                            "
            ux_hcd_stm32_asynch_queue_process.c         Fixed problem with non-ULONG aligned buffers
            
                                                        Changed the structure name UX_STM32_ED into UX_HCD_STM32_ED the following files were modified:

            ux_hcd_stm32.h
            ux_hcd_stm32_asynchronous_endpoint_create.c
            ux_hcd_stm32_asynchronous_endpoint_destroy.c
            ux_hcd_stm32_asynch_queue_process.c
            ux_hcd_stm32_asynch_schedule.c
            ux_hcd_stm32_channel_halt.c
            ux_hcd_stm32_controller_disable.c
            ux_hcd_stm32_delay.c
            ux_hcd_stm32_ed_obtain.c
            ux_hcd_stm32_ed_td_clean.c
            ux_hcd_stm32_endpoint_reset.c
            ux_hcd_stm32_entry.c
            ux_hcd_stm32_frame_number_get.c
            ux_hcd_stm32_frame_number_set.c
            ux_hcd_stm32_initialize_fscore.c
            ux_hcd_stm32_initialize_hscore.c
            ux_hcd_stm32_interrupt_endpoint_create.c
            ux_hcd_stm32_interrupt_handler.c
            ux_hcd_stm32_isochronous_endpoint_create.c
            ux_hcd_stm32_isochronous_td_obtain.c
            ux_hcd_stm32_iso_queue_process.c
            ux_hcd_stm32_iso_schedule.c
            ux_hcd_stm32_least_traffic_list_get.c
            ux_hcd_stm32_periodic_endpoint_destroy.c
            ux_hcd_stm32_periodic_schedule.c
            ux_hcd_stm32_periodic_tree_create.c
            ux_hcd_stm32_port_disable.c
            ux_hcd_stm32_port_enable.c
            ux_hcd_stm32_port_reset.c
            ux_hcd_stm32_port_resume.c
            ux_hcd_stm32_port_status_get.c
            ux_hcd_stm32_port_suspend.c
            ux_hcd_stm32_power_down_port.c
            ux_hcd_stm32_power_on_port.c
            ux_hcd_stm32_register_clear.c
            ux_hcd_stm32_register_read.c
            ux_hcd_stm32_register_set.c
            ux_hcd_stm32_register_write.c
            ux_hcd_stm32_regular_td_obtain.c
            ux_hcd_stm32_request_bulk_transfer.c
            ux_hcd_stm32_request_control_transfer.c
            ux_hcd_stm32_request_interupt_transfer.c
            ux_hcd_stm32_request_isochronous_transfer.c
            ux_hcd_stm32_request_transfer.c
            ux_hcd_stm32_td_schedule.c
            ux_hcd_stm32_transfer_abort.c
                                                        

            ux_device_class_cdc_acm_control_request.c   Removed the lineCodingZero global variable
            ux_device_class_cdc_acm_write.c             Fixed function name
          
            ux_device_class_storage_csw_send.c          Changed the CSW synchronization with STALL status - 
                                                        synchronization is now happening in the ux_device_stack_transfer_request function


            Changed the deactivation mechanism to host classes. The following files were modified:

            ux_host_class_asix_deactivate.c
            ux_host_class_audio_deactivate.c
            ux_host_class_cdc_acm_deactivate.c
            ux_host_class_hid_deactivate.c
            ux_host_class_hub_deactivate.c
            ux_host_class_pima_deactivate.c
            ux_host_class_printer_deactivate.c
            ux_host_class_prolific_deactivate.c
            ux_host_class_storage_deactivate.c
            ux_host_class_swar_deactivate.c

            
            Added a mounting state for the class to synchronize between the composite classes of the CDC
            The following files were modified or added:
            ux_host_class_cdc_acm_activate.c
            ux_host_class_cdc_acm_ioctl.c               
            ux_host_class_prolific_activate.c
            ux_host_class_prolific_ioctl.c
            ux_host_class_storage_activate.c

            ux_host_class_hid_descriptor_parse.c        Fixed problem when parsing HID descriptor to remember HID interface
            ux_host_class_prolific_activate.c           Fixed problem during activation of the prolific class
            ux_host_class_storage_transport_bo.c        Added support for large SCSI read requests/write to make the number of sector read
                                                        irrespective of the controller memory capacity
            ux_hcd_ehci.h                               Added support for dynamic frame list
            ux_hcd_ehci_initialize.c                    "               "                  "

            ux_hcd_sh2a_port_reset.c                    Added support for SH7670 and SH7263
            ux_hcd_sh2a_interrupt_handler.c             "               "                  "
            ux_hcd_sh2a.h                               "               "                  "
            
             
            ux_dcd_lpc3180_interrupt_handler.c          Removed the variable lpc3180_endpoint_int_status
            ux_dcd_at91hs_endpoint_stall.c              Removed the variable at91hs_register
            
            ux_device_class_rndis_bulkin_thread.c       Fixed missing header size in the length of the RNDIS packets to be send/received
            ux_device_class_rndis_bulkout_thread.c      Fixed missing header size in the length of the RNDIS packets to be send/received
            
            ux_dcd_ti18x_endpoint_create.c              Changed strategy for flow control on the AM1808            
            ux_dcd_ti18x_transfer_callback.c            "                    "                        "
            ux_dcd_ti18x_transfer_request.c             "                    "                        "
            ux_dcd_ti18x_fifo_read.c                    Fixed problem in FIFO reading that was leading to overflow
            ux_dcd_ti18x_endpoint_reset.c               Fixed problem in resetting endpoint after STALL condition
            ux_dcd_ti18x_interrupt_handler.c            Changed strategy for high speed negotiation
            ux_dcd_ti18x_initialize                     Added support for high speed in AM1808
            
            ux_device_stack_transfer_request.c          Changed strategy for waiting for a STALLed endpoint to be reset
            ux_device_stack_alternate_setting_set.c     Fixed problem when changing alternate setting where endpoints resources were not
                                                        properly cleaned

            ux_host_stack_interface_setting_select.c    Fixed problem on the host stack about changing the alternate setting
            ux_host_stack_interface_set.c               Interface and alternate setting values were in reverse order

            ux_host_class_storage_media_mount.c         Fixed possible endianess issue when parsing the partition/boot sector

            ux_host_class_hub_port_change_connection_process.c 
                                                        Fixed an issue with device removal
            ux_*.c                                      Modified comment(s).
            ux_*.h                                      Modified comment(s).
                        

07/01/2011  USBX generic code version 5.5. This release includes the following 
            modifications:

            ux_hcd_ehci_power_root_hubs.c               Changes power sequence to preserve EHCI port register in case a non 100% EHCI
                                                        controller is used and has a previous setting in the PORT_SC register.
            ux_hcd_ehci_interrupt_endpoint_create.c     Fixed issues with 1ms interrupt pipes
            ux_hcd_ehci_interrupt_endpoint_destroy.c
            ux_hcd_ehci_request_bulk_transfer.c         Fixed support for ZLP bulk requests                                                
                                                        
            ux_host_class_prolific_activate.c           Added better support for Prolific PL2302 chips, differentiating between type 0,1 and HX.
            ux_host_class_prolific_setup.c
            ux_host_class_prolific_activate.c
            ux_host_class_prolific_ioctl.c
            ux_host_class_prolific_command.c
            ux_host_class_prolific.h
            
            ux_host_class_hid_keyboard.h                Fixed support for USB keyboard without hnumeric keypads
            ux_host_class_hid_keyboard_activate.c
            ux_host_class_hid_keyboard_callback.c

            ux_host_class_hid_report_get.c              Fixed GET_REPORT when dealing with multiple reports.
            ux_host_class_hid_report_set.c            
            
            ux_host_class_asix_reception_callback.c     Ensure proper alignement for prepend ptr
            ux_host_class_asix_thread.c                 "             "              "

                                                        Added support for NETX 5.3 and above. The following files have been added:
            ux_device_class_rndis.h
            ux_device_class_rndis_activate.c
            ux_device_class_rndis_deactivate.c
            ux_device_class_rndis_bulkout_thread.c
            ux_device_class_rndis_write.c
            
            ux_device_class_cdc_ecm.h
            ux_device_class_cdc_ecm_activate.c
            ux_device_class_cdc_ecm_deactivate.c
            ux_device_class_cdc_ecm_bulkout_thread.c
            ux_device_class_cdc_ecm_write.c
                        
            ux_host_class_asix_write.c
            ux_host_class_asix_activate.c
            ux_host_class_asix_deactivate.c
            ux_host_class_asix_setup.c
            ux_host_class_asix_interrupt_notification.c
            ux_host_class_asix_read.c
            ux_host_class_asix.h
            
                                                        Added files for NETX 5.3 and above support
            ux_network_driver.c
            ux_network_driver.h                                                        

            ux_host_class_hub.h                         Provide protection in hub class for removal/insertion within one hub polling frequency
            ux_host_class_hub_port_change_connnection_process.c
            ux_host_class_hub_descriptor_get.c          Added the HUB descriptor for stricter HUB GET_DESCRIPTOR requests
            
                                                        Renamed the device class CDC to CDC_ACM
                                                        Files affected
            ux_device_class_cdc.h
            ux_device_class_cdc_activate.c
            ux_device_class_cdc_control_complete.c
            ux_device_class_cdc_control_request.c
            ux_device_class_cdc_deactivate.c
            ux_device_class_cdc_entry.c
            ux_device_class_cdc_read.c
            ux_device_class_cdc_thread.c
            ux_device_class_cdc_write.c

            ux_hcd_sh2a.h                               Fixed ZLP and some scheduling bugs in the SH2 driver
            ux_hcd_sh2a_asynch_schedule.c
            ux_hcd_sh2a_request_bulk_transfer.c            
            
            
            ux_hcd_stm32.h                              Fixed several bugs in the STM32 driver
            ux_hcd_stm32_asynch_queue_process.c
            ux_hcd_stm32_entry.c
            ux_hcd_stm32_interrupt_handler.c
            ux_hcd_stm32_request_bulk_transfer.c
            ux_hcd_stm32_td_schedule.c

                                                        Added support for TILM device controller 
                                                        Files added:
            ux_dcd_tilm3.h
            ux_dcd_tilm3_address_set.c
            ux_dcd_tilm3_endpoint_create.c
            ux_dcd_tilm3_endpoint_destroy.c
            ux_dcd_tilm3_endpoint_reset.c
            ux_dcd_tilm3_endpoint_stall.c
            ux_dcd_tilm3_endpoint_status.c
            ux_dcd_tilm3_fifo_flush.c
            ux_dcd_tilm3_fifo_read.c
            ux_dcd_tilm3_fifo_write.c
            ux_dcd_tilm3_frame_number_get.c
            ux_dcd_tilm3_function.c
            ux_dcd_tilm3_initialize.c
            ux_dcd_tilm3_initialize_complete.c
            ux_dcd_tilm3_interrupt_handler.c
            ux_dcd_tilm3_register_clear.c
            ux_dcd_tilm3_register_read.c
            ux_dcd_tilm3_register_set.c
            ux_dcd_tilm3_register_write.c
            ux_dcd_tilm3_state_change.c
            ux_dcd_tilm3_transfer_callback.c
            ux_dcd_tilm3_transfer_request.c
                                         
                                                        Added support for TIAM180 device controller 
                                                        Files added:
                                         
            ux_dcd_ti18x.h
            ux_dcd_ti18x_address_set.c
            ux_dcd_ti18x_endpoint_create.c
            ux_dcd_ti18x_endpoint_destroy.c
            ux_dcd_ti18x_endpoint_reset.c
            ux_dcd_ti18x_endpoint_stall.c
            ux_dcd_ti18x_endpoint_status.c
            ux_dcd_ti18x_fifo_flush.c
            ux_dcd_ti18x_fifo_read.c
            ux_dcd_ti18x_fifo_write.c
            ux_dcd_ti18x_frame_number_get.c
            ux_dcd_ti18x_function.c
            ux_dcd_ti18x_initialize.c
            ux_dcd_ti18x_initialize_complete.c
            ux_dcd_ti18x_interrupt_handler.c
            ux_dcd_ti18x_register_clear.c
            ux_dcd_ti18x_register_read.c
            ux_dcd_ti18x_register_set.c
            ux_dcd_ti18x_register_write.c
            ux_dcd_ti18x_state_change.c
            ux_dcd_ti18x_transfer_callback.c
            ux_dcd_ti18x_transfer_request.c
                                                                   

                                                        Added support for the Sierra Wireless Airprime host class
                                                        Files added:
                                         
            ux_host_class_swar.h
            ux_host_class_swar_activate.c
            ux_host_class_swar_configure.c
            ux_host_class_swar_deactivate.c
            ux_host_class_swar_endpoints_get.c
            ux_host_class_swar_entry.c
            ux_host_class_swar_ioctl.c
            ux_host_class_swar_read.c
            ux_host_class_swar_reception_callback.c
            ux_host_class_swar_reception_start.c
            ux_host_class_swar_reception_stop.c
            ux_host_class_swar_write.c


11/16/2010  USBX generic code version 5.4. This release includes the following 
            modifications:

            ux_user.h                                   Added UX_DEVICE_CLASS_CDC_ECM_NX_PKPOOL_ENTRIES definition for CDC ECM class
            ux_device_class_cdc_ecm.h                   Allow for user.h configuration variable.
            ux_device_class_cdc_ecm_bulkin_thread.c     Corrected a flaw in Zero Length Packet condition for CDC/RNDIS classes.
            ux_device_class_rndis_bulkin_thread.c
            demo_usbx_stm32_dcd_cdc_ecm.c               Added an example for CDC ECM for STM32.
            ux_api.h                                    Added support for CDC-ECM TraceX values


            Added support for CDC ECM. The following files have been added:       

            ux_device_class_cdc_ecm.h
            ux_device_class_cdc_ecm_activate.c
            ux_device_class_cdc_ecm_bulkin_thread.c
            ux_device_class_cdc_ecm_bulkout_thread.c
            ux_device_class_cdc_ecm_change.c
            ux_device_class_cdc_ecm_control_request.c
            ux_device_class_cdc_ecm_deactivate.c
            ux_device_class_cdc_ecm_driver_entry.c
            ux_device_class_cdc_ecm_entry.c
            ux_device_class_cdc_ecm_initialize.c
            ux_device_class_cdc_ecm_interrupt_thread.c
            ux_device_class_cdc_ecm_write.c
            ux_device_class_cdc_entry.c
    
            Changed RNDIS to clean endpoints when shared in multiple configuration scenario.  The following files are modified:
            ux_device_class_rndis_interrupt_thread.c    
            ux_device_class_rndis_bulkin_thread.c       
            ux_device_class_rndis_bulkout_thread.c      
            ux_device_class_rndis_activate              

            ux_device_stack_interface_set.c             Fixed a problem with multiple interfaces. 
            ux_device_stack_configuration_set.c         Changed support for composite devices by forcing a IAD descriptor to group 
                                                        interfaces. 
            ux_device_stack_class_register.c            Class registration now needs the first interface number and configuration the  
                                                        interface is attached to inaddition to a IAD descriptor in the device framework.

            ux_device_stack_initialize.c                Fixed a problem with endpoint sharing when using mulitple configurations
            ux_device_stack_configuration_set.c         Fixed a problem with multiple configurations. 
            ux_device_stack_control_request_process.c   Changed the way multiple interfaces are owned by the same class.
            ux_system_initialize.c                      Added name for USB CDC ECM class and new host/device controller driver names.
            ux_host_stack_endpoint_instance_delete.c    Fixed a bug when a device resource are freed but the device was not associated
                                                        to a class.
            ux_host_stack_configuration_interface_get.c Fixed a bug when scanning for non 0/0 interface index.

            ux_host_controller_stm32                    Added support for the STM32 Host controler, the following files have beedn added:

                                                        ux_hcd_stm32.h
                                                        ux_hcd_stm32_asynchronous_endpoint_create.c
                                                        ux_hcd_stm32_asynchronous_endpoint_destroy.c
                                                        ux_hcd_stm32_asynch_queue_process.c
                                                        ux_hcd_stm32_asynch_schedule.c
                                                        ux_hcd_stm32_channel_halt.c
                                                        ux_hcd_stm32_controller_disable.c
                                                        ux_hcd_stm32_delay.c
                                                        ux_hcd_stm32_ed_obtain.c
                                                        ux_hcd_stm32_ed_td_clean.c
                                                        ux_hcd_stm32_endpoint_reset.c
                                                        ux_hcd_stm32_entry.c
                                                        ux_hcd_stm32_frame_number_get.c
                                                        ux_hcd_stm32_frame_number_set.c
                                                        ux_hcd_stm32_initialize.c
                                                        ux_hcd_stm32_interrupt_endpoint_create.c
                                                        ux_hcd_stm32_interrupt_handler.c
                                                        ux_hcd_stm32_isochronous_endpoint_create.c
                                                        ux_hcd_stm32_isochronous_td_obtain.c
                                                        ux_hcd_stm32_iso_queue_process.c
                                                        ux_hcd_stm32_iso_schedule.c
                                                        ux_hcd_stm32_least_traffic_list_get.c
                                                        ux_hcd_stm32_periodic_endpoint_destroy.c
                                                        ux_hcd_stm32_periodic_schedule.c
                                                        ux_hcd_stm32_periodic_tree_create.c
                                                        ux_hcd_stm32_port_disable.c
                                                        ux_hcd_stm32_port_enable.c
                                                        ux_hcd_stm32_port_reset.c
                                                        ux_hcd_stm32_port_resume.c
                                                        ux_hcd_stm32_port_status_get.c
                                                        ux_hcd_stm32_port_suspend.c
                                                        ux_hcd_stm32_power_down_port.c
                                                        ux_hcd_stm32_power_on_port.c
                                                        ux_hcd_stm32_register_clear.c
                                                        ux_hcd_stm32_register_read.c
                                                        ux_hcd_stm32_register_set.c
                                                        ux_hcd_stm32_register_write.c
                                                        ux_hcd_stm32_regular_td_obtain.c
                                                        ux_hcd_stm32_request_bulk_transfer.c
                                                        ux_hcd_stm32_request_control_transfer.c
                                                        ux_hcd_stm32_request_interupt_transfer.c
                                                        ux_hcd_stm32_request_isochronous_transfer.c
                                                        ux_hcd_stm32_request_transfer.c
                                                        ux_hcd_stm32_td_schedule.c
                                                        ux_hcd_stm32_transfer_abort.c

            ux_slave_controller_stm32                   Added support for the STM32 slave controler, the following files have beedn added:
                                                        ux_dcd_stm32.h
                                                        ux_dcd_stm32_address_set.c
                                                        ux_dcd_stm32_delay.c
                                                        ux_dcd_stm32_endpoint_create.c
                                                        ux_dcd_stm32_endpoint_destroy.c
                                                        ux_dcd_stm32_endpoint_register_address_get.c
                                                        ux_dcd_stm32_endpoint_reset.c
                                                        ux_dcd_stm32_endpoint_stall.c
                                                        ux_dcd_stm32_endpoint_status.c
                                                        ux_dcd_stm32_fifo_flush.c
                                                        ux_dcd_stm32_fifo_read.c
                                                        ux_dcd_stm32_fifo_write.c
                                                        ux_dcd_stm32_frame_number_get.c
                                                        ux_dcd_stm32_function.c
                                                        ux_dcd_stm32_initialize.c
                                                        ux_dcd_stm32_initialize_complete.c
                                                        ux_dcd_stm32_interrupt_handler.c
                                                        ux_dcd_stm32_register_clear.c
                                                        ux_dcd_stm32_register_read.c
                                                        ux_dcd_stm32_register_set.c
                                                        ux_dcd_stm32_register_write.c
                                                        ux_dcd_stm32_state_change.c
                                                        ux_dcd_stm32_transfer_callback.c
                                                        ux_dcd_stm32_transfer_request.c

            ux_slave_controller_sh2                     Added support for SH2 device controller, The following files have been added:
                                                        ux_dcd_sh2a.h
                                                        ux_dcd_sh2a_address_set.c
                                                        ux_dcd_sh2a_buffer_empty_interrupt.c
                                                        ux_dcd_sh2a_buffer_notready_interrupt.c
                                                        ux_dcd_sh2a_buffer_read.c
                                                        ux_dcd_sh2a_buffer_ready_interrupt.c
                                                        ux_dcd_sh2a_buffer_write.c
                                                        ux_dcd_sh2a_current_endpoint_change.c
                                                        ux_dcd_sh2a_data_buffer_size.c
                                                        ux_dcd_sh2a_endpoint_create.c
                                                        ux_dcd_sh2a_endpoint_destroy.c
                                                        ux_dcd_sh2a_endpoint_nak_set.c
                                                        ux_dcd_sh2a_endpoint_reset.c
                                                        ux_dcd_sh2a_endpoint_stall.c
                                                        ux_dcd_sh2a_endpoint_status.c
                                                        ux_dcd_sh2a_fifoc_write.c
                                                        ux_dcd_sh2a_fifod_write.c
                                                        ux_dcd_sh2a_fifo_port_change.c
                                                        ux_dcd_sh2a_fifo_read.c
                                                        ux_dcd_sh2a_frame_number_get.c
                                                        ux_dcd_sh2a_function.c
                                                        ux_dcd_sh2a_initialize.c
                                                        ux_dcd_sh2a_initialize_complete.c
                                                        ux_dcd_sh2a_interrupt_handler.c
                                                        ux_dcd_sh2a_register_clear.c
                                                        ux_dcd_sh2a_register_read.c
                                                        ux_dcd_sh2a_register_set.c
                                                        ux_dcd_sh2a_register_write.c
                                                        ux_dcd_sh2a_state_change.c
                                                        ux_dcd_sh2a_transfer_callback.c
                                                        ux_dcd_sh2a_transfer_request.c


            ux_slave_controller_lpc3131                 Added support for LPC3131 device controller, The following files have been added:
                                                        ux_dcd_lpc3131.h
                                                        ux_dcd_lpc3131_address_set.c
                                                        ux_dcd_lpc3131_endpoint_address_get.c
                                                        ux_dcd_lpc3131_endpoint_create.c
                                                        ux_dcd_lpc3131_endpoint_destroy.c
                                                        ux_dcd_lpc3131_endpoint_flush.c
                                                        ux_dcd_lpc3131_endpoint_reset.c
                                                        ux_dcd_lpc3131_endpoint_stall.c
                                                        ux_dcd_lpc3131_endpoint_stall_clear.c
                                                        ux_dcd_lpc3131_endpoint_status.c
                                                        ux_dcd_lpc3131_frame_number_get.c
                                                        ux_dcd_lpc3131_function.c
                                                        ux_dcd_lpc3131_initialize.c
                                                        ux_dcd_lpc3131_initialize_complete.c
                                                        ux_dcd_lpc3131_interrupt_handler.c
                                                        ux_dcd_lpc3131_interrupt_thread.c
                                                        ux_dcd_lpc3131_qtd_get.c
                                                        ux_dcd_lpc3131_register_clear.c
                                                        ux_dcd_lpc3131_register_read.c
                                                        ux_dcd_lpc3131_register_set.c
                                                        ux_dcd_lpc3131_register_write.c
                                                        ux_dcd_lpc3131_state_change.c
                                                        ux_dcd_lpc3131_status_phase_hook.c
                                                        ux_dcd_lpc3131_transfer_abort.c
                                                        ux_dcd_lpc3131_transfer_callback.c
                                                        ux_dcd_lpc3131_transfer_request.c

            ux_otg_controller_lpc3131                   Added OTG support for the LPC3131               
                                                        ux_otg_lpc3131.h
                                                        ux_otg_lpc3131_dcd_initialize.c
                                                        ux_otg_lpc3131_dcd_interrupt_handler.c
                                                        ux_otg_lpc3131_dcd_interrupt_thread.c
                                                        ux_otg_lpc3131_dcd_srp_start.c
                                                        ux_otg_lpc3131_dcd_stop.c
                                                        ux_otg_lpc3131_function.c
                                                        ux_otg_lpc3131_hcd_initialize.c
                                                        ux_otg_lpc3131_hcd_interrupt_handler.c
                                                        ux_otg_lpc3131_hcd_stop.c
                                                        ux_otg_lpc3131_initialize.c
                                                        ux_otg_lpc3131_interrupt_handler.c
                                                        ux_otg_lpc3131_thread_entry.c
                                                        ux_otg_lpc3131_vbus_manage.c


            ux_host_class_hid_idle_get                  Fixed a bug in IDLE command
            ux_host_class_hid_idle_set                  Fixed a bug in IDLE command
            ux_host_class_hid_report_get                Fixed a endianess issue with HID reports
            ux_host_class_hid_report_set                Fixed a endianess issue with HID reports

            ux_host_class_storage_endpoints_get         Fixed an issue with storage device with wrng endpoints assignement

            ux_hcd_ehci_initialize                      Fixed a bug with certain EHCI controllers, delayed the RUN.
            ux_hcd_ehci_port_status_get                 Allowed for EHCI controllers with embedded TT.

            ux_hcd_ehci_ed_clean.c                      Fixed a problem when Virtual/Physical memory translation was used.
        
            ux_hcd_ehci_initialize.c                    Added EHCI support for LPC3131 in lpc3131 directory
            ux_hcd_ehci_interrupt_handler.c             Fixed bug in awakening root hub driver.

07/10/2009  USBX generic code version 5.3. This release includes the following 
            modifications:

            ux_api.h                                    Changed to included new memory alignment values and TraceX events and objects,
                                                        and changed timeout value for control transfers from 1 second to 5 seconds
                                                        as some devices need a bit more time to reply to the first control request.
            ux_device_class_rndis.h                     Added a mutex to protect queuing/dequeing of packets between the application and the RNDIS xmit thread.
            ux_host_class_storage.h                     Ensure the SCSI CBW and CSW buffers are aligned on 32bit and do not rely on the compiler packing pragma
                                                        some DMA engines of certain OHCI controllers (SH7727 in particular) requires all OHCI data buffers
                                                        to be aligned on 32 bits even though OHCI does not demand it. 
            ux_dcd_at91_transfer_callback.c             Fixed missing update of actual_length field on out transmission, and added support for Control Out 
                                                        data payload in the Atmel AT91 controller.
            ux_dcd_at91_transfer_request.c              Fixed missing update of actual_length field on out transmission.
            ux_device_class_rndis_bulkin_thread.c       Added a mutex to protect queuing/dequeing of packets between the application and the RNDIS xmit thread, and
                                                        fixed problem when dequeing multiple NetX packets to be sent.
            ux_device_class_rndis_initialize.c          Added a mutex to protect queuing/dequeing of packets between the application and the RNDIS xmit thread.
            ux_device_class_rndis_write.c               Added a mutex to protect queuing/dequeing of packets between the application and the RNDIS xmit thread.
            ux_hcd_ehci_asynch_td_process.c             Update the ux_ehci_ed_first_td field with the next td to allow USB transactions of more than 16 spanning 
                                                        multiple SOFs, and only look for transfer errors if the Halt bit of the QTD is set.
            ux_hcd_ehci_interrupt_endpoint_create.c     Filter for interval 1 when we anchor on the last ed in the tree.
            ux_hcd_ehci_interrupt_endpoint_destroy.c    Check for the forward link of the QED and ensure it is not NUL before attaching the previous QED.
            ux_hcd_ehci_request_interrupt_transfer.c    Check for no QTD allocation.
            ux_hcd_ehci_transfer_abort.c                Fixed a bug when cleaning TDs after an abort.
            ux_hcd_isp1161_interrupt_endpoint_create.c  Filter for interval 1 when we anchor on the last ed in the tree.
            ux_hcd_ohci_interrupt_endpoint_create.c     Filter for interval 1 when we anchor on the last ed in the tree.
            ux_hcd_pic32_interrupt_endpoint_create.c    Filter for interval 1 when we anchor on the last ed in the tree.
            ux_hcd_sh2a_interrupt_endpoint_create.c     Filter for interval 1 when we anchor on the last ed in the tree.
            ux_host_stack_device_resources_free.c       Filter for no interface attached to a configuration before reading the current alternate setting, which 
                                                        would cause a crash in systems where reading from address 0 is illegal.
            ux_host_stack_endpoint_instance_delete.c    Filter for physical endpoint allocation when freeing device resources.                                                        
            ux_utility_memory_allocate.c                Allow safe alignment of DMA memory for controllers which do not support scatter/gather memory - the field 
                                                        UX_ENFORCE_SAFE_ALIGNMENT needs to be defined otherwise alignment defaults to the default.

            ux_hcd_isp1362                              Added support for the ISP1362 host controller, the following files have been added:

                                                            ux_hcd_isp1362.h                            
                                                            ux_hcd_isp1362_aitl_buffer_read.c
                                                            ux_hcd_isp1362_aitl_buffer_write.c
                                                            ux_hcd_isp1362_asynchronous_endpoint_create.c
                                                            ux_hcd_isp1362_asynchronous_endpoint_destroy.c
                                                            ux_hcd_isp1362_asynch_schedule.c
                                                            ux_hcd_isp1362_atl_queue_process.c
                                                            ux_hcd_isp1362_controller_disable.c
                                                            ux_hcd_isp1362_ed_obtain.c
                                                            ux_hcd_isp1362_ed_td_clean.c
                                                            ux_hcd_isp1362_endpoint_reset.c
                                                            ux_hcd_isp1362_entry.c
                                                            ux_hcd_isp1362_frame_number_get.c
                                                            ux_hcd_isp1362_frame_number_set.c
                                                            ux_hcd_isp1362_hcer_register_read.c
                                                            ux_hcd_isp1362_hcer_register_write.c
                                                            ux_hcd_isp1362_hcor_register_read.c
                                                            ux_hcd_isp1362_hcor_register_write.c
                                                            ux_hcd_isp1362_initialize.c
                                                            ux_hcd_isp1362_interrupt_endpoint_create.c
                                                            ux_hcd_isp1362_interrupt_endpoint_destroy.c
                                                            ux_hcd_isp1362_interrupt_handler.c
                                                            ux_hcd_isp1362_isochronous_endpoint_create.c
                                                            ux_hcd_isp1362_isochronous_endpoint_destroy.c
                                                            ux_hcd_isp1362_isochronous_td_obtain.c
                                                            ux_hcd_isp1362_iso_queue_process.c
                                                            ux_hcd_isp1362_iso_schedule.c
                                                            ux_hcd_isp1362_itl_queue_process.c
                                                            ux_hcd_isp1362_periodic_schedule.c
                                                            ux_hcd_isp1362_port_disable.c
                                                            ux_hcd_isp1362_port_enable.c
                                                            ux_hcd_isp1362_port_reset.c
                                                            ux_hcd_isp1362_port_resume.c
                                                            ux_hcd_isp1362_port_status_get.c
                                                            ux_hcd_isp1362_port_suspend.c
                                                            ux_hcd_isp1362_power_down_port.c
                                                            ux_hcd_isp1362_power_on_port.c
                                                            ux_hcd_isp1362_power_root_hubs.c
                                                            ux_hcd_isp1362_ptd_add.c
                                                            ux_hcd_isp1362_regular_td_obtain.c
                                                            ux_hcd_isp1362_request_bulk_transfer.c
                                                            ux_hcd_isp1362_request_control_transfer.c
                                                            ux_hcd_isp1362_request_interupt_transfer.c
                                                            ux_hcd_isp1362_request_isochronous_transfer.c
                                                            ux_hcd_isp1362_request_transfer.c
                                                            ux_hcd_isp1362_transfer_abort.c
                                                            
            mcf5445x                                    Added support for Coldfire MCF5445x with a special initialize file in the usbx\usbx_custom\mcf5445x directory
            ux_*.c                                      Modified comment(s) and added trace support.
            ux_*.h                                      Modified comment(s) and added trace support.
               
    
10/25/2008  USBX generic code version 5.2. This release includes the following 
            modifications:

            ux_host_class_storage_a\ctivate.c           Changed the mechanism for callback upon
            ux_host_class_prolific_activate.c           Device insertion/extraction.
            ux_host_class_pima_activate.c               Now, the class and the instance are passed
            ux_host_class_hub_activate.c                back to the application if the callback function
            ux_host_class_hid_activate.c                is registered.
            ux_host_class_cdc_acm_activate.c            All the files below have been modified:
            ux_host_class_audio_activate.c              "                 "                      "
            ux_host_class_asix_activate.c          
            ux_host_class_storage_deactivate.c          
            ux_host_class_prolific_deactivate.c          
            ux_host_class_pima_deactivate.c          
            ux_host_class_hub_deactivate.c          
            ux_host_class_hid_deactivate.c          
            ux_host_class_cdc_acm_deactivate.c          
            ux_host_class_audio_deactivate.c          
            ux_host_class_asix_deactivate.c          
            ux_host_stack_device_remove.c
            ux_host_stack_class_device_scan.c
            ux_host_stack_class_interface.c             "                 "                      "

            ux_host_class_hid_mouse_position_get.c      Added protection for instance verification
            ux_host_class_hid_mouse_buttons_get.c       "                 "                      "
            ux_host_class_hid_keyboard_key_get.c        "                 "                      "
            ux_host_class_hid_remote_control_usage_get.c"                 "                      "
            ux_host_class_hid_remote_control.h          "                 "                      "

            ux_device_stack_transfer_request.c          Ignore test for ENDPOINT_HALT if on a control endpoint
            ux_device_stack_control_request_process.c   Keep the Interface target command inside the device stack and do not forward to the class(es).
            
            ux_device_stack_configuration_get.c         Data payload now goes through the ux_device_stack_transfer_request function.
            ux_device_stack_get_status.c                Data payload now goes through the ux_device_stack_transfer_request function.
            ux_dcd_lpc3180_endpoint_stall_clear.c       Remove check for transfer pending when clearing the STALL condition.
            ux_dcd_lpc3180_endpoint_stall.c             Fixed a bug when setting STALL for non control endpoint.            
            ux_dcd_lpc3180_endpoint_transfer_callback.c Remove STALL flag for Control IN and Control OUT endpoints upon receiving a SETUP transaction
            ux_device_class_storage_thread.c            Check for exact CBW length and STALL Bulk In/Out endpoints if wrong length.
                                                        STALL Bulk In/Out endpoints if CBW header does not have the right signature.
            ux_device_class_storage_write.c             Modified to support media change
            ux_device_class_storage_format.c            Modified to support media change
            ux_device_class_storage_mode_select.c       Modified to support media change
            ux_device_class_storage_inquiry.c           Modified to support media change
            ux_device_class_storage_read.c              Modified to support media change
            ux_device_class_storage_request_sense.c     Modified to support media change
            ux_device_class_storage_test_ready.c        Modified to support media change
            ux_device_class_storage_read_capacity.c     Modified to support media change
            ux_device_class_storage_prevent_allow_media_removal.c               Modified to support media change
            ux_device_class_storage_mode_sense.c        Modified to support media change
            ux_device_class_storage_csw_send.c          Modified to support media change
            ux_device_class_storage.h                   Modified to support media change
            

            ux_host_class_storage_activate.c            Allocate the storage instance from CACHE_SAFE memory to ensure the SCSI
                                                        CSW buffer is in a cache safe memory region.
                                                                    
            ux_api.h                                    Removed class structures back into their own specific .h files
                                                        to improve readability, all host classes .h files have also been modified
                                                        accordingly.
            ux_user.h                                   Added several configurable parameters for memory constraint environment like PIC32
            us_port.h                                   Like above, also changed the USBX thread priorities to 1 for HCD and DCD and 2 for 
                                                        the enumeration thread and other classes. Changed the string UX_SYSTEM_HOST_INIT to UX_SYSTEM_INIT
            ux_system_initialize.c                      Changed the string UX_SYSTEM_HOST_INIT to UX_SYSTEM_INIT
            ux_host_class_hub_activate                  Change the hub instance state to activated before starting the interrupt pipe.
            ux_hcd_ehci_asynch_td_process.c             Properly release the last TD when an error occur during the transfer
            ux_hcd_ehci_done_queue_process.c            Discovered a bug when parsing the interrupt tree in search for the range of frame
                                                        entries to scan. The algorithm is now simpler and all the entries are parsed.
            ux_hcd_isp1161_least_traffic_list_get.c     When looking for the list with least traffic, ignore the static EDs.
            ux_hcd_ohci_initialize.c                    Force the periodic start default value of the HC_PERIODIC_START register.
                                                        Some OHCI controllers needs this register to be set manually, others default
                                                        to some value upon reset.
            ux_hcd_ehci_asynchronous_endpoint_create.c  Bug found when setting the cap0 register of the ED. If the endpoint is a control endpoint,
                                                        the QH-CEF bit must be set.         
            ux_hcd_sh2a                                 Added support for variants of the SH2A USB host controller (SH7670 and SH7263)
                                                        Files added: 
                                                            ux_hcd_sh2a.h
                                                            ux_hcd_sh2a_asynchronous_endpoint_create.c
                                                            ux_hcd_sh2a_asynchronous_endpoint_destroy.c
                                                            ux_hcd_sh2a_asynch_queue_process.c
                                                            ux_hcd_sh2a_asynch_queue_process_bemp.c
                                                            ux_hcd_sh2a_asynch_queue_process_brdy.c
                                                            ux_hcd_sh2a_asynch_queue_process_nrdy.c
                                                            ux_hcd_sh2a_asynch_queue_process_sign.c
                                                            ux_hcd_sh2a_asynch_schedule.c
                                                            ux_hcd_sh2a_buffer_empty_interrupt.c
                                                            ux_hcd_sh2a_buffer_notready_interrupt.c
                                                            ux_hcd_sh2a_buffer_read.c
                                                            ux_hcd_sh2a_buffer_ready_interrupt.c
                                                            ux_hcd_sh2a_buffer_write.c
                                                            ux_hcd_sh2a_bulk_endpoint_create.c
                                                            ux_hcd_sh2a_bulk_int_td_add.c
                                                            ux_hcd_sh2a_controller_disable.c
                                                            ux_hcd_sh2a_control_endpoint_create.c
                                                            ux_hcd_sh2a_control_td_add.c
                                                            ux_hcd_sh2a_current_endpoint_change.c
                                                            ux_hcd_sh2a_data_buffer_size.c
                                                            ux_hcd_sh2a_ed_obtain.c
                                                            ux_hcd_sh2a_ed_td_clean.c
                                                            ux_hcd_sh2a_endpoint_nak_set.c
                                                            ux_hcd_sh2a_endpoint_reset.c
                                                            ux_hcd_sh2a_entry.c
                                                            ux_hcd_sh2a_fifoc_write.c
                                                            ux_hcd_sh2a_fifod_write.c
                                                            ux_hcd_sh2a_fifo_port_change.c
                                                            ux_hcd_sh2a_fifo_read.c
                                                            ux_hcd_sh2a_fifo_size_get.c
                                                            ux_hcd_sh2a_frame_number_get.c
                                                            ux_hcd_sh2a_frame_number_set.c
                                                            ux_hcd_sh2a_initialize.c
                                                            ux_hcd_sh2a_interrupt_endpoint_create.c
                                                            ux_hcd_sh2a_interrupt_handler.c
                                                            ux_hcd_sh2a_isochronous_endpoint_create.c
                                                            ux_hcd_sh2a_isochronous_td_obtain.c
                                                            ux_hcd_sh2a_iso_queue_process.c
                                                            ux_hcd_sh2a_iso_schedule.c
                                                            ux_hcd_sh2a_least_traffic_list_get.c
                                                            ux_hcd_sh2a_periodic_endpoint_destroy.c
                                                            ux_hcd_sh2a_periodic_schedule.c
                                                            ux_hcd_sh2a_periodic_tree_create.c
                                                            ux_hcd_sh2a_port_disable.c
                                                            ux_hcd_sh2a_port_enable.c
                                                            ux_hcd_sh2a_port_reset.c
                                                            ux_hcd_sh2a_port_resume.c
                                                            ux_hcd_sh2a_port_status_get.c
                                                            ux_hcd_sh2a_port_suspend.c
                                                            ux_hcd_sh2a_power_down_port.c
                                                            ux_hcd_sh2a_power_on_port.c
                                                            ux_hcd_sh2a_power_root_hubs.c
                                                            ux_hcd_sh2a_register_clear.c
                                                            ux_hcd_sh2a_register_read.c
                                                            ux_hcd_sh2a_register_set.c
                                                            ux_hcd_sh2a_register_write.c
                                                            ux_hcd_sh2a_regular_td_obtain.c
                                                            ux_hcd_sh2a_request_bulk_transfer.c
                                                            ux_hcd_sh2a_request_control_transfer.c
                                                            ux_hcd_sh2a_request_interupt_transfer.c
                                                            ux_hcd_sh2a_request_isochronous_transfer.c
                                                            ux_hcd_sh2a_request_transfer.c
                                                            ux_hcd_sh2a_td_add.c
                                                            ux_hcd_sh2a_transfer_abort.c

            ux_hcd_pic32                                Added support for the PIC32 host controller
                                                        Files added: 
                                                            ux_hcd_pic32.h
                                                            ux_hcd_pic32_asynchronous_endpoint_create.c
                                                            ux_hcd_pic32_asynchronous_endpoint_destroy.c
                                                            ux_hcd_pic32_asynch_queue_process.c
                                                            ux_hcd_pic32_asynch_schedule.c
                                                            ux_hcd_pic32_bus_error_process.c
                                                            ux_hcd_pic32_controller_disable.c
                                                            ux_hcd_pic32_ed_obtain.c
                                                            ux_hcd_pic32_ed_td_clean.c
                                                            ux_hcd_pic32_endpoint_reset.c
                                                            ux_hcd_pic32_entry.c
                                                            ux_hcd_pic32_frame_number_get.c
                                                            ux_hcd_pic32_frame_number_set.c
                                                            ux_hcd_pic32_initialize.c
                                                            ux_hcd_pic32_interrupt_endpoint_create.c
                                                            ux_hcd_pic32_interrupt_handler.c
                                                            ux_hcd_pic32_isochronous_endpoint_create.c
                                                            ux_hcd_pic32_isochronous_td_obtain.c
                                                            ux_hcd_pic32_iso_queue_process.c
                                                            ux_hcd_pic32_iso_schedule.c
                                                            ux_hcd_pic32_least_traffic_list_get.c
                                                            ux_hcd_pic32_periodic_endpoint_destroy.c
                                                            ux_hcd_pic32_periodic_schedule.c
                                                            ux_hcd_pic32_periodic_tree_create.c
                                                            ux_hcd_pic32_port_disable.c
                                                            ux_hcd_pic32_port_enable.c
                                                            ux_hcd_pic32_port_reset.c
                                                            ux_hcd_pic32_port_resume.c
                                                            ux_hcd_pic32_port_status_get.c
                                                            ux_hcd_pic32_port_suspend.c
                                                            ux_hcd_pic32_power_down_port.c
                                                            ux_hcd_pic32_power_on_port.c
                                                            ux_hcd_pic32_register_clear.c
                                                            ux_hcd_pic32_register_read.c
                                                            ux_hcd_pic32_register_set.c
                                                            ux_hcd_pic32_register_write.c
                                                            ux_hcd_pic32_regular_td_obtain.c
                                                            ux_hcd_pic32_request_bulk_transfer.c
                                                            ux_hcd_pic32_request_control_transfer.c
                                                            ux_hcd_pic32_request_interupt_transfer.c
                                                            ux_hcd_pic32_request_isochronous_transfer.c
                                                            ux_hcd_pic32_request_transfer.c
                                                            ux_hcd_pic32_td_schedule.c
                                                            ux_hcd_pic32_transfer_abort.c
                
            ux_device_class_rndis                       Added support for RNDIS                                                                         
                                                        Files added: 
                                                            ux_device_class_rndis.h
                                                            ux_device_class_rndis_activate.c
                                                            ux_device_class_rndis_bulkin_thread.c
                                                            ux_device_class_rndis_bulkout_thread.c
                                                            ux_device_class_rndis_bulkxx_thread.c
                                                            ux_device_class_rndis_control_request.c
                                                            ux_device_class_rndis_deactivate.c
                                                            ux_device_class_rndis_driver_entry.c
                                                            ux_device_class_rndis_entry.c
                                                            ux_device_class_rndis_initialize.c
                                                            ux_device_class_rndis_interrupt_thread.c
                                                            ux_device_class_rndis_msg_initialize.c
                                                            ux_device_class_rndis_msg_keep_alive.c
                                                            ux_device_class_rndis_msg_query.c
                                                            ux_device_class_rndis_msg_reset.c
                                                            ux_device_class_rndis_msg_set.c
                                                            ux_device_class_rndis_write.c
            
            ux_device_stack_initialize.c                Change the endpoint payload memory to use CACHE_SAFE memory.
            ux_utility_short_get.c                      Change the return type to ULONG
            ux_utility_short_get_big_endian.c           Like above.
            ux_device_stack_interface_start.c           Changed the calling parameter structure to the device classes by setting the interface value
                                                        and not the instance with the device interface.
                                                        This changed all the device class activate and deactivate functions
            ux_pictbridge_element_to_decimal.c          Found a bug in XML object decimal conversion    
            
            ux_custom\sh7727                            Addition of the OHCI modified files for SH7727 OHCI limitations.                                                    
                                                         
            udemo_usbx_lpc2468_dcd_rndis.c              Example for RNDIS driver on LPC2468
            demo_usbx_sh2a_7263.c                       SH7263 host example
            demo_usbx_pic32_host_storage_printer.c      PIC32 storage and printer behind hub example
            demo_usbx_pic32_host_keyboard.c             PIC32 low speed example
            demo_usbx_pic32_host_storage.c              PIC32 storage example
                                                                

07/04/2008  USBX generic code version 5.1. This release includes the following 
            modifications:
        
            ux_api.h                                    Added constants, updated typedefs, and updated prototypes.
            ux_dcd_sim_slave_endpoint_create.c          Added logic to check for endpoint 0 and if found, make it ready 
                                                        for transactions.
            ux_dcd_sim_slave_transfer_request.c         Added code to set the ED to transfer status.
            ux_device_class_*_activate.c                Changed the registration and initialization of device classes.
            ux_device_class_*_initialize.c              Changed the registration and initialization of device classes.
            ux_device_class_cdc.h                       Updated CDC parameter typedef, removed unused function prototypes,
                                                        and added new function prototypes.
            ux_device_class_cdc_activate.c              Added logic to call application's activate function if present.
            ux_device_class_cdc_deactivate.c            Added logic to call application's deactivate function if present.
            ux_device_class_cdc_control_request.c       Removed setup of complete function callback.
            ux_device_class_dpump.h                     Added data pump class structure, and added read/write APIs.
            ux_device_class_dpump_activate.c            Added logic to call application's activate function if present.
            ux_device_class_dpump_deactivate.c          Added logic to call application's deactivate function if present.
            ux_device_class_storage.h                   Added new read capacity response constants.
            ux_device_class_storage_inquiry.c           Changed setting for data format bit.
            ux_device_class_storage_mode_sense.c        Replaced sending inquiry response with read capacity response buffer.
            ux_device_class_storage_read_format_capacity.c        
                                                        Replaced sending inquiry response with read capacity response buffer.
            ux_device_stack_class_register.c            Changed the registration and initialization of device classes
                                                        and fixed a memory resource release problem.
            ux_device_stack_control_request_process.c   Removed the verification for length in control_request_process 
                                                        due to a new mechanism to allow control request with OUT data 
                                                        payload.
            ux_device_stack_disconnect.c                Changed the registration and initialization of device classes.
            ux_hcd_ehci_interrupt_endpoint_create.c     Changed frequency check and changed the value of NAK counter in EHCI 
                                                        interrupt endpoints.
            ux_hcd_ehci_interrupt_handler.c             Changed the mechanism to report root hub port changes. There is 
                                                        now a bit per root hub port to indicate device insertion/extraction.
            ux_hcd_isp1161_asynch_schedule.c            Added check for NULL pointer in the scheduling loop.
            ux_hcd_isp1161_asynchronous_endpoint_destroy.c
                                                        Added logic to update the current ED if current ED is the one being 
                                                        destroyed.
            ux_hcd_isp1161_interrupt_handler.c          Changed the mechanism to report root hub port changes. There is 
                                                        now a bit per root hub port to indicate device insertion/extraction.
            ux_hcd_ohci_done_queue_process.c            Fixed a problem in OHCI when a buffer underrun is detected with a 
                                                        callback OHCI TD error bit needs to be reset before callback.
            ux_hcd_ohci_interrupt_handler.c             Changed the mechanism to report root hub port changes. There is 
                                                        now a bit per root hub port to indicate device insertion/extraction.
            ux_hcd_ohci_request_bulk_transfer.c         Fixed a problem with zero length packet in the OHCI driver.
            ux_hcd_sim_host_asynch_schedule.c           Added check for NULL pointer in the scheduling loop.
            ux_hcd_sim_host_asynchronous_endpoint_destroy.c
                                                        Added logic to update the current ED if current ED is the one being 
                                                        destroyed.
            ux_hcd_sim_host_transaction_schedule.c      Corrected several ED problems.
            ux_host_class_hub_deactivate.c              Fixed a problem when the hub class gets deactivated - deleted the 
                                                        semaphore properly.
            ux_host_class_*_deactivate.c                Changed the deactivation process of each host classes to ensure all 
                                                        pending transactions are terminated before cleaning the class.
            ux_host_stack_class_device_scan.c           Fixed a problem with custom classes which trigger on PID/VID.
            ux_host_stack_device_remove.c               Fixed a problem with custom classes which trigger on PID/VID.
            ux_host_stack_rh_change_process.c           Changed the mechanism to report root hub port changes. There is 
                                                        now a bit per root hub port to indicate device insertion/extraction.
            ux_host_stack_rh_device_insertion.c         Changed the mechanism to report root hub port changes. There is 
                                                        now a bit per root hub port to indicate device insertion/extraction.
            ux_host_stack_transfer_request.c            Added the UX_TRANSFER_STATUS_PENDING flag to transfer request status 
                                                        when a urb is scheduled. This allows each class to ensure no urbs are 
                                                        pending when shutting down.
            ux_utility.h                                Added new function prototypes.  
            ux_dcd_bf52*.*                              Added support for Blackfin USB device controller.
            ux_dcd_lpc3180*.*                           Added support for LPC3180 USB device controller.
            ux_dcd_sh7705*.*                            Added support for SH7705 USB device controller.
            ux_device_class_initialize.c                Added cdc initialize function.
            ux_device_class_cdc_read.c                  Added cdc read function.
            ux_device_class_cdc_write.c                 Added cdc write function.
            ux_device_class_dpump_initialize.c          Added dpump initialize function.
            ux_device_class_dpump_read.c                Added dpump read function.
            ux_device_class_dpump_write.c               Added dpump write function.
            ux_device_class_hid*.*                      Added support for HID device class.
            ux_device_class_pima*.*                     Added support for PIMA device class.
            ux_host_class_asix*.*                       Added support for Asix host class.
            ux_host_class_cdc*.*                        Added support for CDC host class.
            ux_host_class_pima*.*                       Added support for Pima host class.
            ux_host_class_prolific*.*                   Added support for Prolific host class.
            ux_pictbridge*.*                            Added Pictbridge support.
            ux_user.h                                   Added user conditional define file.  
            ux_utility_descriptor_pack.c                Added utility to pack descriptor.
            ux_utility_event_flags_create.c             Added utility to create event flags.
            ux_utility_event_flags_delete.c             Added utility to delete event flags.
            ux_utility_event_flags_get.c                Added utility to get event flags.
            ux_utility_event_flags_set.c                Added utility to set event flags.
            ux_utility_string_to_unicode.c              Added function for unicode encoding/decoding.
            ux_utility_unicode_to_string.c              Added function for unicode encoding/decoding.
            ux_*.c                                      Modified comment(s).
            ux_*.h                                      Modified comment(s).


07/01/2007  Initial USBX generic code version 5.0. 


Copyright(c) 1996-2017 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com

