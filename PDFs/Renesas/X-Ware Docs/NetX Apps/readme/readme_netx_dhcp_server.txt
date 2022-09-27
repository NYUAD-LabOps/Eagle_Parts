Revision History for NetX DHCP Server

Release 5.11  07-15-2018

            nx_dhcp_server.c                        Fixed an error checking for interface index in _nx_dhcp_create_server_ip_address_list().

                                                    Removed #if 0 code for feature never implemented in
                                                      _nx_dhcp_server_extract_information().

                                                    Improved internal logic.

                                                    Fixed a compiler warning.

            nx_dhcp_server.h                        Removed unused symbol:NX_DHCP_CLIENT_IDENTIFIER_MAX.


Release 5.10  05-10-2016

            nx_dhcp_server.c                        Added flag events to process packet receive event, fast periodic event and slow periodic event.
                                                      Functions are modified or renamed: 
                                                      _nx_dhcp_server_create()
                                                      _nx_dhcp_server_delete()
                                                      _nx_dhcp_fast_periodic_timer_entry()
                                                      _nx_dhcp_slow_periodic_timer_entry()
                                                      _nx_dhcp_server_thread_entry()
                                                      _nx_dhcp_listen_for_messages()
                                                      _nx_dhcp_server_packet_process()

                                                    Fixed packet leaks in _nx_dhcp_respond_to_client_message().

                                                    Added mutex protection.
                                                      Functions are modified: 
                                                      _nx_dhcp_create_server_ip_address_list()
                                                      _nx_dhcp_set_interface_network_parameters()
                                                      _nx_dhcp_clear_client_record()

            nx_dhcp_server.h                        Added flag events to process packet receive event, fast periodic event and slow periodic event.
 

Release 5.9   02-22-2016

            demo_netx_dhcp.c                        Unified ticks per second. 

                                                    Simplified the demo.

                                                    Fixed compiler warnings.

            nx_dhcp_server.c                        Unified ticks per second in nx_dhcp_server_create().
 
                                                    Optimized process logic in nx_dhcp_server_thread_entry().
 
                                                    Fixed packet leak in nx_dhcp_listen_for_message().

                                                    Fixed the bug for user options seek in nx_dhcp_server_extract_information.

                                                    Initialized dhcp client in nx_dhcp_listen_for_message.
                                                    
                                                    Copied the incoming data in one packet from dhcp server pool in nx_dhcp_listen_for_messages.
                                                    
                                                    Fixed a bug in nx_dhcp_server_extract_information to initialize the dhcp_client_ptr to NULL in the event
                                                    the function encounters an invalid packet. Previously, the function returned a garbage dhcp_client_ptr to 
                                                    the caller which would then dereference it and get an exception.
                                                    
                                                    Send NACK message if the client's requested IP address is incorrect in _nx_dhcp_validate_client_message.
                                                    
                                                    Simplified the logic to find, record and clear the IP address owner.

                                                    Fixed compiler warnings.

            nx_dhcp_server.h                        Unified ticks per second.
                                                     
                                                    Adjusted the default value of configuration options.
                                                    
                                                    Optimized the structure.

01-12-2015  Initial DHCP Server generic code version 5.8.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com
