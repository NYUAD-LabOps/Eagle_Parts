Revision History for NetX Duo DHCPv6 Server 

Release 5.11  07-15-2018

            demo_netxduo_dhcpv6.c                   Corrected the symbol name and value for hardware type.

            nxd_dhcpv6_server.c                     Fixed the bug for checking length.
                                                      Function is modified:
                                                      _nx_dhcpv6_server_process_iana()

                                                    Improved packet length verification.
                                                      Function is modified:
                                                      _nx_dhcpv6_listen_for_messages()

                                                    Improved internal logic.
                                                      Functions are modified:
                                                      _nx_dhcpv6_assign_ip_address()
                                                      _nx_dhcpv6_find_client_record_by_duid()
                                                      _nx_dhcpv6_add_ip_address_lease()
                                                      _nx_dhcpv6_create_ip_address_range()
                                                      _nx_dhcpv6_reserve_ip_address_range()
                                                      _nx_dhcpv6_retrieve_client_record()
                                                      _nx_dhcpv6_server_utility_time_randomize()

            nxd_dhcpv6_server.h                     Corrected the symbol name and value for hardware type.

Release 5.10  05-10-2016

            nxd_dhcpv6_server.c                     Fixed the typo, rename NX_DHCPV6_STATUS_NO_ADDRS_AVAILABLE to NX_DHCPV6_STATUS_MESSAGE_NO_ADDRS_AVAILABLE.

            nxd_dhcpv6_server.h                     Fixed the typo, rename NX_DHCPV6_STATUS_NO_ADDRS_AVAILABLE to NX_DHCPV6_STATUS_MESSAGE_NO_ADDRS_AVAILABLE.


Release 5.9   02-22-2016

            demo_netxduo_dhcpv6.c                   Unified ticks per second.

                                                    Simplified the demo.

                                                    Fixed compiler warnings.

            demo_netxduo_dhcpv6_client.c            Unified ticks per second.

                                                    Fixed compiler warnings.

            nxd_dhcpv6_server.c                     Unified ticks per second.

                                                    Copied the incoming data in one packet from dhcpv6 server pool in nx_dhcpv6_listen_for_messages.
                                                    
                                                    Fixed the bug for IPv6 address get.

                                                    Fixed compiler warnings.

            nxd_dhcpv6_server.h                     Unified ticks per second.
            
                                                    Fixed the bug for IPv6 address get.

Release 5.8   01-12-2015

            nxd_dhcpv6_server.c                     Fixed the compiler warnings
     
                                                    Removed MULTI_HOME macro definition.

                                                    Used NetX Duo API to get the interface instead of directly getting the internal parameters.

                                                    Fixed the bug for physical address check.
   

Release 5.4   01-31-2013

           nxd_dhcpv6_server.c                      Modified comments for release 5.4
           nxd_dhcpv6_server.h                      Modified comments for release 5.4


Release 5.1   01-12-2012

        
            nxd_dhcpv6_server.c                     Modified the nx_dhcpv6_server_create function to include a stack size. Defaulted the 
                                                    DHCPv6 server IP address index to 1 instead of requiring the host application to use 
                                                    the nx_dhcpv6_server_set_interface (only necessary if using the non primary interface 
                                                    or global address not at index 1 in the IP address table). 

                                                    Renamed internal functions and #defines to avoid compile erros in projects including the DHCPv6 Client 


            nxd_dhcpv6_server.h                     Renamed internal functions and #defines to avoid compile erros in projects including the DHCPv6 Client



Release 5.0  - This is the initial release.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com
