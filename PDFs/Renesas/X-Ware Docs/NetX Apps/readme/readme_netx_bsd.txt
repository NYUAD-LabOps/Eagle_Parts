Revision History for NetX BSD

07-15-2018  NetX BSD wrapper version 5.11. This release includes the following major features:

       nx_bsd.c modified API functions:
            inet_pton - Fixed compiler warnings.
            nx_bsd_socket_set_inherited_settings - Removed NX_BSD_INHERIT_LISTENER_SOCKET_SETTINGS.
            nx_bsd_raw_packet_info_extract - Used interface index since nx_interface_ip_instance 
                                               is removed from interface structure.

       nx_bsd.c - Removed NetX trace event.
                  Improved internal logic.

       nx_bsd.h - Removed NX_BSD_INHERIT_LISTENER_SOCKET_SETTINGS which is now enabled, not optional
                  and NX_BSD_TIMED_WAIT_TIMEOUT - no longer in use.
                  Used time_t from time.h.

       nx_bsd.c modified internal functions:
            nx_bsd_udp_receive_notify - used API to receive UDP packet to verify checksum.
            nx_bsd_udp_packet_received - used API to receive UDP packet to verify checksum.


05-10-2016  NetX BSD wrapper version 5.10. This release includes the following major features:

       nx_bsd.h - Included internal header file in C file.

       nx_bsd.c - Included internal header file in C file.

       nx_bsd.c modified API functions:
            getsockopt - Optimized the logic for keepalive feature.
            recv - Added support for thread preemption.
            setsockopt - Optimized the logic for keepalive feature.
            socket - Optimized the logic for keepalive feature.
            inet_ntop - Fixed endian swap when ntohl is not defined.

       nx_bsd.c modified internal functions:
            inet_ntoa_internal - Fixed endian swap when ntohl is not defined.
            nx_bsd_send_internal - Added a case for the error status NX_NO_PACKET.


Release 5.9   02-22-2016

1. New Features:


2. Revision 

For installation and usage please see the readme_netx_bsd.txt file included
in your distribution. The NetX BSD code version information is as follows:

02-22-2016  NetX BSD wrapper version 5.9. This release includes the following major features:

       * New features here

       bsd_demo_tcp.c - Unified ticks per second. 
                        Fixed compiler warnings.

       bsd_demo_udp.c - Unified ticks per second. 
                        Fixed compiler warnings.

       nx_bsd.h - Added support for unified timer tick macros.
                  Defined return code for environment error.
                  Modified the type of time_t and suseconds_t from ULONG to LONG.

       nx_bsd.c - Fixed compiler warnings.

       nx_bsd.c modified API functions:
           bsd_initialize - Returned error when extended notify feature was disabled.
           recv - Fixed return value when peer shutdown orderly.
                  Fixed statistics of TCP socket.
           send - Fixed length of data sent.
           sendto - Fixed length of data sent.
           connect - Fixed errno when connection timeouts.
           inet_addr - Corrected the status process of inet_aton.
           setsockopt - Added support for SO_SNDTIMEO option.
                        Unified ticks per second. 
                        Renamed symbols from NX_TCP_ENABLE_KEEPALIVE to NX_ENABLE_TCP_KEEPALIVE,
                        and from NX_TCP_ENABLE_WINDOW_SCALING to NX_ENABLE_TCP_WINDOW_SCALING.
           select - Unified ticks per second. 
                    Fixed statistics of TCP socket.

       nx_bsd.c modified internal functions:
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


01-12-2015  Initial BSD generic code version 5.8.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com

