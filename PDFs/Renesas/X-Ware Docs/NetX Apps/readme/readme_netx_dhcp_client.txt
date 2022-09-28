Revision History for NetX DHCP Client

Release 5.11  07-15-2018

            demo_netx_dhcp.c                        Corrected the host name.
            
            nx_dhcp.c                               Returned the option value as host byte order.
                                                      Function is modified:
                                                      _nx_dhcp_interface_user_option_retrieve()

                                                    Fixed compiler errors when event trace is enabled.
                                                      Function is modified:
                                                      _nx_dhcp_client_send_with_zero_source_address()

                                                    Added a check for invalid characters in the host name.
                                                      Function is modified:
                                                      _nx_dhcp_create()

                                                    Improved packet length verification.
                                                      Function is modified:
                                                      _nx_dhcp_packet_process()

                                                    Improved internal logic.
                                                      Function is modified:
                                                      _nx_dhcp_client_checksum_compute()

                                                    Supported for adding user supplied options.
                                                      Functions are added or modified:
                                                      _nx_dhcp_send_request_internal()
                                                      _nx_dhcp_user_option_add_callback_set()
                                                      _nxe_dhcp_user_option_add_callback_set()

                                                    Fixed a bug that mutex is not released before return.
                                                      Function is modified:
                                                      _nx_dhcp_client_send_with_zero_source_address()

            nx_dhcp.h                               Added a status for invalid characters in the host name.

                                                    Supported for adding user supplied options.

                                                    Updated the default value of NX_DHCP_CLIENT_MAX_RECORDS.

Release 5.10  05-10-2016

             nx_dhcp.c                              Optimized the logic for detecting address conflict.
                                                      Functions are modified or added: 
                                                      _nx_dhcp_client_send_arp_probe()
                                                      _nx_dhcp_create()
                                                      _nx_dhcp_delete()
                                                      _nx_dhcp_ip_conflict()
                                                      _nx_dhcp_process()

                                                    Corrected the logic for setting the broadcast bit.
                                                      The following functions are modified:
                                                      _nx_dhcp_send_request_internal()

                                                    Corrected the logic for setting the target IP address.
                                                      The following functions are modified:
                                                      _nx_dhcp_send_request_internal()

                                                    Modified the logic for processing DHCP options.
                                                      The following functions are modified:
                                                      _nx_dhcp_extract_information()
                                                      _nx_dhcp_user_option_retrieve()
                                                      _nx_dhcp_get_option_value()
                                                      _nx_dhcp_search_buffer()

                                                    Added support for DHCP on multiple interfaces.
                                                      The following API are modified or added: 
                                                      _nx_dhcp_create()
                                                      _nx_dhcp_clear_broadcast_flag()
                                                      _nx_dhcp_client_send_with_zero_source_address()
                                                      _nx_dhcp_delete()
                                                      _nx_dhcp_decline()
                                                      _nx_dhcp_extract_information()
                                                      _nx_dhcp_force_renew()
                                                      _nx_dhcp_packet_process()
                                                      _nx_dhcp_reinitialize()
                                                      _nx_dhcp_release()
                                                      _nx_dhcp_request_client_ip()
                                                      _nx_dhcp_resume()
                                                      _nx_dhcp_suspend()     
                                                      _nx_dhcp_send_request()
                                                      _nx_dhcp_send_request_internal()
                                                      _nx_dhcp_server_address_get()
                                                      _nx_dhcp_set_interface_index()
                                                      _nx_dhcp_start()
                                                      _nx_dhcp_stop()
                                                      _nx_dhcp_thread_entry()
                                                      _nx_dhcp_timeout_entry()
                                                      _nx_dhcp_timeout_process()
                                                      _nx_dhcp_udp_receive_notify()
                                                      _nx_dhcp_user_option_retrieve()  
                                                      _nx_dhcp_client_get_record()
                                                      _nx_dhcp_client_restore_record()
                                                      _nx_dhcp_client_update_time_remaining()
                                                      _nx_dhcp_client_interface_get_record()
                                                      _nx_dhcp_client_interface_restore_record()
                                                      _nx_dhcp_client_interface_update_time_remaining()
                                                      _nx_dhcp_interface_clear_broadcast_flag()
                                                      _nx_dhcp_interface_enable()
                                                      _nx_dhcp_interface_disable()
                                                      _nx_dhcp_interface_decline()
                                                      _nx_dhcp_interface_force_renew()
                                                      _nx_dhcp_interface_reinitialize()
                                                      _nx_dhcp_interface_release()
                                                      _nx_dhcp_interface_request_client_ip()
                                                      _nx_dhcp_interface_start()
                                                      _nx_dhcp_interface_stop()
                                                      _nx_dhcp_interface_send_request()
                                                      _nx_dhcp_interface_server_address_get()
                                                      _nx_dhcp_interface_state_change_notify()
                                                      _nx_dhcp_interface_user_option_retrieve()
                                                      _nx_dhcp_interface_record_find()
                                                      _nxe_dhcp_interface_clear_broadcast_flag() 
                                                      _nxe_dhcp_interface_reinitialize()       
                                                      _nxe_dhcp_interface_request_client_ip()
                                                      _nxe_dhcp_interface_force_renew()  
                                                      _nxe_dhcp_interface_decline()   
                                                      _nxe_dhcp_interface_release()
                                                      _nxe_dhcp_interface_start()
                                                      _nxe_dhcp_interface_stop()      
                                                      _nxe_dhcp_interface_enable()
                                                      _nxe_dhcp_interface_disable()
                                                      _nxe_dhcp_interface_state_change_notify()
                                                      _nxe_dhcp_interface_user_option_retrieve()
                                                      _nxe_dhcp_interface_send_request()
                                                      _nxe_dhcp_interface_server_address_get() 
                                                      _nxe_dhcp_client_interface_get_record()         
                                                      _nxe_dhcp_client_interface_restore_record() 
                                                      _nxe_dhcp_client_interface_update_time_remaining() 

                                                    Modified the logic for updating DHCP timeout. 
                                                     The following functions are modified:
                                                      _nx_dhcp_update_timeout() 
                                                      _nx_dhcp_packet_process()
                                                      _nx_dhcp_timeout_entry()
                                                      _nx_dhcp_interface_record_find()
                                                      _nx_dhcp_ip_conflict()
                                                      _nx_dhcp_thread_entry()

             nx_dhcp.h                              Fixed compiler warnings.

                                                    Modified the logic for processing DHCP options.

                                                    Added support for DHCP on multiple interfaces.


Release 5.9   02-22-2016

             demo_netx_dhcp.c                       Unified ticks per second. 

                                                    Simplified the demo.

                                                    Fixed compiler warnings.

             nx_dhcp.c                              Unified ticks per second.

                                                    Added support for sending maximum DHCP message size option.

                                                    Changed the logic to check the DHCP state to update the time remaining in renew and rebind states.

                                                    Optimized the algorithm for calculating random time.

                                                    Corrected the logic for sending ARP probe and restarting configuration.

                                                    Fixed compiler warnings.

                                                    Set the source address field in the IP header to 0 for DHCP messages that client obtaining its IP address.

             nx_dhcp.h                              Unified ticks per second.

                                                    Added support for sending maximum DHCP message size option.

                                                    Added symbol names for sending ARP probe and restarting configuration.

                                                    Fixed compiler warnings.

01-12-2015  Initial DHCP Client generic code version 5.8.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com
