Revision History for NetX Duo DHCPv6 Client


Release 5.11  07-15-2018

            demo_netxduo_dhcpv6.c                   Corrected the symbol name and value for hardware type.

            demo_netxduo_dhcpv6_client.c            Corrected the symbol name and value for hardware type.

            nxd_dhcpv6_client.c                     Corrected the symbol name and value for hardware type.
                                                      Function is modified:
                                                      _nxe_dhcpv6_create_client_duid()

                                                    Added support for EUI-64 hardware type.  
                                                      Functions are modified:
                                                      _nx_dhcpv6_add_client_duid()
                                                      _nx_dhcpv6_add_server_duid()
                                                      _nx_dhcpv6_create_client_duid()
                                                      _nx_dhcpv6_process_client_duid()
                                                      _nx_dhcpv6_process_server_duid()
                                                      _nxe_dhcpv6_create_client_duid()

                                                    Added function to set the destination address where DHCP message should be sent.
                                                      Functions are modified:
                                                      _nx_dhcpv6_client_create()
                                                      _nx_dhcpv6_client_set_destination_address()
                                                      _nxe_dhcpv6_client_set_destination_address()

                                                    Corrected the logic for setting the source address.  
                                                      Function is modified:
                                                      _nx_dhcpv6_send_request()

                                                    Supported for rapid option.
                                                      Function is modified:
                                                      _nx_dhcpv6_scan_packet_options()

                                                    Improved packet length verification.
                                                      Function is modified:
                                                      _nx_dhcpv6_packet_process()

                                                    Improved internal logic.
                                                      Function is modified:
                                                      _nx_dhcpv6_add_client_ia()
                                                      _nx_dhcpv6_client_create()
                                                      _nx_dhcpv6_create_client_duid()
                                                      _nx_dhcpv6_get_valid_ip_address_lease_time()
                                                      _nx_dhcpv6_process_domain_name()
                                                      _nx_dhcpv6_process_server_duid()
                                                      _nx_dhcpv6_remove_assigned_address()

                                                    Added support for setting DHCPv6 server as default router.
                                                      Functions are modified:
                                                      _nx_dhcpv6_packet_process()
                                                      _nx_dhcpv6_register_IP_address()
                                                      _nx_dhcpv6_remove_assigned_address()

            nxd_dhcpv6_client.h                     Corrected the symbol name and value for hardware type.

                                                    Added support for EUI-64 hardware type.

                                                    Added function to set the destination address where DHCP message should be sent.

                                                    Added support for setting DHCPv6 server as default router.

Release 5.10  05-10-2016

            *.c                                     Modified comments.
            *.h                                     Modified comments.


Release 5.9   02-22-2016

            demo_netxduo_dhcpv6.c                   Unified ticks per second.

                                                    Simplified the demo.

                                                    Fixed compiler warnings.

            demo_netxduo_dhcpv6_client.c            Unified ticks per second.

                                                    Fixed compiler warnings.

            nxd_dhcpv6_client.c                     Unified ticks per second.
            
                                                    Verified the incoming data does not exceed our DHCPv6 Client packet payload in _nx_dhcpv6_packet_process().
                                                    
                                                    Fixed the bug for setting IPv6 address change notify in _nx_dhcpv6_client_create().
                                                    
                                                    Fixed the bug for setting address status in _nx_dhcpv6_register_IP_address().

                                                    Renamed symbols from NX_IPV6_ADDRESS_CHANGE_NOTIFY_ENABLE to NX_ENABLE_IPV6_ADDRESS_CHANGE_NOTIFY,
                                                      NXDUO_DISABLE_DAD to NX_DISABLE_IPV6_DAD since NetX Duo renamed these symbols.

                                                    Fixed compiler warnings.

            nxd_dhcpv6_client.h                     Unified ticks per second.

                                                    Added conditional code for DAD notify declaration.

                                                    Renamed symbols from NX_IPV6_ADDRESS_CHANGE_NOTIFY_ENABLE to NX_ENABLE_IPV6_ADDRESS_CHANGE_NOTIFY,
                                                      NXDUO_DISABLE_DAD to NX_DISABLE_IPV6_DAD since NetX Duo renamed these symbols.

                                                    Fixed compiler warnings.

Release 5.8   01-12-2015

            nxd_dhcpv6_client.c                     Created nx_dhcpv6_get_valid_ip_address_prefix service for obtaining the prefix of 
                                                    addresses assigned by DHCPv6 servers.

                                                    Modified nx_dhcpv6_thread_entry to automatically restart the SOLICIT messages if the DHCPv6 Client
                                                    IPv6 address expires. Previously it put the DHCPv6 Client in the INIT state, requiring the DHCPv6
                                                    Client app to manually restart the SOLICIT messages. 
                                      
                                                    Created nx_dhcpv6_get_time_server_address service for obtaining the time server address assigned by DHCPv6 Servers.

                                                    Added support for the FQDN option to the DHCPv6 Client, with new API nx_dhcpv6_request_option_FQDN

                                                    Fixed the bug for NoAddrsAvail status in nx_dhcpv6_process()

                                                    Modified the nx_dhcpv6_server_error_handler function; the message type should be the type of received message 
                                                    and defined status codes to reflect the error (see nxd_dhcpv6_client.h). 

                                                    Modified the nx_dhcpv6_resume function to support for DHCPv6 state restore feature.

                                                    Added nx_dhcpv6_client_get_record and nx_dhcpv6_client_restore_record functions to realize the DHCPv6 Client restore feature.

                                                    Added _nx_dhcpv6_flush_queue_packets function to flush the useless queue packets 

                                                    Loop to receive the queue packets until get the valid answer or timeout.
                                                    

            nxd_dhcpv6_client.h                     Added support for the FQDN option, including defining FQDN settings and creating a new NX_DHCPV6_CLIENT_FQDN struct

                                                    Added declaration of nx_dhcpv6_get_valid_ip_address_prefix service API service.

                                                    Added declaration of nx_dhcpv6_get_time_server_address service API service.

                                                    Added nx_dhcp_seconds to the DHCP CLIENT struct.
                                                    
                                                    Defined error status codes for server error handler op codes; NX_DHCPV6_ERROR_STATUS_CODE_IN_OPTION_FIELD,  
                                                    NX_DHCPV6_ERROR_STATUS_CODE_IN_IA_NA, and NX_DHCPV6_ERROR_STATUS_CODE_IN_IA_ADDRESS.

                                                    Added nx_dhcpv6_client_get_record and nx_dhcpv6_client_restore_record functions to realize the DHCPv6 Client restore feature.

                                                    Added _nx_dhcpv6_flush_queue_packets function to flush the useless queue packets.

                                                    Optimized DHCPv6 struct, removed nx_dhcpv6_valid_advertise_or_reply_flag.   
 
Release 5.4   01-31-2013

            *.c, *.h                                Restructure of NetX Duo DHCPv6 client implementation.

Release 5.3   01-12-2012

        
            nxd_dhcpv6_client.c                     Modified the DHCPv6 Client thread task to be stoppable at any time

                                                    Added nx_dhcpv6_stop and nx_dhcpv6_reinitialize for stopping and restarting the Client

                                                    Added nx_dhcpv6_register_IP_address for updating NetX Duo with the DHCPv6 Client assigned IP address

                                                    Modified DHCPv6 Client to remove IP address from the IP instance address table if an IP address is not reassigned
                                                    for example if rebind fails or host decides to release or decline an assigned address
                                                    
                                                    Added critical section and mutex protection to the DHCPv6 Client

            nxd_dhcpv6_client.h                     Corrected the timer interval for the accrued lifetime entry function to use seconds, not ticks

                                                    Created a BOUND state and removed the FAILURE state (not useful); the BOUND state is a drop through
                                                    state in the DHCPv6 Client processing thread (does nothing)



Release 5.2    10-10-2011

            nxd_dhcpv6_client.c                            
                                                    
                                                    Fixed compile errors in the NetX duo 5.6 environment.

                                                    v5.1 patches:

                                                    Modified nx_dhcpv6_start() for DHCPv6 client hosts rebooting with a valid IP lease already assigned. 

                                                    Modified nx_dhcpv6_client_create_duid() not to set the link local address. The host application must do this
                                                    
                                                    Added support for multihoming and NetX Duo v5.5 and later.
 

            nxd_dhcpv6_client.h                     Fixed compile errors in the NetX duo 5.6 environment.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com
