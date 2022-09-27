Revision History for NetX Duo DHCP (IPv4) Server

Release 5.11  07-15-2018

            nxd_dhcp_server.c                       Fixed an error checking for interface index in _nx_dhcp_create_server_ip_address_list().

                                                    Removed #if 0 code for feature never implemented in
                                                      _nx_dhcp_server_extract_information().

                                                    Improved internal logic.

                                                    Fixed a compiler warning.

            nxd_dhcp_server.h                       Removed unused symbol:NX_DHCP_CLIENT_IDENTIFIER_MAX.


Release 5.10  05-10-2016

            nxd_dhcp_server.c                       Added flag events to process packet receive event, fast periodic event and slow periodic event.
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

            nxd_dhcp_server.h                       Added flag events to process packet receive event, fast periodic event and slow periodic event.



Release 5.9   02-22-2016

            demo_netxduo_dhcp.c                     Unified ticks per second.

                                                    Simplified the demo.

                                                    Fixed compiler warnings.

            nxd_dhcp_server.c                       Unified ticks per second in nx_dhcp_server_create().
 
                                                    Optimized process logic in nx_dhcp_server_thread_entry().
 
                                                    Fixed a packet leak in nx_dhcp_listen_for_message().
                                                    
                                                    Fixed the bug for user options seek in nx_dhcp_server_extract_information.

                                                    Initialized dhcp client in nx_dhcp_listen_for_message.

                                                    Copied the incoming data in one packet from dhcp server pool in nx_dhcp_listen_for_messages.

                                                    Fixed a bug in nx_dhcp_server_extract_information to initialize the dhcp_client_ptr to NULL in the event
                                                    the function encounters an invalid packet. Previously, the function returned a garbage dhcp_client_ptr to 
                                                    the caller which would then dereference it and get an exception.
                                                    
                                                    Send NACK message if the client's requested IP address is incorrect in _nx_dhcp_validate_client_message.

                                                    Simplified the logic to find, record and clear the IP address owner.
                                                    
                                                    Fixed compiler warnings.

            nxd_dhcp_server.h                       Unified ticks per second.

                                                    Adjusted the default value of configuration options.
                                                    
                                                    Optimized the structure.

Release 5.8   01-12-2015
        
            nxd_dhcp_server.c                       Modified the process of DHCP Server response message, set the correct destination address 
                                                    and destination port according to the 'giaddr', 'ciaddr' and broadcast bit. 

                                                    Modified the logic in nx_dhcp_server_validate_client_message to delay
                                                    NACKs to finish checking for invalid data which requires the Server
                                                    to respond silently.

                                                    Added logic in nx_dhcp_listen_for_messages to check for invalid DHCP packet length
                                                    being less than NX_DHCP_HEADER_SIZE.
                            
                                                    Removed the MULTI_HOME_NETXDUO macro definition.

                                                    Fixed a bug of DHCPv4 Server option added operation

                                                    Removed the internal function from nxd_dhcp_server.h into nxd_dhcp_server.c.

                                                    Used API to get the interface instead of directly getting the internal parameters.

                                                    Corrected memset in nx_dhcp_server_create_ip_list() for the size input arguement.


            nxd_dhcp_server.h                       Created a new error status for malformed packets (0xA4).  Added a new define for
                                                    DHCP header size (no option bytes)  NX_DHCP_HEADER_SIZE. 
                                                    
                                                    Removed the MULTI_HOME_NETXDUO macro definition. 

                                                    Removed useless function declaration (nx_dhcp_create_server_ip_address_list_text). 

Release 5.4   01-31-2013

        
            nxd_dhcp_server.c                       Replaced an array of CHAR pointers with a single CHAR array for the DHCP 
                                                    Server dhcp_name field.  Modified nx_dhcp_server_create() to copy the input 
                                                    name to the server dhcp_name field.
            nxd_dhcp_server.h                       


Release 5.3   01-12-2012

        
            nxd_dhcp_server.c                       Renamed internal functions, error constants and definitions to avoid conflicts with the 
                                                    DHCP client.

            nxd_dhcp_server.h                       Renamed internal functions, error constants and definitions to avoid conflicts with the 
                                                    DHCP client.


Release 5.2    10-10-2011

            nxd_dhcp_server.c                       First release of NetX Duo DHCP Server (branched from NetX DHCP Server)     
                                                    
                                                    Renamed the NetX Duo Server source code file from nx_dhpc_server.c to nxd_dhcp_server.c to 
                                                    indicate that the DHCP Server will work properly in an IPv6 enabled NetX Duo 
                                                    environment. 

 

            nxd_dhcp_server.h                       Renamed the NetX Duo Server header file from nx_dhpc_server.h to nxd_dhcp_server.h



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com
