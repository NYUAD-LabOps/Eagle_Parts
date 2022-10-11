                       BSD 4.3 Sockets API Compliancy Wrapper for NetX Duo

                                  by Express Logic, Inc.

                                   www.expresslogic.com

07-15-2018  NetX Duo BSD wrapper version 5.11. This release includes the following major features:

       bsd_demo_raw.c - Supported for disabling IPv4 feature.

       bsd_demo_tcp.c - Supported for disabling IPv4 feature.

       bsd_demo_udp.c - Supported for disabling IPv4 feature.

       nxd_bsd.c - Improved internal logic.

       nxd_bsd.c modified API functions:
            getaddrinfo - Fixed a bug that AF_INET info was returned even ai_family was set to AF_INET6.
            inet_pton - Fixed compiler warnings.
                        Fixed endian issue for IPv6 address when ntohl is not defined.
            nx_bsd_socket_set_inherited_settings - Removed NX_BSD_INHERIT_LISTENER_SOCKET_SETTINGS.
            nx_bsd_raw_packet_info_extract - Used interface index since nx_interface_ip_instance 
                                               is removed from interface structure.

       nxd_bsd.c - Removed NetX trace event.
                   Supported for disabling IPv4 feature.

       nxd_bsd.h - Removed NX_BSD_INHERIT_LISTENER_SOCKET_SETTINGS which is now enabled, not optional
                   and NX_BSD_TIMED_WAIT_TIMEOUT - no longer in use.
                   Used time_t from time.h.

       nxd_bsd.c modified internal functions:
            nx_bsd_udp_receive_notify - used API to receive UDP packet to verify checksum.
            nx_bsd_udp_packet_received - used API to receive UDP packet to verify checksum.
            _nxd_bsd_ipv6_packet_send - Checked interface for router lookup.
                                        Moved destination and ND cache tables to IP structure.


05-10-2016  NetX Duo BSD wrapper version 5.10. This release includes the following major features:

       nxd_bsd.h - Included internal header file in C file.

       nxd_bsd.c - Included internal header file in C file.

       nxd_bsd.c modified API functions:
            getsockopt - Optimized the logic for keepalive feature.
            recv - Added support for thread preemption.
            setsockopt - Optimized the logic for keepalive feature.
            socket - Optimized the logic for keepalive feature.
            inet_ntop - Fixed endian swap when ntohl is not defined.

       nxd_bsd.c modified internal functions:
            _nxd_bsd_ipv6_packet_send - Modified the parameter list of _nx_icmpv6_send_ns.
            inet_ntoa_internal - Fixed endian swap when ntohl is not defined.
            nx_bsd_find_interface_by_source_addr - Fixed endian swap when ntohl is not defined.
            nx_bsd_send_internal - Added a case for the error status NX_NO_PACKET.


Release 5.9   02-22-2016

1. New Features:


2. Revision 

For installation and usage please see the readme_netxduo_bsd.txt file included
in your distribution. The NetX Duo BSD code version information is as follows:

02-22-2016  NetX Duo BSD wrapper version 5.9. This release includes the following major features:

       * New features here

       bsd_demo_raw.c - Unified ticks per second. 
                        Fixed compiler warnings.

       bsd_demo_tcp.c - Unified ticks per second. 
                        Fixed compiler warnings.

       bsd_demo_udp.c - Unified ticks per second. 
                        Fixed compiler warnings.

       nxd_bsd.h - Added support for unified timer tick macros.
                   Defined return code for environment error.
                   Modified the type of time_t and suseconds_t from ULONG to LONG.

       nxd_bsd.c - Fixed compiler warnings.

       nxd_bsd.c modified API functions:
           bsd_initialize - Returned error when extended notify feature was disabled.
           recv - Fixed return value when peer shutdown orderly.
                  Fixed statistics of TCP socket.
           send - Fixed length of data sent.
           sendto - Fixed length of data sent.
           connect - Fixed errno when connection timeouts.
           bind - Added logic to allow TCP IPv4 and IPv6 sockets to share a port if reuse is enabled 
                  on the sockets (which it is by default. This lets BSD emulate a TCP client socket that accepts
                  and transmits IPv4 and IPv6 packets. 
           inet_addr - Corrected the status process of inet_aton.
           setsockopt - Unified ticks per second. 
                        Added support for SO_SNDTIMEO option.
                        Renamed symbols from NX_TCP_ENABLE_KEEPALIVE to NX_ENABLE_TCP_KEEPALIVE,
                        and from NX_TCP_ENABLE_WINDOW_SCALING to NX_ENABLE_TCP_WINDOW_SCALING.
           select - Unified ticks per second. 
                    Fixed statistics of TCP socket.

       nxd_bsd.c modified internal functions:
           bsd_initialize - Used tx_thread_sleep instead of setting event from timer.
           nx_bsd_select_wakeup - Cleared fd_sets in suspend info if they were not met.
           nx_bsd_send_internal - Supported to return length of data sent. 
                                  Fixed timeout for packet process.
                                  Added support for SO_SNDTIMEO option.
           nx_bsd_socket_set_inherited_settings - Renamed symbols from NX_TCP_ENABLE_KEEPALIVE to NX_ENABLE_TCP_KEEPALIVE,
                                                  and from NX_TCP_ENABLE_WINDOW_SCALING to NX_ENABLE_TCP_WINDOW_SCALING.
           nx_bsd_tcp_socket_disconnect_notify - Fixed errno when connection timeouts.
           nx_bsd_timer_entry - Used tx_thread_sleep instead of setting event from timer.
           nx_bsd_thread_entry - Used tx_thread_sleep instead of setting event from timer.


Release 5.8   01-12-2015

1. New Features:

   NetX Duo BSD wrapper 5.8 added support for raw sockets. Optimized bsd structure. Supported optimized packet structure.

2. Revision 

For installation and usage please see the readme_netxduo_bsd.txt file included
in your distribution. The NetX Duo BSD code version information is as follows:

01-12-2015  NetX Duo BSD wrapper version 5.8. This release includes the following major features:

       * New features here

       nxd_bsd.h - Fixed FD_SETSIZE, added PPPOE and DNS support,
                   added inet_pton, inet_ntop, getnameinfo, getaddrinfo, freeaddrinfo services,
                   supported flags MSG_PEEK.

                   New configuration option for TCP socket disconnect, NX_BSD_TCP_SOCKET_DISCONNECT_TIMEOUT.
                   The default value is 1 (timer tick) 

       nxd_bsd.c added API functions:
           inet_pton - This function converts an IP address from presentation to numeric.
           inet_ntop - This function converts an IP address from numeric to presentation.
           getaddrinfo - This function returns one or more addrinfo structures according
                         to the specified node and service.
           freeaddrinfo - This function releases the memory allocated by getaddrinfo.
           getnameinfo - This function converts a socket address to a corresponding host and service.
       
       nxd_bsd.c modified API functions:
           socket - Improved UDP and raw socket performance. 
           connect - Fixed error status when connection fails in blocking mode.
           bind   - Fixed a bug in local bound port, improved UDP socket performance. 
           accept - Cleared the INPROGRESS flag when connection is established.
           getsockname - Fixed port value for UDP socket.
           recv   - Fixed how socket timeout is handled.  Socket doing blocked receive
                    with timeout value would not wake up if there are other BSD sockets
                    receiving data. Fixed return code. Supported flags MSG_PEEK and MSG_DONTWAIT.
           recvfrom - Supported flags MSG_PEEK and MSG_DONTWAIT.
           select - Fixed fd_set value when socket is not in use.
                    Removed an obsolete for loop clearing blocked sockets for new connection requests.
           send - Supported raw PPPOE. Supported flags MSG_DONTWAIT.
           sendto - Supported raw PPPOE. Supported flags MSG_DONTWAIT.
           soc_close - Improved UDP and raw socket performance.
                       Added support for NX_BSD_TCP_SOCKET_DISCONNECT_TIMEOUT in the nx_tcp_socket_disconnect call.
                       Fixed a bug that secondary socket was not disconnected. 
           ioctl  - Added logic for applications to clear the non-blocking flag.
                    Modified FIONREAD option to capture the correct number of bytes received on the UDP socket
           inet_ntoa  - Move logic to internal function inet_ntoa_internal.
           inet_aton - Added an error return if an invalid character is received
                       for base-16 address buffer. Fixed a bug of processing hex number.
           FD_SET - Fixed FD_SETSIZE check
           FD_CLR - Fixed FD_SETSIZE check
           FD_ISSET - Fixed FD_SETSIZE check
           FD_ZERO  - Fixed FD_SETSIZE value 

        nxd_bsd.c added internal functions:
           nx_bsd_pppoe_internal_sendto - This function sends raw PPPOE packet to driver directly.
           _nx_bsd_pppoe_packet_received - This function receives raw PPPOE packet from driver directly.
           inet_ntoa_internal - This function converts an IPv4 address to a string and 
                                returns the size of the string.
           bsd_string_to_number - This function converts string to number.
           nx_bsd_set_service_list - This function lets user set the service list used by getaddrinfo.
           _nx_bsd_string_length - This function returns the length of string.

        nxd_bsd.c modified internal functions:
           bsd_initialize - Supported getaddrinfo and getnameinfo APIs.
           nx_bsd_timeout_process - Corrected the logic and comment to skip client sockets.
           nx_bsd_send_internal - Remove unnecessary code. Supported flags MSG_DONTWAIT.
           bsd_number_convert - Added support for HEX number. Added argument to avoid overflow. 
           nx_bsd_raw_socket_filter - Improved the raw socket search logic.
           nx_bsd_tcp_create_listen_socket - Fixed a bug to allow accept from remote end.
           nx_packet_data_extract_offset - Fixed a bug when offset and length of packet are both zero.
           nx_bsd_udp_packet_received - Improved the UDP socket search logic
           nx_bsd_tcp_syn_received_notify - Fixed connection status
           _nxd_bsd_ipv4_packet_send - Encapsulated all IGMP-related infomation.

        nxd_bsd.c removed internal functions:
           nx_bsd_isascii


01/31/2013  NetX Duo BSD wrapper version 5.3. This release includes the following major features:

          * Raw socket support

    New functions created:
        nx_bsd_raw_filter_set - sets a function pointer to the BSD function that filters packets when raw
                  sockets are enabled in NetX Duo and NX_RAW_PACKET_FILTER_ENABLE is defined at NetX Duo
                  library build time.  Note that if there are multiple BSD raw sockets using the same protocol,
                  the behavior in NetX Duo is undefined. BSD sockets should copy received packets to all raw sockets
                  having the same protocol, but this is not implemented in BSD 5.3

            nx_bsd_packet_receive- Retrieves packets enqueued on the BSD raw socket queue.

            nx_bsd_raw_packet_info_extract - Extracts the raw packet sender and physical interface.  

            nx_bsd_raw_receive_notify - This is the callback function NetX Duo uses when a raw packet has been received
                   and raw sockets are enabled in NetX Duo.
                          
        nx_bsd_raw_packet_filter - receives packets from NetX Duo if raw sockets are enabled and determines if 
                   BSD will consume the packet or let NetX Duo continue processing the packet e.g. hand off to TCP,
                   UDP, ICMP and other protocol handlers.

        Modified functions
        sendto - modified to send raw packets out the BSD socket if raw sockets are enabled.

            recv - modified to receive raw packets if raw sockets enabled in NetX Duo

        select - modified to receive raw packets if raw sockets enabled in NetX Duo

        connect - modified to check for and disallow raw sockets to use this service 

        send - modified to check for and disallow raw sockets to use this service
            
            soc_close - modified for closing BSD sockets enabled for raw socket handling, including 
                        manully clearing packet from the raw receive queue 
    
        nxd_bsd.h - added the NX_BSD_PRINT_ERROR macro definition (disbaled by default0 for debug output
    
        Errata

            send, sendto - modified to remove potential packet leaks after a transmit packet has been allocated.
            nx_bsd_establish_notify_callback - replaced NX_BSD_SOC_ERROR with NX_BSD_SOC 
            nx_bsd_timeout_process - fixed bug (and comment) to select for TCP server sockets instead of client sockets.



01/05/2012  NetX Duo BSD version 5.2. This release includes the following major features:

          * New socket options SO_RCVBUF, SO_RCVTIMEO, and SO_SNDTIMEO
                  SO_RCVBUF is equivalent to setting the TCP receive windows size in the nx_tcp_socket_create call
                  SO_RCVTIMEO sets the wait option on TCP and UDP socket receive calls
                  SO_SNDTIMEO sets the wait option on TCP receive calls and for UDP sockets the wait to allocate a packet and obtain the BSD mutex

          * New configuration option NX_EXTENDED_BSD_LINGER_AND_TIMED_WAIT for optimal compiling with BSD Extended options enabled
                  By default this is disabled; This reduces code size by eliminating the two ThreadX timers for Linger and Timed Wait socket options,
                  and the ThreadX task for handling timer expiration. 

          * Modified socket error handling to avoid collisions with errno in non ThreadX header files.
                  This reduces code size by placing the lines of code for setting all socket errors in one function.

    New functions created:
        set_errno - handles socket error handling to reduce code size
            nx_bsd_socket_set_inherited_settings - handles socket inheritance to reduce code size
        
        
        Modified functions
        nx_bsd_thread_entry - only compiles if NX_EXTENDED_BSD_LINGER_AND_TIMED_WAIT is enabled
            sendto - uses send() for the common logic of transmitting packets out BSD sockets
        accept - modified for implementing the timed wait state on the master server socket
        connect - modified for implementing the timed wait state 
            nx_bsd_timed_wait_timer_entry - renamed from nx_bsd_timer_entry for semantic reasons
        Errata
            tx_user.h  
                    Renamed TX_THREAD_USER_EXTENSION variable errno to bsd_errno to avoid collision with other non ThreadX header files
        nxd_bsd.h 
                    NX_BSD_INHERIT_LISTENER_SOCKET_SETTINGS corrected to be enabled by default 
        nxd_bsd.c
                    Compile error caused by NX_BSD_ADDRESS_FAMILY_ERROR fixed
                    Compile error caused by NX_BSD_ERROR(NX_BSD_ERROR, __LINE__); fixed


Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com

