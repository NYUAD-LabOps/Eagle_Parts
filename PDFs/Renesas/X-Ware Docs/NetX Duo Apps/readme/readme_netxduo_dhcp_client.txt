Revision History for NetX Duo DHCP (IPv4) Client

Release 5.11  07-15-2018

            demo_netxduo_dhcp.c                     Corrected the host name.

            nxd_dhcp_client.c                       Returned the option value as host byte order.
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

                                                    Supported for adding user supplied options.
                                                      Functions are added or modified:
                                                      _nx_dhcp_send_request_internal()
                                                      _nx_dhcp_user_option_add_callback_set()
                                                      _nxe_dhcp_user_option_add_callback_set()

                                                    Fixed a bug that mutex is not released before return.
                                                      Function is modified:
                                                      _nx_dhcp_client_send_with_zero_source_address()

            nxd_dhcp_client.h                       Added a status for invalid characters in the host name.

                                                    Supported for adding user supplied options.

                                                    Updated the default value of NX_DHCP_CLIENT_MAX_RECORDS.

Release 5.10  05-10-2016

            nxd_dhcp_client.c                       Optimized the logic for detecting address conflict.
                                                      The following functions are modified or added: 
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
                                                      _nxe_dhcp_interface_enable()
                                                      _nxe_dhcp_interface_disable()
                                                      _nxe_dhcp_interface_decline()  
                                                      _nxe_dhcp_interface_force_renew()    
                                                      _nxe_dhcp_interface_reinitialize() 
                                                      _nxe_dhcp_interface_release()      
                                                      _nxe_dhcp_interface_request_client_ip()
                                                      _nxe_dhcp_interface_start()
                                                      _nxe_dhcp_interface_stop()   
                                                      _nxe_dhcp_interface_send_request()
                                                      _nxe_dhcp_interface_server_address_get() 
                                                      _nxe_dhcp_interface_state_change_notify()
                                                      _nxe_dhcp_interface_user_option_retrieve()
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

            nxd_dhcp_client.h                       Fixed compiler warnings.

                                                    Modified the logic for processing DHCP options.

                                                    Added support for DHCP on multiple interfaces.

Release 5.9   02-22-2016

            demo_netxduo_dhcp.c                     Unified ticks per second.

                                                    Simplified the demo.

                                                    Fixed compiler warnings.

            nxd_dhcp_client.c                       Unified ticks per second.

                                                    Added support for sending maximum DHCP message size option.

                                                    Changed the logic to check the DHCP state to update the time remaining in renew and rebind states.

                                                    Optimized the algorithm for calculating random time.

                                                    Corrected the logic for sending ARP probe and restarting configuration.

                                                    Fixed compiler warnings.

                                                    Set the source address field in the IP header to 0 for DHCP messages that client obtaining its IP address.

            nxd_dhcp_client.h                       Unified ticks per second.

                                                    Added support for sending maximum DHCP message size option.

                                                    Added symbol names for sending ARP probe and restarting configuration.

                                                    Fixed compiler warnings.


Release 5.8   01-12-2015

        
            nxd_dhcp_client.c                       Removed MULTI_HOME_NETXDUO/MULTI_HOME_NETX macro definition.

                                                    Fixed a bug in nx_dhcp_search_buffer() that could potentially casue buffer overflow

                                                    Fixed a packet leak in nx_dhcp_process() in the REQUEST state. 

                                                    Replaced rand() with NetX Duo macro NX_RAND

                                                    Updated nx_dhcp_process and nx_dhcp_send_request_internal for updating the 'secs' field 
                                                        in the DHCP client header for those DHCP servers that expect this field to be updated. 

                                                    Fixed a bug in nx_dhcp_add_randomize that could potentially cause a huge random delay factor

                                                    Added nx_dhcp_clear_broadcast_flag service for cases where the DHCP server is behind
                                                        a router and the server must be able to send unicast messages.

                                                    Added nx_dhcp_seconds to the DHCP Client structure for filling in the 'secs' field in 
                                                        the DHCP header.

                                                    Modified calls for allocating packets so that NetX Duo DHCP CLient will also compile and run
                                                        in a NetX environment. 
                                                        
                                                    Modified nx_dhcp_process for DHCP CLient to update the IP router and IP address from ACKs received
                                                        from the server in the RENEW and REBIND state. 

                                                    Modified the clear gateway address call function to match NetX Duo 5.8 

                                                    Remove the nx_packet_data_extract_offset function since nx_packet_data_extract_offset function
                                                        is defined in NetX/NetXDuo 5.8

                                                    Fixed the bug of DHCPv4 Client option added operation: added Server identifier option in DHCP Decline and Release messages, 
                                                        removed Host name option in DHCP Decline and Release messages.

                                                    Remove the internal function from nxd_dhcp_client.h into nxd_dhcp_client.c.

                                                    _nx_dhcp_client_send_arp_probe modified to check if an arp entry with matching IP address 
                                                    does not have a non-zero MAC address.

                                                    Modified the logic to get DHCP option value to avoid using the released packet in _nx_dhcp_user_option_retrieve.

                                                    Processed the DNS and NTP server options in _nx_dhcp_extract_information.

            nxd_dhcp_client.h                       Modified definition of NX_DHCP_PACKET_PAYLOAD so that NetX Duo DHCP CLient will also compile and run
                                                        in a NetX environment.  
                                                        
                                                    Added nx_dhcp_seconds to the DHCP CLIENT struct.

                                                    Added nx_dhcp_clear_broadcast_flag service for cases where the DHCP server is behind
                                                        a router and the server must be able to send unicast messages.

                                                    Added variables to store DNS and NTP server addresses.  


Release 5.4   01-31-2013

        
            nxd_dhcp_client.c                       
                                                    Added logic to clear non specific DHCP broadcast packets from the DHCP Client
                                                    receive queue in nx_dhcp_thread_entry() and nx_dhcp_get_response(). This is enabled by
                                                    defining the NX_DHCP_CLIENT_CLEAR_QUEUE option in nx_dhcp.h. 

                                                    Made corrections to nx_dhcp_process for more accurate handling of retransmission
                                                    intervals in both the process of reaching the BOUND state and in the RENEW and REBIND
                                                    states.

                                                    Simplified the logic for extracting network parameters from the Server DHCP messages
                                                    between nx_dhcp_extract_information and nx_dhcp_process, in particular if the 
                                                    ARP probe is enabled. This also fixed a bug with using nx_dhcp_send_arp_probe of 
                                                    calling the state change notify function before the probe completed and the DHCP Client
                                                    properly promoted to the BOUND state. 

                                                    Simplified the logic in nx_dhcp_start and nx_dhcp_request_client_ip for setting the DHCP 
                                                    Client state with respect to the Client requesting a particular IP address.
 
                                                    Modified nx_dhcp_get_response() to prevent invalid packet releases.

                                                    Removed the requirement for having the DHCP CLient to have a non zero interface IP address for using 
                                                    the option to skip the discovery step. 
                                                    
                                                    Modified nx_dhcp_process, nx_dhcp_release, nx_dhcp_decline and nx_dhcp_reinitialize to clear the DHCP
                                                    Client copy of network parameters (e.g. network mask, gateway) if the DHCP Client is clearing the 
                                                    interface IP address and gateway.

                                                    Made a correction to nx_dhcp_send_response_internal to always send DISCOVERY messages
                                                    as broadcast packets as per the RFC 2131.

                                                    Made a correction to nx_dhcp_send_response_internal to always send REQUEST messages
                                                    as broadcast packets if the DHCP Client is in the REBIND or REQUESTING state as per the RFC 2131.

                                                    Made corrections for creating and sending the INFORM_REQUEST message. 
                                         
                                                    Created nx_dhcp_decline() to send DECLINE messages

                                                    Modified nx_dhcp_send_request() to disallow RELEASE and DECLINE messages.

                                                    Removed logic in nx_dhcp_client_arp_probe_send() setting IP network parameters.  Modified to only 
                                                    return status if the IP address is not in use.  


                                                    Modified nx_dhcp_release to set the start flag to false which is required to be able to restart the client with nx_dhcp_start().  

                                                    Modified nx_dhcp_delete() to unbind the socket before deleting. 

                                                    Modified nx_dhcp_delete() and nx_dhcp_create() to delete the DHCP Client packet pool only if the DHCP 
                                                    Client task created it. 

                                                    Modified nx_dhcp_option_retrieve() for an error in parsing the option buffer. 

                                                    Modified nx_dhcp_process() to sleep for the NX_DHCP_TIME_INTERVAL only if the 
                                                    DHCP client is at or beyond the bound state.

                                                    Modified nx_dhcp_process() to set the IP network address to zero if the ARP probe 
                                                    fails. This ensures the DHCP Client sends the subsequent DHCP messages out as broadcast
                                                    (not unicast).  

                                                    Modified nx_dhcp_process() to adjust the DHCP Client time remaining on its IP lease for 
                                                    the length of time of the ARP probe.


            nxd_dhcp_client.h                       Added nx_dhcp_decline to the list of DHCP Client API services

                                                    Modified nx_dhcp_client_arp_probe_send definition

                                                    Added internal flags to the DHCP CLient struct to simplify internal logic of the DHCP
                                                    Client processing messages from the Server.



Release 5.3   01-12-2012

        
            nxd_dhcp_client.c                       Added  _nx_dhcp_server_address_get, for obtaining the DHCP server address and
                                                    _nx_dhcp_packet_pool_set to allow the host application to create the packet pool instead
                                                    of the default DHCP Client packet pool.  

                                                    Added critical section and mutex protection to the DHCPv6 Client

                                                    
                                                    Modified nx_dhcp_get_response to add missing nx_packet_release calls to prevent packet leaks.

            nxd_dhcp_client.h                       Corrected the definition for NX_PACKET_ALLOCATE_TIMEOUT

                                                    Created a configuration option NX_DHCP_CLIENT_USER_CREATE_PACKET_POOL for the new feature for the 
                                                         host application to optionally create the DHCP Client packet pool



Release 5.2    10-10-2011

            nxd_dhcp_client.c                       First release of NetX Duo DHCP Client (branched from NetX DHCP Client)     
                                                    
                                                    Renamed the NetX Duo Client source code file from nx_dhpc.c to nxd_dhcp_client.c to specify the 
                                                    DHCP Client and to indicate that the DHCP Client will work properly in an IPv6 enabled NetX Duo 
                                                    environment. 

 

            nxd_dhcp_client.h                       Renamed the NetX Duo Client header file from nx_dhpc.h to nxd_dhcp_client.h



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com
