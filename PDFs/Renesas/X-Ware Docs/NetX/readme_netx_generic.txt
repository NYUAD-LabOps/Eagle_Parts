                        Express Logic's NetX  

1. Revision History

For installation and usage please see the readme_netx.txt file included
in your distribution. For port-specific version information, please refer
to the bottom of readme_netx.txt. The NetX generic code version 
information is as follows:

07/15/2018  NetX generic code version 5.11. This release includes the following modifications:

        Files are modified to unify the code format:
            *.c
            *.h

        Files are modified to fix custom MSS value:
            nx_api.h
            nx_tcp_client_socket_connect.c
            nx_tcp_packet_process.c
            nx_tcp_packet_send_syn.c
            nx_tcp_server_socket_relisten.c
            nx_tcp_socket_mss_get.c
            nx_tcp_socket_mss_peer_get.c
            nx_tcp_socket_mss_set.c
            nx_tcp_socket_send.c

        Files are modified to improve internal logic:
            nx_arp_packet_receive.c
            nx_ip_packet_send.c
            nx_ram_network_driver.c
            nx_tcp_client_socket_bind.c
            nx_tcp_socket_retransmit.c
            nx_tcp_server_socket_relisten.c
            nx_udp_socket_bind.c

        Files are modified to improve packet length verification:
            nx_ip_packet_receive.c
            nx_tcp_packet_process.c

        Files are modified to be compatible with ThreadX 5.8 or later:
            nx_api.h
            nx_icmp.h
            nx_icmp_cleanup.c
            nx_ip.h
            nx_ip_delete.c
            nx_ip_raw_packet_cleanup.c
            nx_ip_raw_packet_disable.c
            nx_packet.h
            nx_packet_pool_cleanup.c
            nx_tcp.h
            nx_tcp_cleanup_deferred.c
            nx_tcp_client_bind_cleanup.c
            nx_tcp_client_socket_unbind.c
            nx_tcp_connect_cleanup.c
            nx_tcp_deferred_cleanup_check.c
            nx_tcp_disconnect_cleanup.c
            nx_tcp_receive_cleanup.c
            nx_tcp_server_socket_unaccept.c
            nx_tcp_socket_connection_reset.c
            nx_tcp_socket_disconnect.c
            nx_tcp_socket_state_established.c
            nx_tcp_socket_thread_suspend.c
            nx_tcp_transmit_cleanup.c
            nx_udp.h
            nx_udp_bind_cleanup.c
            nx_udp_receive_cleanup.c
            nx_udp_socket_unbind.c

        Files are modified to support random port find:
            nx_api.h
            nx_tcp_client_socket_bind.c
            nx_tcp_enable.c
            nx_tcp_free_port_find.c
            nx_udp_enable.c
            nx_udp_free_port_find.c
            nx_udp_socket_bind.c

        Files are modified to fix compiler errors when event trace is enabled:
            nx_trace_object_register.c
            nx_trace_object_unregister.c

        Files are modified to avoid NULL pointer access in trace logging:
            nx_ip_interface_info_get.c
            nx_udp_packet_info_extract.c
        
        Other modified files:

            nx_arp_packet_receive.c                Added check for zero IP probe address.
            nx_arp_periodic_update.c               Improved retry counter check logic.
            nx_icmp_packet_receive.c               Added logic for checking address of ICMP packet.
            nx_igmp.h                              Declare nx_igmp_interface_report_send function.
            nx_igmp_multicast_leave.c              Optimized to use the report_send function.
            nx_igmp_periodic_processing.c          Optimized to use the report_send function.
            nx_ip_fragment_assembly.c              Fixed a bug when packet in the middle was dropped,
                                                     the remaining fragments were passed to IP layer.
                                                   Corrected the logic to update the fragment tail.
            nx_tcp_packet_process.c                Fixed the packet leak.
            nx_tcp_server_socket_accept.c          Fixed an issue where SYN is sent multiple times.
            nx_tcp_server_socket_unlisten.c        Used NX_NULL instead of NX_FALSE when clearing pointers.
            nx_user.h                              Added symbol for checking address of ICMP packet.
                                                     Corrected the comment for NX_DISABLE_IGMPV2.
            nxe_ip_create                          Modified invalid IP address check.
            nxe_ip_interface_attach.c              Modified invalid IP address check.


        File created:
            nx_igmp_interface_report_send.c        Created internal function for sending join and leave reports. 



05/10/2016  NetX generic code version 5.10. This release includes the following major features:

        Files are added or modified to optimized the logic for IP address conflict detection:
            nx_api.h
            nx_arp.h
            nx_arp_announce_send.c
            nx_arp_gratuitous_send.c
            nx_arp_packet_receive.c
            nx_arp_probe_send.c

        Other modified files
            nx_user.h                              Added symbols for disabling checksum logic on received and transmitted ICMP packet.
            nx_igmp_packet_process.c               Added support for packet_chaining in nx_igmp_process_packet() checksum computation.
            nx_packet_copy.c                       Allowed zero length of chained packets. 
            nx_tcp_socket_send.c                   Replace TX_NO_WAIT with the input wait_option in packet allocate and packet append calls.
                                                     Fixed packet length when partial data are sent.
                                                     Fixed invalid packet release.


02/22/2016  NetX generic code version 5.9. This release includes the following major features:

        Files are modified to fix compiler warnings:
            demo_netx_multihome_udp.c
            demo_netx_multihome_tcp.c
            demo_netx_udp.c
            demo_netx_tcp.c
            nx_icmp_checksum_compute.c
            nx_igmp_packet_process.c
            nx_ip.h
            nx_ip_create.c
            nx_ip_deferred_link_status_process.c
            nx_ip_driver_deferred_enable.c
            nx_ip_driver_deferred_receive.c
            nx_ip_fragment_packet.c
            nx_ip_static_route_add.c
            nx_ip_static_route_delete.c
            nx_packet.h
            nx_packet_copy.c
            nx_packet_data_append.c
            nx_packet_data_extract_offset.c
            nx_tcp.h
            nx_tcp_checksum.c
            nx_tcp_cleanup_deferred.c
            nx_tcp_periodic_processing.c
            nx_tcp_socket_bytes_available.c
            nx_tcp_socket_disconnect_complete_notify.c
            nx_tcp_socket_establish_notify.c
            nx_tcp_socket_send.c
            nx_tcp_socket_state_established.c
            nx_tcp_socket_state_data_check.c
            nx_tcp_socket_timed_wait_callback.c
            nx_udp.h
            nx_udp_socket_receive.c
            nx_udp_socket_send.c
            nxe_ip_interface_status_check.c
            nxe_ip_static_route_add.c
            nxe_ip_static_route_delete.c
            nxe_ip_status_check.c
            nxe_tcp_socket_disconnect_complete_notify.c
            nxe_tcp_socket_establish_notify.c
            nxe_tcp_socket_timed_wait_callback.c
            server.c

        Files are modified to return NX_NOT_SUPPORTED when NX_ENABLE_IP_STATIC_ROUTING is not enabled:
            nx_ip_static_route_add.c
            nx_ip_static_route_delete.c
            nxe_ip_static_route_add.c
            nxe_ip_static_route_delete.c

        Files are modified to return NX_NOT_SUPPORTED when NX_DISABLE_EXTENDED_NOTIFY_SUPPORT is not enabled:
            nx_tcp_socket_disconnect_complete_notify.c
            nx_tcp_socket_establish_notify.c
            nx_tcp_socket_timed_wait_callback.c
            nxe_tcp_socket_disconnect_complete_notify.c 
            nxe_tcp_socket_establish_notify.c
            nxe_tcp_socket_timed_wait_callback.c 
            nx_tcp_enable.c

        Files are added or modified to support the link status change feature:
            nx_api.h
            nx_ip.h
            nx_ip_deferred_link_status_process.c
            nx_ip_driver_link_status_event.c
            nx_ip_link_status_change_notify_set.c
            nx_ip_thread_entry.c
            nxe_ip_link_status_change_notify_set.c

        Files are added or modified to support TCP fast retransmission:        

            nx_api.h                               
            nx_tcp.h
            nx_tcp_socket_retransmit.c
            nx_tcp_fast_periodic_processing.c
            nx_tcp_packet_send_syn.c
            nx_tcp_socket_state_ack_check.c
            nx_tcp_socket_state_transmit_check.c
            nx_tcp_socket_state_syn_sent.c
            nx_tcp_socket_state_syn_received.c
            nx_tcp_socket_send.c
            
        Files are modified to unify ticks per second, used TX_TIMER_TICKS_PER_SECOND as default vaue of NX_IP_PERIODIC_RATE:        

            demo_netx_multihome_tcp.c
            demo_netx_tcp.c
            nx_api.h
            nx_ip_create.c
            nx_system.h
            nx_system_initialize.c
            nx_tcp.h
            nx_tcp_enable.c
            nx_user.h

        Files are modified to send TCP reset message when receive an illegal TCP option:
            nx_tcp.h
            nx_tcp_packet_process.c
            nx_tcp_server_socket_relisten.c
            nx_tcp_mss_option_get.c
            nx_tcp_no_connection_reset.c
            
        Files are modified to support IP packet filter:
            nx_api.h
            nx_ip_packet_receive.c
            nx_ip_packet_send.c
            
        Files are modified to remove unused code since NAT does not support for NetX:
            nx_api.h
            nx_user.h
            nx_ip_forwarding_disable.c
            nx_ip_forwarding_enable.c
            nx_ip_packet_receive.c

        The following table contains mappings from legacy names to the new names developers
        are encouraged to use for furture development work.  For backward compatibility reasons,
        legacy names are still maintained. Therefore existing projects and build systems are not
        affected.

                  Legacy Names                                       New Names

            NX_ARP_DISABLE_AUTO_ARP_ENTRY                       NX_DISABLE_ARP_AUTO_ENTRY
            NX_ARP_MAC_CHANGE_NOTIFICATION_ENABLE               NX_ENABLE_ARP_MAC_CHANGE_NOTIFICATION
            NX_TCP_ENABLE_KEEPALIVE                             NX_ENABLE_TCP_KEEPALIVE
            NX_TCP_ENABLE_WINDOW_SCALING                        NX_ENABLE_TCP_WINDOW_SCALING
            NX_TCP_MSS_CHECKING_ENABLED                         NX_ENABLE_TCP_MSS_CHECKING

        Files are modified to rename symbols:

            nx_api.h
            nx_arp_packet_receive.c
            nx_ip_deferred_link_status_process.c
            nx_ip_driver_link_status_event.c
            nx_ip_link_status_change_notify_set.c
            nx_ip_packet_receive.c
            nx_ip_packet_send.c
            nx_system.h
            nx_system_initialize.c
            nx_tcp.h
            nx_tcp_mss_option_get.c
            nx_tcp_packet_process.c
            nx_tcp_packet_send_ack.c
            nx_tcp_packet_send_fin.c
            nx_tcp_packet_send_rst.c
            nx_tcp_packet_send_syn.c
            nx_tcp_periodic_processing.c
            nx_tcp_server_socket_relisten.c
            nx_tcp_socket_create.c
            nx_tcp_socket_disconnect.c
            nx_tcp_socket_send.c
            nx_tcp_socket_state_ack_check.c
            nx_tcp_socket_state_data_check.c
            nx_tcp_socket_state_established.c
            nx_tcp_socket_state_syn_received.c
            nx_tcp_socket_state_syn_sent.c
            nx_user.h
            nxe_ip_link_status_change_notify_set.c
            nxe_tcp_socket_create.c

        Other modified files:

            nx_api.h                               Removed a check that IGMPv2 is not enabled (e.g. NX_DISABLE_IGMPV2 is defined).
                                                     Added a macro to disable warning of parameter not used. 
            nx_arp_packet_receive.c                Removed the check on message type when updating an existing ARP entry.
            nx_ip_packet_receive.c                 Fixed source check when address mapping is not needed.
            nx_ip_static_route_add.c               Added the check whether the route table is full.
            nx_tcp.h                               Declared API functions for TCP extended services.
            nx_tcp_packet_send_rst.c               Modified reset ack number, sequence number and ACK bit according to incoming packet ACK bit.
            nx_tcp_socket_disconnect.c             Removed check for transmit queue when connection was not established.  
                                                   Cleared ports when disconnected.
                                                   Called the cleanup routines after completed the tcp disconnected operation.
            nx_tcp_socket_packet_process.c         Checked socket state before processing data.                                                   
            nx_tcp_socket_receive.c                Modified the logic for SWS avoidance algorithm. 
            nx_tcp_socket_send.c                   Updated sequence only when packet can be sent.  
            nx_tcp_socket_state_ack_check.c        Fixed a bug while packet was not transmitted by driver,
                                                     the ACK check was incorrect.
                                                     Fixed packet that was ACKed but not released by driver.

            nx_tcp_socket_state_data_check.c       Fixed the bug for updating receive window.
                                                     Trimmed the data that out of receive window.
                                                     Optimized the logic when a packet with old data is received.
                                                     Modified the logic for SWS avoidance algorithm.
            nx_tcp_socket_state_syn_sent           Fixed the condition to send RST when ACK was received.
            nx_tcp_socket_state_transmit_check.c   Updated sequence only when packet can be sent.  
            nx_tcp_transmit_cleanup.c              Updated sequence only when packet can be sent.  



01/12/2015  NetX generic code version 5.8  This release includes the following modifications:

            nx_api.h                               Added function prototypes for new services.
                                                   Added a feature that responds to a conflict GARP packet.
                                                   Supported user defined random function.
            nx_arp.h                               Added a feature that responds to a conflict GARP packet.
            nx_arp_packet_receive.c                Added a feature that responds to a conflict GARP packet.
                                                   Fixed a bug where a packet is used after being released.
                                                   Added an ARP man in the middle detection feature.   
                                                   Block adding entries to ARP cache with zero sender IP address.
                                                   Prevent an ARP request matching an ARP entry sender address to change the mac address.
            nx_arp_periodic_update.c               Added a feature that responds to a conflict GARP packet.
            nx_icmp_checksum_compute.c             Fixed compiler warnings.
            nx_icmp_ping.c                         Fixed a bug that causes packet leak, fixed the pings sent count.
            nx_igmp_packet_process.c               Fixed compiler warnings.
            nx_ip.h                                Added function prototypes for new services.
            nx_ip_address_set.c                    Added a feature that responds to conflict GARP packets.
            nx_ip_create.c                         Added a feature that responds to conflict GARP packets.
            nx_ip_driver_interface_direct_command.c Added new service.
            nx_ip_fragment_packet.c                Fixed logic computing the fragment size relative to the MTU
            nx_ip_interface_address_set.c          Added a feature that responds to a conflict GARP packet.
            nx_ip_packet_receive.c                 Fixed a bug where inicoming address was not checked correctly,
                                                   Added a feature that allows unicast DHCP messages to be received prior
                                                   to interface address being assigned.
            nx_ip_static_route_add.c               Fixed compiler warnings.
            nx_packet_data_extract_offset.c        Optimized data copy logic with memcpy.
            nx_ram_network_driver.c                Supported more commands.
            nx_rarp_packet_send.c                  Skipped invalid interfaces.           
            nx_tcp_client_socket_connect.c         Supported user defined random function.
            nx_tcp_fast_periodic_processing        Updated intervals for sending zerop window probe. 
            nx_tcp_socket_state_data_check.c       Added feature that limits packets enqueued when received out of order,
                                                   (configuration option NX_TCP_MAX_OUT_OF_ORDER_PACKETS).
            nx_tcp_mss_option_get.c                Fixed endless loop when option length is zero.
            nx_tcp_server_socket_accept.c          Supported user defined random function.
            nx_user.h                              Added a feature that responds to a conflict GARP packet.
            nxe_udp_source_extract                 Fixed compiler warnings.
            nxe_ip_driver_interface_direct_command.c Added new service.
            demo_netx_multihome_tcp.c              Remove compiler error message when NX_MAX_PHYSICAL_INTERFACES is less than two.
            demo_netx_multihome_udp.c              Remove compiler error message when NX_MAX_PHYSICAL_INTERFACES is less than two.

04/30/2013  NetX generic code version 5.5.  This release includes the following modifications:

            
            nx_icmp_checksum_compute.c              Added conditional compilation for checksum computation.
            nx_icmp_packet_process.c                Added conditional compilation for checksum computation.
            nx_icmp_ping.c                          Added conditional compilation for checksum computation.
            nx_igmp_periodic_processing.c           Fixed a bug preventing the loop from decrementing all  
                                                      active memberships.  
            nx_ip_interface_info_get.c              Corrected a reference to interface_name pointer.    
            nx_ip_fragment_packet.c                 Removed an unnecessary 8 byte alignment check.
            nx_ip_packet_receive.c                  Fixed a bug to prevent passing TCP or UDP packets to raw process.  
                                                    Also added an option where the source address of an incoming packet 
                                                    is validated.
            nx_ip_packet_send.c                     Modified handling of packets with internal loopback addresses to be
                                                    enqueued for receive processing.
            nx_tcp_client_socket_unbind.c           Clear socket timeout on promotion to the CLOSED state.
            nx_tcp_fast_periodic_processing.c       Checked for TCP exceeding retries before handling timeout.
            nx_tcp_packet_process.c                 Increment the sequence number by 1 for an incoming SYN packet,
                                                    added a callback function that allows an application to process a 
                                                    SYN message, added an optional MSS check.
            nx_tcp_packet_send_rst.c                Cleaned code to simplify the logic.
            nx_tcp_server_socket_accept.c           Clear socket timeout on waiting for the next conenction request or
                                                    on reset back to the LISTEN state.
            nx_tcp_server_socket_listen.c           Reset the connected interafce, clear socket timeout on promotion 
                                                    to the LISTEN state.
            nx_tcp_server_socket_relisten.c         Reset the connected interafce, clear socket timeout on promotion 
                                                    to the LISTEN state.
            nx_tcp_server_socket_unaccept.c         Clear socket timeout on promotion to the LISTEN or CLOSED states.
            nx_tcp_server_socket_unlisten.c         Clear socket timeout on promotion to the LISTEN or CLOSED states.
            nx_tcp_socket_disconnect.c              Set up the SYN and ACK numbers in the fake header so the RST packet 
                                                    contains valid info, cleared socket timeout on promotion to the LISTEN 
                                                    or the CLOSED state, in the SYN_RECEIVED state, only set FIN timeout 
                                                    if no more packets to be ACKed, do not send FIN if peer is not connected.
            nx_tcp_socket_packet_process.c          Improved the handling of validating incoming TCP segments.
            nx_tcp_socket_received.c                Corrected the logic checking the receive queue against the TCP socket 
                                                    state, corrected the logic checking the received packets before 
                                                    dereferencing packet legnth.
            nx_tcp_socket_send.c                    Added logic to handle a failed return from nx_tcp_socket_send_internal() 
                                                    and removed the packet leak. 
            nx_tcp_socket_state_ack_check.c         Fixed a bug determining if packets can be released from the queue 
                                                    when the transmit window wraps.
            nx_tcp_socket_state_data_check.c        Fixed logic for handling chained packets.
            nx_tcp_socket_receive.c                 Added a check for valid packet_ptr in the receive timeout logic.
            nx_tcp_socket_state_fin_wait2.c         Clear socket timeout on promotion to the CLOSED or LISTEN state.
            nx_tcp_socket_state_syn_received.c      Update the rx_sequence_acked value, clear socket time after sending 
                                                    RST for invalid packet.
            nx_udp_packet_info_extract.c            Corrected a reference to the interface_index pointer.
            nx_user.h                               Created the option NX_TCP_MSS_CHECKING_ENABLED to check connection  
                                                    requests for a minimum MSS value, added source address check for 
                                                    incoming packet.

               

06/30/2011  NetX generic code version 5.4.  This release includes the following
            modifications:

            nx_api.h                                Added TCP keepalive flag, added NX_IP_INTERFACE_LINK_ENABLED 
                                                    IP status, modified minor version number, added additional 
                                                    notification data structures/prototypes, added macro 
                                                    NX_PACKET_HEADER_PAD_SIZE to allow an application to specify 
                                                    the number of ULONG words at the end of the NX_PACKET header 
                                                    such that the payload area starts on a desired alignment, and  
                                                    changed UDP socket interface send to use a pointer to a packet 
                                                    pointer.
            nx_ip.h                                 Added macro to control the amount of wait in IP status check.
            nx_tcp.h                                Added new notification function prototypes.
            nx_user.h                               Added receive and transmit UDP checksum disable options, added 
                                                    option to disable extended notify logic, and added packet padding
                                                    option.
                                                    Added NX_PACKET_HEADER_PAD_SIZE to pad towards the end of the NX_PACKET structure.
            nx_arp_dynamic_entry_set.c              Added check to make sure the entry is directly accessible via 
                                                    the interface, record the outgoing interface in ARP cache entry, 
                                                    record the outgoing interface in the packet.
            nx_arp_static_entry_create.c            Added check to make sure the entry is directly accessible via 
                                                    the interface, and record the outgoing interface in ARP cache entry.
            nx_ip_address_get.c                     Updated data structure name.                                        
            nx_ip_delete.c                          Moved clearing nx_ip_id to after cleanup calls, added a mutex 
                                                    release if IP instance has sockets bound and cannot be deleted.
            nx_ip_fragment_assembly.c               Modified logic comparing packet fragment IP header fields as per RFC 791.
            nx_ip_fragment_packet.c                 Added logic to assign the same outgoing interface to all 
                                                    subsequent IP fragments. 
            nx_ip_gateway_address_set.c             Added a missing mutex release if no interface found, clear the 
                                                    gateway if 0.0.0.0 is specified.  
            nx_ip_interface_status_check.c          Added macro to control the amount of wait in IP status check,
                                                    and added option NX_IP_INTERFACE_LINK_ENABLED to get link enable 
                                                    from device driver level.
            nx_ip_packet_receive.c                  Added VOID* cast to avoid compiler warning, and added mask to 
                                                    checksum to convert to 16-bits.
            nx_ip_packet_send.c                     Fixed a bug where the prepend_ptr was incorrectly adjusted before
                                                    calling nx_packet_transmit_release.                                                    
            nx_ip_route_find.c                      Added logic to use user-specified outgoing interface.
            nx_ip_static_route_add.c                Added a missing mutex release if no interface found.
            nx_ip_status_check.c                    Replaced code to call the nx_ip_interface_status_check version of 
                                                    the API.
            nx_ip_thread_entry.c                    Removed packet data from the trace macro for driver deferred 
                                                    processing.
            nx_packet_data_extract_offset.c         Added logic for handling empty packets.
            nx_ram_network_driver.c                 Added support for multiple instances of the RAM driver.
            nx_rarp_packet_receive.c                Added initialization to avoid compiler warning, and added logic 
                                                    to skip invalid interfaces.
            nx_tcp_checksum.c                       Added conditional logic to disable TCP checksum entirely.
            nx_tcp_client_socket_connect.c          Added logic to restore TCP socket states after detecting errors, 
                                                    and do socket cleanup before sending the initial SYN packet.
            nx_tcp_connect_cleanup.c                Pickup IP pointer earlier to ensure it is always available for trace.
            nx_tcp_enable.c                         Added conditional inclusion of notification callbacks.
            nx_tcp_packet_process.c                 Added logic to handle a RST packet cancelling a previous 
                                                    connection request.
            nx_tcp_packet_send_ack.c                Added conditional logic to disable TCP checksum entirely.
            nx_tcp_packet_send_fin.c                Added conditional logic to disable TCP checksum entirely.
            nx_tcp_packet_send_rst.c                Added logic to use packet ACK to determine how to set RST ACK 
                                                    and sequence number, and added conditional logic to disable 
                                                    TCP checksum entirely.
            nx_tcp_packet_send_syn.c                Added conditional logic to disable TCP checksum entirely.
            nx_tcp_periodic_processing.c            Added logic to check keepalive enabled on each socket.
            nx_tcp_server_socket_accept.c           Added logic to cleanup socket before sending the SYN-ACK.
            nx_tcp_server_socket_relisten.c         Modified the relisten logic where MSS and window scale is processed 
                                                    in new request.
            nx_tcp_socket_connection_rest.c         Added logic to invoke disconnect callback.
            nx_tcp_socket_create.c                  Added support for configuring TCP Keep Alive per socket.
            nx_tcp_socket_disconnect.c              Modified fake tcp header for zero wait option.
            nx_tcp_socket_packet_process.c          Added a check for valid sequence number on RST packets.
            nx_tcp_socket_send.c                    Added conditional logic to disable TCP checksum entirely, and 
                                                    moved core login into internal function (above), added logic 
                                                    to fragment packets if required by the connection MSS, added  
                                                    support for multihome and TCP window scale feature.
            nx_tcp_socket_state_ack_check.c         Fixed logic that checks out-of-order sequence number, and 
                                                    added support for keepalive.
                                                    Fixed logic for determining if packets can be released from the
                                                    transmit queue if the transmit window wraps
            nx_tcp_socket_state_data_check.c        Break out of the loop after the packet is released, and mark 
                                                    the packet as not being part of a TCP stream before releasing 
                                                    it.
            nx_tcp_socket_state_established.c       Added support for keep alive
            nx_tcp_socket_state_fin_wait1.c         Added TCP disconnect callback
            nx_tcp_socket_state_fin_wait2.c         Added TCP disconnect callback
            nx_tcp_socket_state_last_ack.c          Added TCP disconnect callback
            nx_tcp_socket_state_syn_received.c      Added TCP establish callback, added logic to adjust the sequence 
                                                    number for proper generation of RST packet, and added per socket keepalive.
            nx_tcp_socket_state_syn_sent.c          Doubled the initial transmit congestion window, added TCP 
                                                    establish callback, added logic to adjust the sequence number for proper 
                                                    generation of RST packet, and added per socket keepalive.
            nxe_ip_gateway_address_set.c            Removed requirement that ARP be enabled before setting the gateway address.
            nxe_ip_interface_status_check.c         Added NX_IP_INTERFACE_LINK_ENABLED status option.
            nxe_ip_status_check.c                   Added NX_IP_INTERFACE_LINK_ENABLED status option.
            nxe_packet_release.c                    Removed unreachable code.
            nxe_packet_transmit_release.c           Removed unreachable code.
            nx_tcp_socket_disconnect_complete_notify.c Added new API for this release.
            nx_tcp_socket_establish_notify.c        Added new API for this release.
            nx_tcp_socket_timed_wait_callback.c     Added new API for this release.
            nxe_tcp_socket_disconnect_complete_notify.c Added error checking for new API.
            nxe_tcp_socket_establish_notify.c       Added error checking for new API.
            nxe_tcp_socket_timed_wait_callback.c    Added error checking for new API.
            demo_netx_multihome_tcp.c               Added example added to demonstrate multihome configuration.
            demo_netx_multihome_udp.c               Added example added to demonstrate multihome configuration.
            nx*.h                                   Modified comment(s).
            nx*.c                                   Modified comment(s).


12/31/2009  NetX generic code version 5.3.  This release includes the following 
            modifications:

            nx_api.h                                Corrected CLASS A defines for Net and Host ID,
                                                    added new Trace Event IDs, a link driver constant 
                                                    for interface attachment, error status codes, added 
                                                    multihome support, static routing, loopback interface, 
                                                    modified to support TCP Window Scaling feature,
                                                    IGMPv2 support, added function prototypes, set default 
                                                    handling for raw IP packets as UDP packets (user 
                                                    configurable), added support for NAT, defined a new 
                                                    control block (NX_INTERFACE), modified the following 
                                                    control block definitions: NX_PACKET, NX_TCP_SOCKET, 
                                                    NX_UDP_SOCKET, NX_IP, NX_IP_ROUTING_ENTRY, 
                                                    NX_IP_DRIVER, and added the following new APIs:

                                                        nx_igmp_multicast_interface_join
                                                        nx_ip_interface_address_get
                                                        nx_ip_interface_address_set
                                                        nx_ip_interface_attach
                                                        nx_ip_interface_info_get
                                                        nx_ip_interface_status_check
                                                        nx_ip_raw_packet_interface_send
                                                        nx_packet_data_extract_offset
                                                        nx_tcp_socket_bytes_available
                                                        nx_tcp_socket_peer_info_get
                                                        nx_tcp_socket_window_update_notify
                                                        nx_udp_packet_info_extract
                                                        nx_udp_socket_bytes_available
                                                        nx_udp_socket_interface_send

            nx_arp_initialize.c                     Removed C file that contains depreciated function
            nx_icmp_initialize.c                    Removed C file that contains depreciated function
            nx_igmp_initialize.c                    Removed C file that contains depreciated function
            nx_ip_static_route_find.c               Removed C file that contains depreciated function
            nx_ip_static_routing_disable.c          Removed C file that contains depreciated function
            nx_ip_static_routing_enable.c           Removed C file that contains depreciated function
            nx_rarp_initialize.c                    Removed C file that contains depreciated function
            nx_udp_initialize.c                     Removed C file that contains depreciated function
            nxe_ip_static_routing_disable.c         Removed C file that contains depreciated function
            nxe_ip_static_routing_enable.c          Removed C file that contains depreciated function
            

            nx_arp.h                                Added logic for multihome support.
            nx_ip.h                                 Added logic for multihome support, added static 
                                                    routing support, and added IGMPv2 support.
            nx_igmp.h                               Added logic for multihome support, and added
                                                    IGMPv2 support.
            nx_packet.h                             Added declaration for new API service 
                                                    nx_packet_data_extract_offset().
            nx_tcp.h                                Added or renamed internal function prototypes.
            nx_udp.h                                Added internal function prototypes.
            nx_user.h                               Added options for enabling static routing, loopback 
                                                    interface, IGMPv2 support and multiple physical 
                                                    interface support.
            nx_arp_dynamic_entry_set.c              Added logic for multihome support.
            nx_arp_gratuitous_send.c                Added logic for multihome support.
            nx_arp_packet_receive.c                 Added logic for multihome support.
            nx_arp_packet_send.c                    Added logic for multihome support.
            nx_arp_periodic_update.c                Added logic for multihome support.
            nx_icmp_packet_process.c                Added logic for multihome support.
            nx_icmp_ping.c                          Added logic for multihome support.
            nx_igmp_enable.c                        Added IGMPv2 support.
            nx_igmp_multicast_check.c               Added logic for multihome support.
            nx_igmp_multicast_join.c                Added logic for multihome support.
            nx_igmp_multicast_leave.c               Added logic for multihome support, and added 
                                                    IGMPv2 support.
            nx_igmp_packet_process.c                Added logic for multihome support, and added
                                                    IGMPv2 support.
            nx_igmp_periodic_processing.c           Added logic for multihome support, and added
                                                    IGMPv2 support.
            nx_ip_address_get.c                     Added logic for multihome support, and added trace
                                                    event(s).
            nx_ip_address_set.c                     Added logic for multihome support.
            nx_ip_create.c                          Added logic for multihome support, and added support
                                                    for loopback interface.
            nx_ip_delete.c                          Added logic for multihome support.
            nx_ip_driver_direct_command.c           Added logic for multihome support.
            nx_ip_forwarding_disable.c              Added logic for NAT support.
            nx_ip_forwarding_enable.c               Added logic for NAT support.
            nx_ip_fragment_packet.c                 Added logic for multihome support.
            nx_ip_gateway_address_set.c             Added logic for multihome support, removed C file includes.
            nx_ip_packet_receive.c                  Added logic for multihome support, added check for 
                                                    invalid IP header Total Length field, modified raw IP 
                                                    packet handling such that packets are forwarded to the 
                                                    raw IP handler preferentially (before TCP, UDP, IGMP and 
                                                    ICMP handlers), if raw IP is enabled, added logic for NAT
                                                    support.
            nx_ip_packet_send.c                     Added logic for multihome support, added static 
                                                    routing support, and added loopback interface support.
            nx_ip_raw_packet_processing.c           Corrected an imbalanced TX_DISABLE/TX_RESTORE macro pair.
            nx_ip_raw_packet_send.c                 Added logic for multihome support.
            nx_ip_route_find.c                      Added function for IP internal routing table operation.
            nx_ip_status_check.c                    Added logic for multihome support, and added trace
                                                    event(s).
            nx_ip_thread_entry.c                    Added logic for multihome support.
            nx_packet_copy.c                        Added logic for multihome support.
            nx_ram_network_driver.c                 Added logic for multihome support.
            nx_rarp_enable.c                        Added logic for multihome support.
            nx_rarp_packet_receive.c                Added logic for multihome support, added check to call 
                                                    the address change callback if IP address is received.
            nx_rarp_packet_send.c                   Added logic for multihome support.
            nx_system_initialize.c                  Removed trace C file includes.
            nx_tcp_client_socket_connect.c          Added logic for multihome support, initialize the MSS 
                                                    based on interface MTU.
            nx_tcp_fast_periodic_processing.c       Added check for zero window size before re-transmitting 
                                                    packets.
            nx_tcp_no_connection_reset.c            Added logic for multihome support, removed step of 
                                                    assigning ACK from sequence number of an incoming RST packet.
            nx_tcp_mss_option_get.c                 Fixed a bug where the option length was computed incorrectly;
                                                    Added TCP Window Scaling feature.
            nx_tcp_packet_process.c                 Added logic for multihome support, added check for LAND 
                                                    attack (a form of Denial of Service attack).
                                                    Added TCP Window Scaling feature.
            nx_tcp_packet_send_ack.c                Added logic for multihome support.
                                                    Modified to support TCP Window Scaling feature.
            nx_tcp_packet_send_fin.c                Added logic for multihome support.
                                                    Modified to support TCP Window Scaling feature.
            nx_tcp_packet_send_rst.c                Added logic for multihome support.
                                                    Modified to support TCP Window Scaling feature.
            nx_tcp_packet_send_syn.c                Added logic for multihome support.
                                                    Modified to support TCP Window Scaling feature.
            nx_tcp_socket_bytes_available.c         Removed deprecated #define for TCP source info enabled, 
                                                    removed conditional stub function definition if not enabled.
            nx_tcp_socket_create.c                  Implement congestion window estimation.
                                                    Modified to support TCP Window Scaling feature.
            nx_tcp_socket_info_get.c                Removed C file includes and deprecated define for TCP 
                                                    source info enable.
            nx_tcp_socket_mss_set.c                 Added logic for multihome support.
            nx_tcp_socket_peer_info_get.c           Removed 'stub' function if the deprecated define for TCP 
                                                    source info not enabled.
            nx_tcp_socket_receive.c                 Made a correction in determining if the TCP socket is 
                                                    still in active state.
                                                    Also modified the logic to always check the TCP socket receive queue 
                                                    regardless of the TCP socket state and if there is one or more packets
                                                    on the queue, to retrieve the packet.
            nx_tcp_socket_send.c                    Added logic for multihome support.
            nx_tcp_socket_state_ack_check.c         Modify how the transmit window size is set as per the 
                                                    Congestion Avoidance/Slow Start algorithm.
                                                    Modified to support TCP Window Scaling feature.
            nx_tcp_socket_state_data_check.c        Substantial modifications for detecting packet overlap, 
                                                    receiving out of order packets, and general streamlining.
                                                    Modified to support TCP Window Scaling feature.
            nx_tcp_socket_state_syn_received.c      Modified to support TCP Window Scaling feature.
            nx_tcp_socket_state_syn_sent.c          Modified to support TCP Window Scaling feature.
            nx_trace_event_insert.c                 Removed a stub function and a deprecated define for 
                                                    enabling Trace source.
            nx_trace_event_update.c                 Removed a stub function and a deprecated define for 
                                                    enabling Trace source.
            nx_trace_object_register.c              Removed a stub function and a deprecated define for 
                                                    enabling Trace source.
            nx_trace_object_unregister.c            Removed a stub function and a deprecated define for 
                                                    enabling Trace source.
            nx_udp_socket_bytes_available.c         Removed a stub function and a deprecated define for 
                                                    enabling UDP source.
            nx_udp_socket_create.c                  Added logic for multihome support.
            nx_udp_socket_info_get.c                Removed C file includes and a deprecated define for 
                                                    enabling UDP source.
            nx_udp_socket_send.c                    Added logic for multihome support.
            nxe_arp_gratuitous_send.c               Added check if ARP is enabled.
            nxe_igmp_multicast_join.c               Added check if the primary interface is valid.
            nxe_tcp_socket_create.c                 Modified to support TCP Window Scaling feature.
            nxe_ip_gateway_address_set.c            Removed some restraints on callers to allow call from 
                                                    initialization, removed C file includes. 
            nxe_packet_allocate.c                   Added check for invalid packet type.
            nxe_tcp_socket_bytes_available.c        Removed deprecated #define for TCP source info enabled, 
                                                    removed conditional stub function definition if not 
                                                    enabled.
            nxe_tcp_socket_info_get.c               Removed C file includes and deprecated define for TCP 
                                                    source info enable.
            nxe_tcp_socket_peer_info_get.c          Removed 'stub' function if the deprecated define for 
                                                    TCP source info not enabled.
            nxe_udp_socket_info_get.c               Removed C file includes and a deprecated define for 
                                                    enabling UDP source.
            nx_igmp_multicast_interface_join.c      Added new API for this release.
            nx_ip_interface_address_get.c           Added new API for this release.
            nx_ip_interface_address_set.c           Added new API for this release.
            nx_ip_interface_attach.c                Added new API for this release.
            nx_ip_interface_info_get.c              Added new API for this release.
            nx_ip_interface_status_check.c          Added new API for this release.
            nx_ip_raw_packet_interface_send.c       Added new API for this release.
            nx_packet_data_extract_offset.c         Added new API for this release.
            nx_tcp_socket_bytes_available.c         Added new API for this release.
            nx_tcp_socket_peer_info_get.c           Added new API for this release.
            nx_tcp_socket_window_update_notify.c    Added new API for this release.
            nx_udp_packet_info_extract.c            Added new API for this release.
            nx_udp_socket_bytes_available.c         Added new API for this release.
            nx_udp_socket_interface_send.c          Added new API for this release.
            nxe_igmp_multicast_interface_join.c     Added error checking for new API.
            nxe_ip_interface_address_get.c          Added error checking for new API.
            nxe_ip_interface_address_set.c          Added error checking for new API.
            nxe_ip_interface_attach.c               Added error checking for new API.
            nxe_ip_interface_info_get.c             Added error checking for new API.
            nxe_ip_interface_status_check.c         Added error checking for new API.
            nxe_ip_raw_packet_interface_send.c      Added error checking for new API.
            nxe_packet_data_extract_offset.c        Added error checking for new API.
            nxe_tcp_socket_bytes_available.c        Added error checking for new API.
            nxe_tcp_socket_peer_info_get.c          Added error checking for new API.
            nxe_tcp_socket_window_update_notify.c   Added error checking for new API.
            nxe_udp_packet_info_extract.c           Added error checking for new API.
            nxe_udp_socket_bytes_available.c        Added error checking for new API.
            nxe_udp_socket_interface_send.c         Added error checking for new API.
            nx*.h                                   Removed internal debug logic, since event trace
                                                    makes it obsolete.
            nx*.c                                   Removed internal debug logic, since event trace
                                                    makes it obsolete.
            nx_*_debug*.c                           Removed internal debug files, since event trace
                                                    makes it obsolete.
            nx*.h                                   Modified comment(s).
            nx*.c                                   Modified comment(s).

07/04/2009  NetX generic code version 5.2.  This release includes the following 
            modifications:

            nx_api.h                                Added new services, added function
                                                    prototypes, added TCP window update callback, 
                                                    and added logic for trace support.
            nx_ip.h                                 Added function prototypes.
            nx_tcp.h                                Added function prototypes.
            nx_udp.h                                Added function prototypes.
            nx_ip_gateway_address_set.c             Added logic to include static routing 
                                                    source code.
            nx_ip_packet_send.c                     Changed loopback path to use deferred 
                                                    received in order to reduce stack size, and
                                                    added support for static routing.
            nx_system_initialize.c                  Added logic to include trace source code.
            nx_tcp_checksum.c                       Optimized the checksum logic.
            nx_tcp_packet_send_rst.c                Added ACK bit to RST packet.
            nx_tcp_socket_info_get.c                Added logic to include additional information
                                                    source code.
            nx_tcp_socket_state_data_check.c        Optimized out-of-order data packet
                                                    processing.
            nx_tcp_socket_state_established.c       Added logic to release all threads
                                                    suspended trying to receive data when leaving 
                                                    the established state.
            nx_udp_socket_receive.c                 Optimized the checksum logic.
            nx_udp_socket_send.c                    Optimized the checksum logic.
            nx_udp_socket_info_get.c                Added logic to include additional information
                                                    source code.
            nxe_ip_gateway_address_set.c            Added logic to include static routing 
                                                    error checking source code.
            nxe_tcp_socket_info_get.c               Added logic to include additional information
                                                    error checking source code.
            nxe_udp_socket_info_get.c               Added logic to include additional information
                                                    error checking source code.
            nx_ip_static_route_add.c                New service, adding an IP static route entry.
            nx_ip_static_route_delete.c             New service, deleting an IP static route entry.
            nx_tcp_socket_bytes_available.c         New service, returns the amount of data
                                                    available for read in a given TCP socket. 
            nx_tcp_socket_peer_info_get.c           New service, returns peer's IP address and 
                                                    the port number for a given TCP socket.
            nx_tcp_socket_windows_update_notify.c   New service, registers callback for TCP window changes.
            nx_trace_event_insert.c                 New service for support of tracing NetX events.
            nx_trace_object_register.c              New service for support of tracing NetX events.
            nx_trace_object_unregister.c            New service for support of tracing NetX events.
            nx_trace_event_update.c                 New service for support of tracing NetX events.
            nx_udp_socket_bytes_available.c         New service, returns the amount of data
                                                    available for read in a given UDP socket.
            nxe_ip_static_route_add.c               Error checking for new service, adding an IP static route entry.
            nxe_ip_static_route_delete.c            Error checking for new service, deleting an IP static route entry.
            nxe_tcp_socket_bytes_available.c        Error checking for new service, returns the amount of data
                                                    available for read in a given TCP socket. 
            nxe_tcp_socket_peer_info_get.c          Error checking for new service, returns peer's IP address and 
                                                    the port number for a given TCP socket.
            nx_*.h                                  Added support for tracing NetX events.
            nx_*.c                                  Added support for tracing NetX events.
            nx*.h                                   Modified comment(s).
            nx*.c                                   Modified comment(s).

07/18/2007  NetX generic code version 5.1. This release includes the following 
            modifications:

            nx_api.h                                Changed UL to ULONG cast.
            nx_arp.h                                Changed UL to ULONG cast.
            nx_ip.h                                 Changed UL to ULONG cast.
            nx_packet.h                             Changed UL to ULONG cast.
            nx_rarp.h                               Changed UL to ULONG cast.
            nx_tcp.h                                Removed the SACK option from the end 
                                                    of TCP options, and changed UL to 
                                                    ULONG cast.
            nx_udp.h                                Changed UL to ULONG cast.
            nx_icmp_checksum_compute.c              Optimized the checksum logic.
            nx_icmp_packet_process.c                Removed ICMP header on echo response 
                                                    packet.
            nx_igmp_periodic_processing.c           Optimized the checksum logic.
            nx_ip_fragment_packet.c                 Optimized the checksum logic.
            nx_ip_packet_receive.c                  Optimized the checksum logic.
            nx_ip_packet_send.c                     Optimized the checksum logic.
            nx_ram_network_driver.c                 Changed UL to ULONG cast.
            nx_system_intialize.c                   Changed UL to ULONG cast.
            nx_tcp_checksum.c                       Optimized the checksum logic.
            nx_tcp_client_bind_cleanup.c            Added logic to remove the thread 
                                                    from the socket owning the port.
            nx_tcp_client_socket_bind.c             Moved the port already bound check 
                                                    to before the new port assignment, 
                                                    and added logic to remember the 
                                                    socket owning the port for
                                                    cleanup. 
            nx_tcp_client_socket_connect.c          Changed UL to ULONG cast.
            nx_tcp_packet_process.c                 Added check for duplicate connection 
                                                    requests, added logic to keep most 
                                                    recent connection requests, added 
                                                    logic to not send RST when an unknown 
                                                    RST is received, and added timeout for 
                                                    server SYN+ACK transmission.
            nx_tcp_server_socket_accept.c           Changed UL to ULONG cast, and 
                                                    added timeout for server SYN+ACK 
                                                    transmission.
            nx_tcp_server_socket_unlisten.c         Cleared the queue count when releasing 
                                                    all packets.
            nx_tcp_socket_state_ack_check.c         Added check for transmit complete before 
                                                    dereferencing the TCP header information, 
                                                    added logic to open up our side of the 
                                                    transmit window, and added logic to check 
                                                    for driver completion prior to actually 
                                                    releasing an ACKed packet.
            nx_udp_bind_cleanup.c                   Added logic to remove the thread from 
                                                    the socket owning the port.
            nx_udp_socket_bind.c                    Moved the port already bound check 
                                                    to before the new port assignment, 
                                                    added mutex release code in bind 
                                                    suspension path, and added logic to 
                                                    remember the socket owning the port 
                                                    for cleanup.
            nx_udp_socket_receive.c                 Optimized the checksum logic.
            nx_udp_socket_send.c                    Optimized the checksum logic.
            nx*.h                                   Modified comment(s).
            nx*.c                                   Modified comment(s).

12/12/2005  Initial NetX generic code version 5.0. This release includes the 
            the following fixes from generic code version 2.1d:

            nx_api.h                                Move "nx_tcp_socket_name" to after 
                                                    the ID so the debugger will be able 
                                                    to display it properly.
            nx_tcp_socket_disconnect.c              Cleared connect suspension on 
                                                    disconnect call.
            nx_tcp_connect_cleanup.c                Cleared connect suspension on 
                                                    disconnect call.
            nx_ip.h                                 Removed duplicate entries for 
                                                    nx_ip_status_check prototype.
            nx_t*.c                                 Added logic to clear timeout in all ACK 
                                                    from FIN send states.


Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com

