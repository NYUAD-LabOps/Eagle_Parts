                        Express Logic's NetX Duo



For installation and usage please see the readme_netx.txt file included
in your distribution. For port-specific version information, please refer
to the bottom of readme_netx.txt. The NetX Duo generic code version
information is as follows:

07/15/2018  NetX Duo generic code version 5.11. This release includes the
            following major features:

        Files are modified to fix custom MSS value:
            nx_api.h
            nx_tcp_packet_process.c
            nx_tcp_packet_send_syn.c
            nx_tcp_server_socket_relisten.c
            nx_tcp_socket_mss_get.c
            nx_tcp_socket_mss_set.c
            nx_tcp_socket_send_internal.c

        Files are modified to improve packet length verification:
            nx_icmpv6_process_echo_reply.c
            nx_icmpv6_process_echo_request.c
            nx_icmpv6_process_na.c
            nx_icmpv6_process_packet_too_big.c
            nx_icmpv6_validate_options.c
            nx_ip_dispatch_process.c
            nx_ipv4_packet_receive.c
            nx_ipv6_packet_receive.c
            nx_ipv6_process_hop_by_hop_option.c
            nx_tcp_packet_process.c

        Files are modified to support Thread feature:
            nx_api.h
            nx_ipv6_process_hop_by_hop_option.c
            nx_ipv6_util.c
            nx_packet_allocate.c

        Files are modified to check interface for router lookup:
            nx_icmpv6_process_redirect.c
            nx_ipv6.h
            nx_ipv6_packet_send.c
            nxd_ipv6_router_lookup.c

        Files are modified to fix the logic to update the destination cache:
            nx_icmpv6.h
            nx_icmpv6_dest_table_add.c
            nx_icmpv6_dest_table_find.c
            nx_icmpv6_process_packet_too_big.c
            nx_icmpv6_process_ra.c
            nx_icmpv6_process_redirect.c
            nx_icmpv6_send_queued_packets.c
            nx_ipv6_packet_send.c

        Files are modified to support specified source interface for IPv6:
            nx_icmp_ping6.c
            nx_icmpv6_send_error_message.c
            nx_icmpv6_send_rs.c
            nx_ipv6.h
            nxd_ipv6_interface_find.c
            nxd_tcp_client_socket_connect.c
            nxd_udp_socket_send.c

        Files are modified to improve internal logic:
            nx_api.h
            nx_icmpv6_process_echo_request.c
            nx_icmpv6_process_na.c
            nx_icmpv6_process_ra.c
            nx_icmpv6_send_error_message.c
            nx_ip_create.c
            nx_ip_dispatch_process.c
            nx_ip_fragment_assembly.c
            nx_ip_fragment_timeout_check.c
            nx_ip_header_add.c
            nx_ip_interface_attach.c
            nx_ip_interface_physical_address_set.c
            nx_ip_max_payload_size_find.c
            nx_ipv4_option_process.c
            nx_ipv6_header_add.c
            nx_ipv6_option_error.c
            nx_ipv6_packet_copy.c
            nx_ipv6_packet_send.c
            nx_ipv6_util.c
            nx_packet_allocate.c
            nx_packet_release.c
            nx_packet_transmit_release.c
            nx_ram_network_driver.c
            nx_tcp_client_socket_bind.c
            nx_tcp_packet_process.c
            nx_tcp_packet_send_control.c
            nx_tcp_packet_send_syn.c
            nx_tcp_server_socket_accept.c
            nx_tcp_socket_disconnect.c
            nx_tcp_socket_retransmit.c
            nx_tcp_socket_send_internal.c
            nx_tcp_socket_state_ack_check.c
            nx_tcp_socket_state_data_check.c
            nx_udp_socket_bind.c
            nx_udp_socket_receive.c
            nxd_ipv6_default_router_delete.c
            nxd_ipv6_interface_find.c
            nxd_ipv6_search_onlink.c
            nxd_tcp_client_socket_connect.c
            nxd_udp_socket_send.c

        Files are modified to merge IPv6 loopback address with normal IPv6 address:
            nx_api.h
            nx_ip_create.c
            nx_ip_max_payload_size_find.c
            nxd_ipv6_disable.c
            nxde_icmp_source_ping.c
            nxde_ip_raw_packet_source_send.c
            nxde_ipv6_address_get.c
            nxde_udp_socket_source_send.c

        Files are modified to use macro to bring in symbol: _tx_thread_system_state:
            nxe_ip_forwarding_disable.c
            nxe_ip_forwarding_enable.c
            nxe_packet_pool_info_get.c
            nxe_tcp_enable.c
            nxe_tcp_socket_receive_queue_max_set.c
            nxe_udp_enable.c
            nxe_udp_info_get.c
            nxe_udp_socket_checksum_disable.c
            nxe_udp_socket_checksum_enable.c
            nxe_udp_socket_info_get.c

        Files are modified to remove unreachable code:
            nx_tcp_socket_receive.c
            nx_ipv6_packet_send.c

        Files are modified to be compatible with ThreadX 5.8 or later:
            nx_api.h
            nx_icmp_cleanup.c
            nx_icmpv4.h
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
            nx_icmpv4_packet_process.c
            nx_ip_create.c
            nx_ip_forwarding_disable.c
            nx_ip_forwarding_enable.c
            nx_ip_fragment_enable.c
            nx_ip_max_payload_size_find.c
            nx_ip_raw_packet_filter_set.c
            nx_ip_raw_packet_receive.c
            nx_ip_static_route_add.c
            nx_ip_static_route_delete.c
            nx_packet_allocate.c
            nx_rarp_disable.c
            nx_rarp_enable.c
            nx_rarp_info_get.c
            nx_tcp.h
            nx_tcp_connect_cleanup.c
            nx_tcp_socket_block_cleanup.c
            nx_tcp_socket_packet_process.c
            nx_tcp_socket_receive_notify.c
            nx_tcp_socket_state_syn_sent.c
            nx_tcp_socket_send_internal.c
            nx_tcp_socket_window_update_notify_set.c
            nx_trace_object_unregister.c
            nx_trace_object_register.c
            nx_udp_info_get.c
            nx_udp_socket_checksum_disable.c
            nx_udp_socket_checksum_enable.c
            nx_udp_socket_info_get.c
            nx_udp_socket_port_get.c
            nxd_ipv6_address_change_notify.c
            nxd_ipv6_stateless_address_autoconfig_enable.c
            nxd_ipv6_stateless_address_autoconfig_disable.c
            nxd_udp_socket_send.c

        Files are modified to avoid NULL pointer access in trace logging:
            nx_ip_interface_info_get.c
            nx_ip_thread_entry.c
            nxd_ipv6_address_set.c
            nxd_udp_packet_info_extract.c

        Files are modified to fix the delay of initial router solicitation:
            nx_icmpv6.h
            nx_icmpv6_send_rs.c
            nx_user.h
            nxd_ipv6_enable.c
            nxd_ipv6_router_solicitation_check.c
            nxd_ipv6_stateless_address_autoconfig_enable.c

        Files are modified to move the destination and ND cache tables to IP structure:
            nx_api.h
            nx_icmpv6.h
            nx_icmpv6_DAD_clear_NDCache_entry.c
            nx_icmpv6_dest_table_add.c
            nx_icmpv6_dest_table_find.c
            nx_icmpv6_destination_table_periodic_update.c
            nx_icmpv6_packet_process.c
            nx_icmpv6_process_redirect.c
            nx_icmpv6_send_queued_packets.c
            nx_ip_thread_entry.c
            nx_ipv6_packet_send.c
            nx_invalidate_destination_entry.c
            nx_nd_cache.h
            nx_nd_cache_add.c
            nx_nd_cache_add_entry.c
            nx_nd_cache_delete_internal.c
            nx_nd_cache_fast_periodic_update.c
            nx_nd_cache_find_entry.c
            nx_nd_cache_find_entry_by_mac_addr.c
            nx_nd_cache_interface_entries_delete.c
            nx_nd_cache_slow_periodic_update.c
            nx_system_initialize.c
            nxd_icmp_enable.c
            nxd_ipv6_destination_table_find_next_hop.c
            nxd_ipv6_disable.c
            nxd_ipv6_prefix_router_timer_tick.c
            nxd_nd_cache_entry_delete.c
            nxd_nd_cache_hardware_address_find.c
            nxd_nd_cache_invalidate.c
            nxd_nd_cache_ip_address_find.c

        Files are modified to add support for disabling IPv4:
            demo_netx_duo_multihome_tcp.c
            demo_netx_duo_multihome_udp.c
            demo_netx_duo_tcp.c
            demo_netx_duo_udp.c
            nx_api.h
            nx_arp.h
            nx_arp_announce_send.c
            nx_arp_dynamic_entries_invalidate.c
            nx_arp_dynamic_entry_delete.c
            nx_arp_dynamic_entry_set.c
            nx_arp_enable.c
            nx_arp_entry_allocate.c
            nx_arp_entry_delete.c
            nx_arp_gratuitous_send.c
            nx_arp_hardware_address_find.c
            nx_arp_info_get.c
            nx_arp_initialize.c
            nx_arp_interface_entries_delete.c
            nx_arp_ip_address_find.c
            nx_arp_packet_deferred_receive.c
            nx_arp_packet_receive.c
            nx_arp_packet_send.c
            nx_arp_periodic_update.c
            nx_arp_probe_send.c
            nx_arp_queue_process.c
            nx_arp_queue_send.c
            nx_arp_static_entries_delete.c
            nx_arp_static_entry_create.c
            nx_arp_static_entry_delete.c
            nx_arp_static_entry_delete_internal.c
            nx_icmp.h
            nx_icmp_enable.c
            nx_icmp_interface_ping.c
            nx_icmp_packet_process.c
            nx_icmp_packet_receive.c
            nx_icmp_ping.c
            nx_icmp_queue_process.c
            nx_icmpv4.h
            nx_icmpv4_packet_process.c
            nx_icmpv4_process_echo_reply.c
            nx_icmpv4_process_echo_request.c
            nx_icmpv4_send_error_message.c
            nx_igmp.h
            nx_igmp_enable.c
            nx_igmp_info_get.c
            nx_igmp_loopback_disable.c
            nx_igmp_loopback_enable.c
            nx_igmp_multicast_check.c
            nx_igmp_multicast_interface_join.c
            nx_igmp_multicast_interface_join_internal.c
            nx_igmp_multicast_interface_leave.c
            nx_igmp_multicast_interface_leave_internal.c
            nx_igmp_multicast_join.c
            nx_igmp_multicast_leave.c
            nx_igmp_packet_process.c
            nx_igmp_packet_receive.c
            nx_igmp_periodic_processing.c
            nx_igmp_queue_process.c
            nx_ip.h
            nx_ip_address_change_notify.c
            nx_ip_address_get.c
            nx_ip_address_set.c
            nx_ip_create.c
            nx_ip_delete.c
            nx_ip_dispatch_process.c
            nx_ip_driver_packet_send.c
            nx_ip_forward_packet_process.c
            nx_ip_forwarding_disable.c
            nx_ip_forwarding_enable.c
            nx_ip_fragment_assembly.c
            nx_ip_fragment_forward_packet.c
            nx_ip_fragment_packet.c
            nx_ip_fragment_timeout_check.c
            nx_ip_gateway_address_clear.c
            nx_ip_gateway_address_get.c
            nx_ip_gateway_address_set.c
            nx_ip_header_add.c
            nx_ip_interface_address_get.c
            nx_ip_interface_address_set.c
            nx_ip_interface_attach.c
            nx_ip_interface_detach.c
            nx_ip_interface_info_get.c
            nx_ip_interface_status_check.c
            nx_ip_max_payload_size_find.c
            nx_ip_packet_receive.c
            nx_ip_packet_send.c
            nx_ip_raw_packet_send.c
            nx_ip_raw_packet_source_send.c
            nx_ip_route_find.c
            nx_ip_static_route_add.c
            nx_ip_static_route_delete.c
            nx_ip_thread_entry.c
            nx_ipv4.h
            nx_ipv4_multicast_interface_join.c
            nx_ipv4_multicast_interface_leave.c
            nx_ipv4_option_process.c
            nx_ipv4_packet_receive.c
            nx_packet_allocate.c
            nx_ram_network_driver.c
            nx_rarp.h
            nx_rarp_disable.c
            nx_rarp_enable.c
            nx_rarp_info_get.c
            nx_rarp_packet_deferred_receive.c
            nx_rarp_packet_receive.c
            nx_rarp_packet_send.c
            nx_rarp_periodic_update.c
            nx_rarp_queue_process.c
            nx_tcp_client_socket_connect.c
            nx_tcp_no_connection_reset.c
            nx_tcp_packet_process.c
            nx_tcp_packet_send_control.c
            nx_tcp_packet_send_syn.c
            nx_tcp_server_socket_relisten.c
            nx_tcp_server_socket_unaccept.c
            nx_tcp_socket_block_cleanup.c
            nx_tcp_socket_mss_set.c
            nx_tcp_socket_peer_info_get.c
            nx_tcp_socket_retransmit.c
            nx_tcp_socket_send_internal.c
            nx_tcp_socket_state_ack_check.c
            nx_udp_packet_info_extract.c
            nx_udp_packet_receive.c
            nx_udp_socket_receive.c
            nx_udp_socket_send.c
            nx_udp_source_extract.c
            nx_user.h
            nxd_icmp_enable.c
            nxd_icmp_ping.c
            nxd_icmp_source_ping.c
            nxd_ip_raw_packet_source_send.c
            nxd_tcp_client_socket_connect.c
            nxd_tcp_socket_peer_info_get.c
            nxd_udp_packet_info_extract.c
            nxd_udp_socket_send.c
            nxd_udp_socket_source_send.c
            nxd_udp_source_extract.c
            nxde_icmp_ping.c
            nxde_icmp_source_ping.c
            nxde_ip_raw_packet_send.c
            nxde_ip_raw_packet_source_send.c
            nxde_tcp_client_socket_connect.c
            nxde_udp_socket_send.c
            nxde_udp_socket_source_send.c
            nxe_arp_dynamic_entries_invalidate.c
            nxe_arp_dynamic_entry_set.c
            nxe_arp_enable.c
            nxe_arp_entry_delete.c
            nxe_arp_gratuitous_send.c
            nxe_arp_hardware_address_find.c
            nxe_arp_info_get.c
            nxe_arp_ip_address_find.c
            nxe_arp_static_entries_delete.c
            nxe_arp_static_entry_create.c
            nxe_arp_static_entry_delete.c
            nxe_icmp_enable.c
            nxe_icmp_ping.c
            nxe_igmp_enable.c
            nxe_igmp_info_get.c
            nxe_igmp_loopback_disable.c
            nxe_igmp_loopback_enable.c
            nxe_igmp_multicast_interface_join.c
            nxe_igmp_multicast_interface_leave.c
            nxe_igmp_multicast_join.c
            nxe_igmp_multicast_leave.c
            nxe_ip_address_change_notify.c
            nxe_ip_address_get.c
            nxe_ip_address_set.c
            nxe_ip_forwarding_disable.c
            nxe_ip_forwarding_enable.c
            nxe_ip_gateway_address_clear.c
            nxe_ip_gateway_address_get.c
            nxe_ip_gateway_address_set.c
            nxe_ip_interface_address_get.c
            nxe_ip_interface_address_set.c
            nxe_ip_interface_status_check.c
            nxe_ip_raw_packet_send.c
            nxe_ip_raw_packet_source_send.c
            nxe_ip_static_route_add.c
            nxe_ip_static_route_delete.c
            nxe_ipv4_multicast_interface_join.c
            nxe_ipv4_multicast_interface_leave.c
            nxe_rarp_disable.c
            nxe_rarp_enable.c
            nxe_rarp_info_get.c
            nxe_tcp_client_socket_connect.c
            nxe_tcp_socket_peer_info_get.c
            nxe_tcp_socket_send.c
            nxe_udp_packet_info_extract.c
            nxe_udp_socket_send.c
            nxe_udp_socket_source_send.c
            nxe_udp_source_extract.c

        Other modified files:

            nx_arp_packet_receive.c                           Added zero IP probe address check.
            nx_arp_periodic_update.c                          Improved retry counter check logic.
            nx_icmp_packet_receive.c                          Added logic for checking address of ICMP packet.
            nx_icmpv6_process_echo_request.c                  Corrected the logic for processing multicast echo.
            nx_igmp.h                                         Declared nx_igmp_interface_report_send function.
            nx_igmp_multicast_interface_leave_internal.c      Optimized to use the report_send function.
            nx_igmp_packet_process.c                          Fixed history information.
            nx_igmp_periodic_processing.c                     Optimized to use the report_send function.
            nx_ip_create.c                                    Fixed address index. The value is cleared by nxd_ipv6_disable.
            nx_ip_forward_packet_process.c                    Added check for class D address.
                                                                Corrected the logic for appending the overflowing data to the new packet.
            nx_ip_interface_detach.c                          Optimized the logic for invalidating destination entries when the router is invalid.
            nx_ipv6_fragment_process.c                        Fixed NULL pointer access.
            nx_nd_cache.h                                     Cleaned up internal functions.
            nx_nd_cache_clear_IsRouter_field.c                Removed unused function.
            nx_nd_cache_init.c                                Removed unused function.
            nx_packet.h                                       Adjusted the packet data to fill the specified header.
            nx_packet_data_append.c                           Fixed NULL pointer access.
            nx_tcp_client_socket_unbind.c                     Fixed a bug where packets in the receive queue may not be properly released.
            nx_tcp_packet_process.c                           Fixed the packet leak.
            nx_tcp_server_socket_accept.c                     Fixed an issue where SYN is sent multiple times.
            nx_tcp_socket_retransmit.c                        Fixed compiler error when NX_DISABLE_TCP_TX_CHECKSUM is defined.
            nx_tcp_socket_send_internal.c                     Fixed window size when receiving duplicated ACKs.
                                                                Fixed empty packet.
            nx_tcp_socket_state_ack_check.c                   Fixed ACK number check when zero window probe is ACKed.
                                                                Fixed the condition to update window size.
            nx_tcp_socket_state_transmit_check.c              Fixed window size when receiving duplicated ACKs.
            nx_user.h                                         Added symbol for checking address of ICMP packet.
            nxd_ipv6_default_router_delete.c                  Removed one line function _nx_nd_cache_clear_IsRouter_field().
            nxd_ipv6_enable.c                                 Fixed address index. The value is cleared by nxd_ipv6_disable.
            nxd_ipv6_prefix_router_timer_tick.c               Removed one line function _nx_nd_cache_clear_IsRouter_field().
                                                                Optimized the logic for invalidating destination entries when the router is invalid.
            nxd_nd_cache_invalidate.c                         Simplified the logic for invalidating all ND cache entries.
            nxd_nd_cache_invalidate_internal.c                Removed unused function.
            nxd_udp_socket_send.c                             Fixed compiler error when NX_DISABLE_UDP_TX_CHECKSUM is defined.
            nxe_ip_create.c                                   Modified invalid IP address check.
            nxe_ip_interface_attach.c                         Modified invalid IP address check.

        File created:
            nx_igmp_interface_report_send.c                   Created internal function for sending join and leave reports.
            nx_packet_data_adjust.c                           Adjusted the packet data to fill the specified header.


05/10/2016  NetX Duo generic code version 5.10. This release includes the
            following major features:

        Files are modified to add an argument to the parameter list of _nx_icmpv6_send_ns:
            nx_icmpv6.h
            nx_icmpv6_perform_DAD.c
            nx_icmpv6_send_ns.c
            nx_ip_thread_entry.c
            nx_ipv6_packet_send.c
            nx_nd_cache_fast_periodic_update.c

        Files are modified to remove unused stub functions for trace:
            nx_api.h
            nx_trace_event_insert.c
            nx_trace_event_update.c
            nx_trace_object_register.c
            nx_trace_object_unregister.c

        Files are modified to fix IPv6 router type:
            nx_api.h
            nx_icmpv6_process_ra.c
            nx_icmpv6_process_redirect.c
            nx_ip.h
            nxd_ipv6_default_router_add.c
            nxd_ipv6_default_router_entry_get.c

        Files are added or modified to avoid recursive call:
            nx_icmpv6_send_ns.c
            nx_ip_dispatch_process.c
            nx_ipv6_header_add.c
            nx_ipv6_packet_send.c
            nx_ipv6_process_fragment_option.c

        Files are added or modified to remove unused IP pointer parameter:
            nx_api.h
            nx_icmpv6.h
            nx_icmpv6_destination_table_periodic_update.c
            nx_ip_thread_entry.c
            nx_nd_cache.h
            nx_nd_cache_add_entry.c
            nx_nd_cache_delete_internal.c
            nx_nd_cache_fast_periodic_update.c
            nx_nd_cache_interface_entries_delete.c
            nxd_ipv6_disable.c
            nxd_nd_cache_entry_delete.c
            nxd_nd_cache_invalidate.c
            nxd_nd_cache_invalidate_internal.c

        Files are added or modified to optimized the logic for IP address conflict detection:
            nx_api.h
            nx_arp.h
            nx_arp_announce_send.c
            nx_arp_gratuitous_send.c
            nx_arp_packet_receive.c
            nx_arp_probe_send.c

        Files are modified to pass PC-Lint check:
            nx_api.h
            nx_icmpv4.h
            nx_icmpv6.h
            nx_ip_create.c
            nx_ipv6.h
            nx_nd_cache.h
            nx_nd_cache_init.c

        Files are modified to support ASSERT macro:
            nx_arp_packet_send.c
            nx_icmpv6_dest_table_find.c
            nx_icmpv6_send_queued_packets.c
            nx_ip_checksum_compute.c
            nxd_ipv6_router_lookup.c
            nxd_tcp_client_socket_connect.c

        Files are modified to optimized the logic for TCP segment processing:
            nx_tcp_socket_packet_process.c
            nx_tcp_socket_state_ack_check.c
            nx_tcp_socket_state_syn_received.c
            nx_tcp_socket_state_syn_sent.c

        Files are modified to remove unreachable code and deprecated functions:
            nx_api.h
            nx_arp.h
            nx_arp_entry_allocate.c
            nx_icmp.h
            nx_icmpv4.h
            nx_icmpv6.h
            nx_icmpv6_process_na.c
            nx_icmpv6_process_ns.c
            nx_icmpv6_process_ra.c
            nx_icmpv6_process_redirect.c
            nx_icmpv6_send_queued_packets.c
            nx_igmp.h
            nx_ipv4.h
            nx_ipv6.h
            nx_ipv6_fragment_process.c
            nx_ip_interface_detach.c
            nx_nd_cache_find_entry_by_mac_addr.c
            nx_packet.h
            nx_tcp.h
            nx_tcp_client_socket_bind.c
            nx_tcp_packet_process.c
            nx_tcp_socket_send_internal.c
            nx_tcp_socket_state_ack_check.c
            nx_tcp_socket_state_data_check.c
            nx_tcp_socket_state_fin_wait1.c
            nx_tcp_socket_state_syn_sent.c
            nx_udp.h
            nx_udp_socket_bind.c
            nxd_ipv6_address_set.c
            nxd_ipv6_router_lookup.c
            nxd_ipv6_raw_packet_send_internal.c
            nxd_tcp_client_socket_connect.c
            nxde_udp_socket_send.c
            nxde_icmp_source_ping.c

        Files are modified to optimize the logic of checksum calculation:
            nx_icmp_interface_ping.c
            nx_icmp_interface_ping6.c
            nx_icmpv4_packet_process.c
            nx_icmpv4_process_echo_request.c
            nx_icmpv4_send_error_message.c
            nx_icmpv6_packet_process.c
            nx_icmpv6_process_echo_request.c
            nx_icmpv6_process_ns.c
            nx_icmpv6_send_error_message.c
            nx_icmpv6_send_ns.c
            nx_icmpv6_send_rs.c
            nx_ip_checksum_compute.c
            nx_ip_fragment_packet.c
            nx_ip_header_add.c
            nx_ipv4_packet_receive.c
            nx_tcp_packet_process.c
            nx_tcp_packet_send_control.c
            nx_tcp_socket_send_internal.c
            nx_udp_socket_receive.c
            nxd_udp_socket_send.c

        Files are modified to protect ND process in _nx_icmpv6_packet_process:
            nx_icmpv6_process_na.c
            nx_icmpv6_process_ns.c
            nx_icmpv6_process_ra.c
            nx_icmpv6_process_redirect.c

        Files are modified to avoid static analysis error report:
            nx_ipv6_fragment_process.c
            nxd_ipv6_address_set.c
            nxd_ipv6_default_router_entry_get.c
            nxd_ipv6_interface_find.c


        Other modified files:
            nx_api.h                                         Listed APIs by alphabetical order.
                                                               Added return status NX_CONTINUE.
                                                               Fixed typo of deprecated symbols.
            nx_arp_entry_allocate.c                          Fixed a bug that is_static of arp entry was not set.
            nx_arp_periodic_update.c                         Checked ARP expiration when NX_ARP_EXPIRATION_RATE is not zero.
                                                               Optimized the logic of updating ARP list.
            nx_arp_static_entries_delete.c                   Optimized the logic.
            nx_icmp_interface_ping6.c                        Optimized the logic due to NX_ICMPV6_ECHO is modified.
            nx_icmpv4_process_echo_reply.c                   Optimized the logic due to NX_ICMPV4_ECHO is modified.
            nx_icmpv6_destination_table_periodic_update.c    Optimized the code.
            nx_icmpv6_process_echo_reply.c                   Optimized the logic due to NX_ICMPV6_ECHO is modified.
            nx_icmpv6_process_ra.c                           Fixed a bug that is_router of ND entry was not set.
            nx_icmpv6_process_redirect.c                     Optimized the logic.
                                                               The destination table is not updated when packet is invalid.
            nx_icmpv6_send_ns.c                              Verified interface before is was used.
            nx_icmpv6_send_queued_packets.c                  Optimized the logic for fragmentation checking.
            nx_icmpv6_validate_neighbor_message.c            Fixed type check for destination address
                                                               when source address is unspecified.
            nx_igmp_multicast_interface_leave_internal       Fixed the bug for adding packet debug information.
            nx_igmp_packet_process                           Added support for packet chaining.
                                                               Compute the checksum over all IGMP data, not just the header.
                                                               Modified the logic for checking packet length.
            nx_igmp_periodic_processing                      Fixed the bug for adding packet debug information.
            nx_ipv4.h                                        Avoided redundant definition of fragmentation symbols.
            nx_ip_driver_packet_send.c                       Optimized the logic for fragmentation checking.
            nx_ip_fast_periodic_timer_entry.c                Set function _nx_ip_fast_periodic_timer_entry to static.
            nx_ip_forward_packet_process.c                   Fixed the bug for processing fragment bit.
            nx_ip_interface_detach.c                         Checked interface status before processing.
            nx_ip_route_find.c                               Fixed a bug that destination address is one of
                                                               the local interface addresses.
            nx_ipv4_option_process.c                         Optimized the code.
            nx_ipv4_packet_receive.c                         Adjusted processing order to make sure interface has IP address before forwarding.
            nx_ipv6_fragment_process.c                       Cleared reserved field in fragment option.
            nx_ipv6_option_error.c                           Optimized the logic for default case of switch.
            nx_ipv6_packet_send.c                            Optimized the logic for fragmentation checking.
                                                               Removed unnecessary check.
            nx_ipv6_perform_min_path_MTU_discovery.c         Moved the functionality into nx_icmpv6_destination_table_periodic_update.c
            nx_packet_data_extract_offset.c                  Removed duplicated for zero packet length.
            nx_system_initialize.c                           Make sure this service cannot invoked more than once.
                                                               Created destination table MUTEX.
            nx_tcp.h                                         Cleaned up the logic to get SYN packet size.
            nx_user.h                                        Added NX_DISABLE_ICMPV4_ERROR_MESSAGE configuration option
            nx_tcp_packet_process.c                          Fixed check for multicast source address.
            nx_tcp_socket_delete.c                           Fixed socket state check.
            nx_tcp_socket_disconnect.c                       Optimized the logic for checking wait_option.
            nx_tcp_socket_receive.c                          Suspended the send request when the connection is in progress.
            nx_tcp_socket_retransmit.c                       Fixed initial CWND value for fast recovery.
            nx_tcp_socket_send_internal.c                    Fixed a bug that empty segment was sent when data append failed.
                                                               Fixed a bug of endless loop in packet queue traverse.
                                                               Fixed the alignment of chained packet.
                                                               Suspended the send request when the connection is in progress.
            nx_tcp_socket_state_ack_check.c                  Fixed the calculation of TCP payload when packet
                                                               was not released by driver.
                                                               Fixed the check for immediately retransmission.
            nx_tcp_socket_state_data_check.c                 Fixed NULL pointer access.
            nx_tcp_socket_state_syn_received.c               Optimized the logic for checking acknowledgment number.
            nxd_icmp_ping.c                                  Removed duplicated error check.
            nxd_icmp_source_ping.c                           Removed duplicated error check.
            nxd_ipv6_disable.c                               Deleted ND cache added to current IP only.
                                                               Protected ND cache process by mutex.
            nxd_ipv6_interface_find.c                        Fixed a bug that destination address is one of
                                                               the local IPv6 addresses.
            nxd_tcp_client_socket_connect.c                  Cleaned up the logic to get SYN packet size.
            nxde_ip_raw_packet_send.c                        Removed unnecessary check. The return value of
                                                               _nxd_ip_raw_packet_source_send is always NX_SUCCESS.
            nxe_ip_raw_packet_source_send.c                  Removed unnecessary check. The return value of
                                                               _nx_ip_raw_packet_source_send is always NX_SUCCESS.


02/22/2016  NetX Duo generic code version 5.9. This release includes the
            following major features:

        Files are modified to fix compiler warnings:
            demo_netx_duo_multihome_tcp.c
            demo_netx_duo_multihome_udp.c
            demo_netx_duo_tcp.c
            demo_netx_duo_udp.c
            nx_api.h
            nx_icmpv4_packet_process.c
            nx_icmpv6_DAD_failure.c
            nx_icmpv6_dest_table_add.c
            nx_icmpv6_dest_table_find.c
            nx_icmpv6_destination_table_periodic_update.c
            nx_icmpv6_packet_process.c
            nx_icmpv6_process_echo_reply.c
            nx_icmpv6_process_echo_request.c
            nx_icmpv6_process_na.c
            nx_icmpv6_process_ns.c
            nx_icmpv6_process_ra.c
            nx_icmpv6_process_redirect.c
            nx_icmpv6_send_error_message.c
            nx_icmpv6_send_ns.c
            nx_icmpv6_send_rs.c
            nx_ip_auxiliary_packet_pool_set.c
            nx_ip_checksum_compute.c
            nx_ip_dispatch_process.c
            nx_ip_driver_deferred_enable.c
            nx_ip_driver_deferred_receive.c
            nx_ip_driver_packet_send.c
            nx_ip_forward_packet_process.c
            nx_ip_fragment_assembly.c
            nx_ip_fragment_disable.c
            nx_ip_fragment_enable.c
            nx_ip_interface_capability_get.c
            nx_ip_interface_capability_set.c
            nx_ip_max_payload_size_find.c
            nx_ip_packet_checksum_compute.c
            nx_ip_packet_send.c
            nx_ip_raw_packet_filter_set.c
            nx_ip_raw_packet_processing.c
            nx_ip_static_route_add.c
            nx_ip_static_route_delete.c
            nx_ipv6_fragment_process.c
            nx_ipv6_option_error.c
            nx_ipv6_packet_send.c
            nx_ipv6_process_fragment_option.c
            nx_ipv6_process_hop_by_hop_option.c
            nx_ipv6_process_routing_option.c
            nx_ipv6_util.c
            nx_nd_cache_delete_internal.c
            nx_packet_copy.c
            nx_packet_data_append.c
            nx_packet_pool_low_watermark_set.c
            nx_tcp_cleanup_deferred.c
            nx_tcp_periodic_processing.c
            nx_tcp_socket_disconnect_complete_notify.c
            nx_tcp_socket_establish_notify.c
            nx_tcp_socket_queue_depth_notify_set.c
            nx_tcp_socket_receive_queue_max_set.c
            nx_tcp_socket_timed_wait_callback.c
            nx_udp_socket_receive.c
            nxd_icmpv6_ra_flag_callback_set.c
            nxd_ipv6_address_change_notify.c
            nxd_ipv6_address_delete.c
            nxd_ipv6_address_get.c
            nxd_ipv6_address_set.c
            nxd_ipv6_default_router_add.c
            nxd_ipv6_default_router_delete.c
            nxd_ipv6_default_router_entry_get.c
            nxd_ipv6_default_router_get.c
            nxd_ipv6_default_router_number_of_entries_get.c
            nxd_ipv6_disable.c
            nxd_ipv6_enable.c
            nxd_ipv6_multicast_interface_join.c
            nxd_ipv6_multicast_interface_leave.c
            nxd_ipv6_stateless_address_autoconfig_disable.c
            nxd_ipv6_stateless_address_autoconfig_enable.c
            nxd_nd_cache_entry_delete.c
            nxd_nd_cache_entry_set.c
            nxd_nd_cache_hardware_address_find.c
            nxd_nd_cache_invalidate.c
            nxd_nd_cache_invalidate_internal.c
            nxd_nd_cache_ip_address_find.c
            nxd_udp_socket_send.c
            nxde_icmpv6_ra_flag_callback_set.c
            nxde_ipv6_address_change_notify.c
            nxde_ipv6_address_delete.c
            nxde_ipv6_address_get.c
            nxde_ipv6_address_set.c
            nxde_ipv6_default_router_add.c
            nxde_ipv6_default_router_delete.c
            nxde_ipv6_default_router_entry_get.c
            nxde_ipv6_default_router_get.c
            nxde_ipv6_default_router_number_of_entries_get.c
            nxde_ipv6_disable.c
            nxde_ipv6_enable.c
            nxde_ipv6_multicast_interface_join.c
            nxde_ipv6_multicast_interface_leave.c
            nxde_ipv6_stateless_address_autoconfig_disable.c
            nxde_ipv6_stateless_address_autoconfig_enable.c
            nxde_nd_cache_entry_delete.c
            nxde_nd_cache_entry_set.c
            nxde_nd_cache_hardware_address_find.c
            nxde_nd_cache_invalidate.c
            nxde_nd_cache_ip_address_find.c
            nxe_ip_auxiliary_packet_pool_set.c
            nxe_ip_interface_capability_get.c
            nxe_ip_interface_capability_set.c
            nxe_ip_raw_packet_filter_set.c
            nxe_ip_static_route_add.c
            nxe_ip_static_route_delete.c
            nxe_packet_pool_low_watermark_set.c
            nxe_tcp_socket_disconnect_complete_notify.c
            nxe_tcp_socket_establish_notify.c
            nxe_tcp_socket_queue_depth_notify_set.c
            nxe_tcp_socket_receive_queue_max_set.c
            nxe_tcp_socket_timed_wait_callback.c

        Files are modified to return NX_NOT_SUPPORTED when related compiler option is not enabled:
            nx_api.h
            nx_icmp.h
            nx_icmpv6.h
            nx_ipv6.h
            nx_nd_cache.h
            nx_packet.h
            nx_tcp.h
            nx_tcp_socket_disconnect_complete_notify.c
            nx_tcp_socket_establish_notify.c
            nx_tcp_socket_queue_depth_notify_set.c
            nx_tcp_socket_timed_wait_callback.c
            nxd_icmpv6_ra_flag_callback_set.c
            nxd_ipv6_address_change_notify.c
            nxd_ipv6_address_delete.c
            nxd_ipv6_address_get.c
            nxd_ipv6_address_set.c
            nxd_ipv6_default_router_add.c
            nxd_ipv6_default_router_delete.c
            nxd_ipv6_default_router_entry_get.c
            nxd_ipv6_default_router_get.c
            nxd_ipv6_default_router_number_of_entries_get.c
            nxd_ipv6_multicast_interface_join.c
            nxd_ipv6_multicast_interface_leave.c
            nxd_ipv6_stateless_address_autoconfig_disable.c
            nxd_ipv6_stateless_address_autoconfig_enable.c
            nxd_nd_cache_entry_delete.c
            nxd_nd_cache_entry_set.c
            nxd_nd_cache_hardware_address_find.c
            nxd_nd_cache_invalidate.c
            nxd_nd_cache_ip_address_find.c
            nxde_icmpv6_ra_flag_callback_set.c
            nxde_ipv6_address_delete.c
            nxde_ipv6_address_get.c
            nxde_ipv6_address_set.c
            nxde_ipv6_default_router_add.c
            nxde_ipv6_default_router_delete.c
            nxde_ipv6_default_router_entry_get.c
            nxde_ipv6_default_router_get.c
            nxde_ipv6_default_router_number_of_entries_get.c
            nxde_ipv6_stateless_address_autoconfig_disable.c
            nxde_ipv6_stateless_address_autoconfig_enable.c
            nxde_nd_cache_entry_delete.c
            nxde_nd_cache_entry_set.c
            nxde_nd_cache_hardware_address_find.c
            nxde_nd_cache_invalidate.c
            nxde_nd_cache_ip_address_find.c
            nxe_ip_auxiliary_packet_pool_set.c
            nxe_tcp_socket_disconnect_complete_notify.c
            nxe_tcp_socket_establish_notify.c
            nxe_tcp_socket_queue_depth_notify_set.c
            nxe_tcp_socket_timed_wait_callback.c

         Files are modified to fix address index check for loopback interface:
            nxde_icmp_source_ping.c
            nxde_ip_raw_packet_source_send.c
            nxde_udp_socket_source_send.c
            nxe_ip_raw_packet_source_send.c
            nxe_udp_socket_source_send.c

         Files are modified to support IP packet filter:
            nx_api.h
            nx_ip_packet_receive.c
            nx_ip_packet_send.c
            nx_ipv6_packet_send.c

        Files are added or modified to set TCP receive queue length:
            nx_api.h
            nx_tcp.h
            nx_tcp_socket_create.c
            nx_tcp_socket_receive_queue_max_set.c
            nx_tcp_socket_state_data_check.c
            nx_user.h
            nxe_tcp_socket_receive_queue_max_set.c

        Files are added or modified to support packet pool low watermark:
            nx_api.h
            nx_packet.h
            nx_packet_pool_low_watermark_set.c
            nx_tcp_socket_state_data_check.c
            nx_udp_packet_receive.c
            nx_user.h
            nxe_packet_pool_low_watermark_set.c
            nxe_tcp_socket_receive_queue_max_set.c

        Files are modified to add mutex protection:
            nx_rarp_disable.c
            nx_tcp_socket_queue_depth_notify_set.c
            nx_tcp_socket_receive_notify.c
            nx_tcp_socket_timed_wait_callback.c
            nx_tcp_socket_window_update_notify_set.c

        Files are added or modified to fix source selection for icmpv4 ping:
            nx_icmpv4.h
            nx_icmp_interface_ping.c
            nx_icmp_ping.c
            nxd_icmp_source_ping.c

        Files are modified to support ASSERT macro:
            nx_api.h
            nx_icmpv6_dest_table_add.c
            nx_ip_header_add.c
            nx_ip_driver_packet_send.c
            nx_ipv6_packet_send.c
            nxd_ipv6_destination_table_find_next_hop.c
            nxd_ipv6_interface_find.c

        Files are added or modified to support NewReno algorithm:
            nx_api.h
            nx_tcp.h
            nx_tcp_socket_retransmit.c
            nx_tcp_fast_periodic_processing.c
            nx_tcp_packet_send_syn.c
            nx_tcp_socket_block_cleanup.c
            nx_tcp_socket_state_ack_check.c
            nx_tcp_socket_send_internal.c
            nx_tcp_socket_state_transmit_check.c
            nx_tcp_socket_state_syn_sent.c
            nx_tcp_socket_state_syn_received.c

        Files are added or modified to optimize the logic of sending TCP control packet:
            nx_tcp_packet_send_control.c
            nx_tcp_packet_send_syn.c
            nx_tcp_packet_send_ack.c
            nx_tcp_packet_send_fin.c
            nx_tcp_packet_send_rst.c

        Files are deleted due to they are not used:
            nxe_igmp_multicast_interface_join_internal.c
            nxe_igmp_multicast_interface_leave_internal.c

        Files are modified to unify the definition of ThreadX ticks per second, use TX_TIMER_TICKS_PER_SECOND to derive NX_IP_PERIODIC_RATE:
            demo_netx_duo_multihome_tcp.c
            demo_netx_duo_multihome_udp.c
            demo_netx_duo_tcp.c
            demo_netx_duo_udp.c
            nx_api.h
            nx_icmpv6_dest_table_add.c
            nx_icmpv6_dest_table_find.c
            nx_icmpv6_process_ra.c
            nx_icmpv6_process_redirect.c
            nx_icmpv6_validate_ra.c
            nx_ip_create.c
            nx_ip_fast_periodic_timer_entry.c
            nx_system.h
            nx_system_initialize.c
            nx_tcp.h
            nx_tcp_enable.c
            nx_user.h
            nxd_ipv6_disable.c
            nxd_ipv6_enable.c

        Files are deleted or modified to simplified the logic of extracting the prefix:
            nx_ipv6_address_find_prefix.c
            nx_ipv6.h
            nx_ipv6_prefix_list_delete_entry.c

        Files are modified to correct the IP Identification field for retransmitted packet:
            nx_api.h
            nx_ip_header_add.c
            nx_packet_allocate.c
            nx_packet_release.c
            nx_tcp_socket_retransmit.c

        Files are added or modified to fix zero window probe packet:
            nx_api.h
            nx_tcp.h
            nx_tcp_fast_periodic_processing.c
            nx_tcp_packet_send_probe.c
            nx_tcp_socket_send_internal.c
            nx_tcp_socket_state_ack_check.c

        Files are modified to correct the sequence and ACK number check for TCP disconnect process:
            nx_api.h
            nx_tcp.h
            nx_tcp_server_socket_accept.c
            nx_tcp_socket_packet_process.c
            nx_tcp_socket_state_ack_check.c
            nx_tcp_socket_state_fin_wait1.c
            nx_tcp_socket_state_fin_wait2.c
            nx_tcp_client_socket_connect.c

        Files are modified to pass PC-Lint check:
            nx_icmp.h
            nx_icmpv6.h
            nx_ip.h
            nx_ipv4.h
            nx_ipv6.h
            nx_ipv6_prefix_list_delete.c
            nx_nd_cache.h
            nx_udp.h
            nxd_icmp_ping.c
            nxd_icmp_source_ping.c
            nxd_icmpv6_ra_flag_callback_set.c
            nxd_ip_raw_packet_send.c
            nxd_ipv6_address_change_notify.c
            nxd_ipv6_address_set.c
            nxd_ipv6_default_router_add_internal.c
            nxd_ipv6_destination_table_find_next_hop.c
            nxd_ipv6_disable.c
            nxd_ipv6_enable.c
            nxd_ipv6_find_default_router_from_address.c
            nxd_ipv6_find_max_prefix_length.c
            nxd_ipv6_interface_find.c
            nxd_ipv6_raw_packet_send_internal.c
            nxd_ipv6_router_lookup.c
            nxd_ipv6_search_onlink.c
            nxd_ipv6_stateless_address_autoconfig_enable.c
            nxd_nd_cache_entry_set.c
            nxd_nd_cache_hardware_address_find.c
            nxde_icmp_ping.c
            nxde_icmp_source_ping.c
            nxde_ip_raw_packet_send.c
            nxde_ip_raw_packet_source_send.c
            nxde_ipv6_address_delete.c
            nxde_ipv6_default_router_delete.c
            nxde_ipv6_multicast_interface_join.c
            nxde_ipv6_multicast_interface_delete.c
            nxde_nd_cache_entry_set.c
            nxde_udp_socket_send.c


        Files are modified to remove deprecated macro for IPv6 path MTU:
            nx_icmpv6.h
            nx_user.h


        Files are added or modified to support packet debug feature:
            nx_api.h
            nx_arp_gratuitous_send.c
            nx_arp_packet_deferred_receive.c
            nx_arp_packet_send.c
            nx_icmp_interface_ping6.c
            nx_icmp_packet_process.c
            nx_icmp_packet_receive.c
            nx_icmp_ping.c
            nx_icmpv4_packet_process.c
            nx_icmpv6_packet_process.c
            nx_icmpv6_process_echo_reply.c
            nx_icmpv6_process_echo_request.c
            nx_icmpv6_process_na.c
            nx_icmpv6_process_packet_too_big.c
            nx_icmpv6_process_ra.c
            nx_icmpv6_process_redirect.c
            nx_icmpv6_send_error_message.c
            nx_icmpv6_send_ns.c
            nx_icmpv6_send_rs.c
            nx_igmp_multicast_interface_leave_internal.c
            nx_igmp_packet_process.c
            nx_igmp_packet_receive.c
            nx_igmp_periodic_processing.c
            nx_ip_dispatch_process.c
            nx_ip_driver_packet_send.c
            nx_ip_fragment_forward_packet.c
            nx_ip_fragment_packet.c
            nx_ip_packet_deferred_receive.c
            nx_ip_packet_receive.c
            nx_ip_packet_send.c
            nx_ip_raw_packet_processing.c
            nx_ip_raw_packet_send.c
            nx_ip_raw_packet_source_send.c
            nx_ip_thread_entry.c
            nx_ipv4_packet_receive.c
            nx_ipv6_fragment_process.c
            nx_ipv6_packet_receive.c
            nx_ipv6_process_fragment_option.c
            nx_ipv6_process_hop_by_hop_option.c
            nx_ipv6_process_routing_option.c
            nx_packet.h
            nx_packet_allocate.c
            nx_packet_copy.c
            nx_packet_data_append.c
            nx_packet_debug_info_get.c
            nx_packet_pool_create.c
            nx_packet_release.c
            nx_packet_transmit_release.c
            nx_rarp_packet_deferred_receive.c
            nx_rarp_packet_send.c
            nx_tcp_packet_process.c
            nx_tcp_packet_receive.c
            nx_tcp_queue_process.c
            nx_tcp_socket_packet_process.c
            nx_tcp_socket_send.c
            nx_tcp_socket_send_internal.c
            nx_udp_packet_receive.c
            nx_user.h
            nxd_ip_raw_packet_source_send.c
            nxd_udp_socket_send.c


        Files are modified to support packet alignment for both header and payload:
            nx_api.h
            nx_packet_pool_create.c
            nxe_packet_pool_create.c
            nx_user.h

        Files are added or modified to ensure only one ARP entry point to specific address and optimized the ARP queued packet sending:
            nx_api.h
            nx_arp.h
            nx_arp_queue_send.c
            nx_arp_dynamic_entry_set.c
            nx_arp_entry_allocate.c
            nx_arp_static_entry_create.c
            nx_arp_static_entry_delete_internal.c
            nx_arp_packet_receive.c
            nx_ip_driver_packet_send.c

        Files are modified to send TCP reset message when receive an illegal TCP option:
            nx_tcp.h
            nx_tcp_packet_process.c
            nx_tcp_server_socket_relisten.c
            nx_tcp_mss_option_get.c
            nx_tcp_window_scaling_option_get.c
            nx_tcp_no_connection_reset.c

        Files are modified to support for TCP TIMED WAIT state:
            nx_tcp.h
            nx_tcp_enable.c
            nxd_tcp_client_socket_connect.c
            nx_tcp_fast_periodic_processing.c
            nx_tcp_socket_state_fin_wait1.c
            nx_tcp_socket_state_fin_wait2.c
            nx_tcp_socket_state_closing.c
            nx_tcp_socket_packet_process.c

        Files are modified to optimize the code for deleting transmission control block
            nx_tcp.h
            nx_tcp_fast_periodic_processing.c
            nx_tcp_client_socket_unbind.c
            nx_tcp_socket_block_cleanup.c
            nx_tcp_socket_connection_reset.c
            nx_tcp_socket_disconnection.c
            nx_tcp_socket_state_last_ack.c

        Files are added or modified to support ICMPv4 error message:
            nx_icmpv4.h
            nx_icmpv4_packet_process.c
            nx_icmpv4_process_echo_reply.c
            nx_icmpv4_process_echo_request.c
            nx_icmpv4_send_error_message.c
            nx_ip_dispatch_process.c
            nx_ip_fragment_timeout_check.c
            nx_udp_packet_receive.c

        Files are added or modified to support IP Option processing:
            nx_ipv4.h
            nx_ipv4_packet_receive.c
            nx_ipv4_option_process.c

        Files are modified to correct the reassembly time:
            nx_api.h
            nx_user.h
            nx_ip_fragment_assembly.c

        Files are modified to optimize the code.
            nx_ip_gateway_address_set.c
            nx_ipv4.h
            nx_nd_cache_add.c
            nx_nd_cache_add_entry.c
            nx_nd_cache_find_entry.c
            nx_tcp_client_bind_cleanup.c
            nx_tcp_connect_cleanup.c
            nx_tcp_disconnect_cleanup.c
            nx_tcp_receive_cleanup.c
            nx_tcp_transmit_cleanup.c
            nxd_ipv6_stateless_address_autoconfig_disable.c
            nxd_ipv6_stateless_address_autoconfig_enable.c
            nxd_nd_cache_ip_address_find.c
            nxd_nd_cache_hardware_address_find.c
            nxde_ipv6_stateless_address_autoconfig_disable.c
            nxde_ipv6_stateless_address_autoconfig_enable.c
            nxe_ip_gateway_address_set.c
            nxe_ip_raw_packet_receive.c
            nxe_ip_static_route_add.c

         Files are modified to assembled all the fragments before calling NAT service:
            nx_api.h
            nx_ip_fragment_assembly.c
            nx_ipv4_packet_receive.c

        The following table contains mappings from legacy names to the new names developers
        are encouraged to use for furture development work.  For backward compatibility reasons,
        legacy names are still maintained. Therefore existing projects and build systems are not
        affected.


                  Legacy Names                                       New Names

            NX_ARP_DISABLE_AUTO_ARP_ENTRY                       NX_DISABLE_ARP_AUTO_ENTRY
            NX_DISABLE_ICMPv4_RX_CHECKSUM                       NX_DISABLE_ICMPV4_RX_CHECKSUM
            NX_DISABLE_ICMPv4_TX_CHECKSUM                       NX_DISABLE_ICMPV4_TX_CHECKSUM
            NX_DISABLE_ICMPv6_RX_CHECKSUM                       NX_DISABLE_ICMPV6_RX_CHECKSUM
            NX_DISABLE_ICMPv6_TX_CHECKSUM                       NX_DISABLE_ICMPV6_TX_CHECKSUM
            NX_DUAL_PACKET_POOL_ENABLE                          NX_ENABLE_DUAL_PACKET_POOL
            NX_IPV6_ADDRESS_CHANGE_NOTIFY_ENABLE                NX_ENABLE_IPV6_ADDRESS_CHANGE_NOTIFY
            NX_IPV6_DISABLE_PURGE_UNUSED_CACHE_ENTRIES          NX_DISABLE_IPV6_PURGE_UNUSED_CACHE_ENTRIES
            NX_IPV6_MULTICAST_ENABLE                            NX_ENABLE_IPV6_MULTICAST
            NX_TCP_ENABLE_KEEPALIVE                             NX_ENABLE_TCP_KEEPALIVE
            NX_TCP_ENABLE_MSS_CHECK                             NX_ENABLE_TCP_MSS_CHECK
            NX_TCP_ENABLE_WINDOW_SCALING                        NX_ENABLE_TCP_WINDOW_SCALING
            NX_TCP_QUEUE_DEPTH_UPDATE_NOTIFY_ENABLE             NX_ENABLE_TCP_QUEUE_DEPTH_UPDATE_NOTIFY
            NXDUO_DESTINATION_TABLE_SIZE                        NX_IPV6_DESTINATION_TABLE_SIZE
            NXDUO_DISABLE_ICMPV6_ERROR_MESSAGE                  NX_DISABLE_ICMPV6_ERROR_MESSAGE
            NXDUO_DISABLE_ICMPV6_REDIRECT_PROCESS               NX_DISABLE_ICMPV6_REDIRECT_PROCESS
            NXDUO_DISABLE_ICMPV6_ROUTER_ADVERTISEMENT_PROCESS   NX_DISABLE_ICMPV6_ROUTER_ADVERTISEMENT_PROCESS
            NXDUO_DISABLE_ICMPV6_ROUTER_SOLICITATION            NX_DISABLE_ICMPV6_ROUTER_SOLICITATION
            NXDUO_DISABLE_DAD                                   NX_DISABLE_IPV6_DAD
            NXDUO_DUP_ADDR_DETECT_TRANSMITS                     NX_IPV6_DAD_TRANSMITS
            NXDUO_ICMPV6_MAX_RTR_SOLICITATIONS                  NX_ICMPV6_MAX_RTR_SOLICITATIONS
            NXDUO_ICMPV6_RTR_SOLICITATION_INTERVAL              NX_ICMPV6_RTR_SOLICITATION_INTERVAL
            NX_CRYPTO_MAX_IV_SIZE_IN_BITS                       (Moved into IPsec module)

        Files are modified to rename symbols:

            nx_api.h
            nx_arp_gratuitous_send.c
            nx_arp_packet_receive.c
            nx_arp_packet_send.c
            nx_icmp_interface_ping6.c
            nx_icmp_interface_ping.c
            nx_icmpv4_packet_process.c
            nx_icmpv4_process_echo_request.c
            nx_icmpv4_send_error_message.c
            nx_icmpv6_DAD_failure.c
            nx_icmpv6_destination_table_periodic_update.c
            nx_icmpv6_dest_table_add.c
            nx_icmpv6_dest_table_find.c
            nx_icmpv6.h
            nx_icmpv6_packet_process.c
            nx_icmpv6_perform_DAD.c
            nx_icmpv6_process_echo_request.c
            nx_icmpv6_process_na.c
            nx_icmpv6_process_ns.c
            nx_icmpv6_process_ra.c
            nx_icmpv6_process_redirect.c
            nx_icmpv6_send_error_message.c
            nx_icmpv6_send_ns.c
            nx_icmpv6_send_rs.c
            nx_icmpv6_validate_ra.c
            nx_igmp_multicast_interface_leave_internal.c
            nx_igmp_periodic_processing.c
            nx_invalidate_destination_entry.c
            nx_ip_auxiliary_packet_pool_set.c
            nx_ip_create.c
            nx_ip_dispatch_process.c
            nx_ip_fragment_timeout_check.c
            nx_ip_interface_attach.c
            nx_ip_interface_detach.c
            nx_ip_packet_receive.c
            nx_ip_packet_send.c
            nx_ip_thread_entry.c
            nx_ipv6_option_error.c
            nx_ipv6_packet_receive.c
            nx_ipv6_packet_send.c
            nx_ipv6_prefix_list_delete_entry.c
            nx_ipv6_process_fragment_option.c
            nx_ipv6_process_routing_option.c
            nx_mld.h
            nx_nd_cache_add_entry.c
            nx_nd_cache_delete_internal.c
            nx_packet.h
            nx_packet_pool_low_watermark_set.c
            nx_rarp_packet_send.c
            nx_system.h
            nx_system_initialize.c
            nx_tcp.h
            nx_tcp_packet_process.c
            nx_tcp_packet_send_control.c
            nx_tcp_packet_send_syn.c
            nx_tcp_periodic_processing.c
            nx_tcp_server_socket_relisten.c
            nx_tcp_socket_create.c
            nx_tcp_socket_disconnect.c
            nx_tcp_socket_queue_depth_notify_set.c
            nx_tcp_socket_receive_queue_max_set.c
            nx_tcp_socket_retransmit.c
            nx_tcp_socket_send_internal.c
            nx_tcp_socket_state_ack_check.c
            nx_tcp_socket_state_data_check.c
            nx_tcp_socket_state_established.c
            nx_tcp_socket_state_syn_received.c
            nx_tcp_socket_state_syn_sent.c
            nx_tcp_window_scaling_option_get.c
            nx_udp_packet_receive.c
            nx_user.h
            nxde_ipv6_address_change_notify.c
            nxde_ipv6_multicast_interface_join.c
            nxde_ipv6_multicast_interface_leave.c
            nxd_icmp_enable.c
            nxd_ipv6_address_change_notify.c
            nxd_ipv6_address_delete.c
            nxd_ipv6_address_set.c
            nxd_ipv6_destination_table_find_next_hop.c
            nxd_ipv6_disable.c
            nxd_ipv6_enable.c
            nxd_ipv6_interface_find.c
            nxd_ipv6_multicast_interface_join.c
            nxd_ipv6_multicast_interface_leave.c
            nxd_ipv6_prefix_router_timer_tick.c
            nxd_ipv6_router_solicitation_check.c
            nxe_packet_pool_low_watermark_set.c
            nxe_tcp_socket_create.c
            nxe_tcp_socket_queue_depth_notify_set.c
            nxe_tcp_socket_receive_queue_max_set.c



        Other modified files:
            nx_api.h                                         Removed internal functions.
                                                               Fixed typo for API names of stateless address control.
                                                               Added a macro to disable warning of parameter not used.
            nx_icmp_ping.h                                   Optimized the data offset of request packet.
            nx_icmp_interface_ping6.c                        Removed limitation of message size when sending echo request.
            nx_icmpv6.h                                      Updated the function name.
                                                               Removed unused argument of _nxd_ipv6_destination_table_find_next_hop.
            nx_icmpv6_dest_table_add.c                       Fixed a bug when destination table was full, index of
                                                               array was out of bound.
            nx_icmpv6_perform_DAD.c                          Updated the function name.
            nx_icmpv6_DAD_clear_NDCache_entry.c              Updated the function name and optimized the code.
            nx_icmpv6_DAD_failure.c                          Renamed the argument name to make it sense.
            nx_icmpv6_process_packet_too_big.c               Fixed a bug that packet was not released.
            nx_icmpv6_process_ra.c                           Fixed a bug that address was formed when prefix was link local.
                                                               Fixed the logic to find empty address entry.
                                                               Fixed retrans timer when it is 0.
            nx_icmpv6_process_redirect.c                     Fixed return status check. Fixed endian of MTU.
            nx_icmpv6_send_error_message.c                   Used wrong IPv6 address.
                                                               Fixed packet leak if IPsec SA disallows this packet.
                                                               Fixed multicast destination address check.
            nx_icmpv6_send_queued_packets                    Optimized the logic for IPv6 fragment processing.
            nx_icmpv6_send_rs.c                              Removed unreachable code.
            nx_icmpv6_validate_neighbor_message.c            Removed unused argument.
            nx_icmpv6_validate_ra.c                          Removed unused argument.
            nx_igmp_packet_process.c                         Optimized the logic of verifying checksum.
            nx_igmp_periodic_process.c                       Removed useless code.
            nx_ip_checksum_compute.c                         Fixed calculation for packet size that is only two bytes aligned.
            nx_ip_create.c                                   Removed the status check for TX API since internal call should be succeed.
            nx_ip_deferred_link_status_process.c             Removed cleanup logic when link was down.
            nx_ip_delete.c                                   Invalidated dynamic ARP entries and ND cache,
                                                               in case packets were queued.
            nx_ip_dispatch_process.c                         Corrected length check for extension header.
                                                               Removed unreachable code.
            nx_ip_driver_packet_send.c                       Added support for IPv4 link-local address
                                                               Optimized the logic for packet sending.
                                                               Added fragmentation check.
            nx_ip_header_add.c                               Stored IP header for outgoing packet.
            nx_ip_fragment_assembly.c                        Used the more recently arrived copy if fragments contain the same data.
                                                               Corrected the logic to find insert position for IPv6 fragments.
            nx_ip_fragment_disable.c                         Removed unreachable code when NX_FRAGMENT_IMMEDIATE_ASSEMBLY is defined.
            nx_ip_fragment_packet.c                          Removed unreachable code.
            nx_ip_fragment_forward_packet.c                  Removed unreachable code.
            nx_ip_forward_packet_process.c                   Added checks for link local address before forwarding.
            nx_ip_interface_attach.c                         Fixed duplicate empty address.
            nx_ip_interface_detach.c                         Simplified the logic to leave multicast group.
            nx_ip_interface_status_check.c                   Checked driver code for NX_IP_LINK_ENABLED status.
                                                               Fixed the bug for wait_option.
            nx_ip_packet_checksum_compute.c                  Removed code not used. Fixed offset when IPv4 header contained options.
                                                               Removed flag after IPv4 checksum calculated.
                                                               Fixed length calculation of IPv4 header.
            nx_ip_packet_send.c                              Removed unreachable lines.
                                                               Initialized status value.
            nx_ip_raw_packet_send.c                          Removed duplicate check for raw service enabled.
            nx_ip_raw_packet_source_send.c                   Removed duplicate check for raw service enabled.
                                                               Optimized the code.
            nx_ip_route_find.c                               Optimized search operation for loopback address.
                                                               Fixed a bug that loopback interface was used by multicast or broadcase address.
                                                               Added support for link-local address.
                                                               Verified whther or not routing address was reachable.
            nx_ip_static_route_add.c                         Fixed a bug that mutex is not released before return.
            nx_ip_status_check.c                             Removed duplicated code.
            nx_ip_thread_entry.c                             Ensured the pointer function is valid before use.
            nx_ipv4_packet_receive.c                         Fixed a bug in source check when address mapping is not needed.
            nx_ipv6_fragment_process.c                       Fixed offset of fragment packets.
            nx_ipv6_multicast_leave.c                        Removed unreachable code.
            nx_ipv6_multicast_join.c                         Removed unreachable code.
            nx_ipv6_option_error.c                           Removed duplicated check for function pointer.
            nx_ipv6_packet_copy.c                            Fixed a bug that four extra bytes were incorrectly copied.
            nx_ipv6_packet_send.c                            Removed fragment check when IPsec is disabled for PMTU, stored IP header for outgoing packet.
            nx_ipv6_prefix_list_add_entry.c                  Fixed a bug that prefix was not sorted.
                                                               Removed unused argument.
            nx_ipv6_prefix_list_delete_entry.c               Optimized the logic to find address.
            nx_ipv6_process_hop_by_hop_option.c              Eliminated unreachable code.
            nx_ipv6_util.c                                   Removed unnecessary NULL check in IPv6_Address_Type.
            nx_mld.h                                         Cleaned up this file.
            nx_packet_allocate.c                             Moved packet type check from _nxe_packet_allocate since
                                                               it is necessary when _nx_packet_allocate is called
                                                               by internal functions.
            nx_packet_copy.c                                 Copied the data of the first packet beginning at data starting position.
                                                               Fixed the bug for ip header pointer set.
            nx_packet_pool_create.c                          Removed unreachable code.
            nx_ram_network_driver.c                          Removed unused parameter in _nx_ram_network_driver_output.
                                                               Supported more commands.
            nx_rarp_packet_receive.c                         Continued RARP when address mapping needed.
            nx_tcp.h                                         Defined the TCP minimum acceptable MSS.
                                                               Added missing TCP function declarations.
            nx_tcp_client_socket_unbind.c                    Limited the socket state to closed only.
            nx_tcp_fast_periodic_processing.c                Modified the logic for zero window probe.
                                                               Updated ACK number and window size for retransmitted packet.
            nx_tcp_packet_process.c                          Fixed invalid source address check.
                                                               Improved statistics of invalid packet.
                                                               Optimized the logic of processing RST packet for listen queue.
            nx_tcp_periodic_processing.c                     Updated the retries to reach the max value.
            nx_tcp_server_socket_accept.c                    Removed unreachable code.
            nx_tcp_server_socket_unlisten.c                  Reset the socket state only when it was listening.
            nx_tcp_socket_create.c                           Removed duplicated check for window size.
            nx_tcp_socket_send_internal.c                    Modified the wait time.
                                                               Removed the TCP transmit suspended count limitation.
                                                               Modified to release IP mutex protection before a blocking call.
                                                               Replaced NX_NO_WAIT with the input wait_option in nx_packet_allocate, nx_packet_data_append.
                                                               Removed duplicated error check.
                                                               Optimized the logic of processing sending packet.
                                                               Fixed the alignment of subsequent packet in chain.
            nx_tcp_socket_disconnect.c                       Removed check for transmit queue when connection was not established.
                                                               Called the cleanup routines after completed the tcp disconnected operation.
            nx_tcp_socket_packet_process.c                   Removed the data check in CLOSE WAIT state.
                                                               Checked ACK for LAST ACK and CLOSING state.
                                                               Checked socket state before processing data.
                                                               Fixed a bug that the receive window can not recover.
            nx_tcp_socket_receive.c                          Modified the logic for SWS avoidance algorithm.
            nx_tcp_socket_state_ack_check.c                  Corrected the processing procedure for SYN/ACK bits.
                                                               Modified the logic to adjust congestion window during slow start and congestion avoidance.
                                                               Fixed a bug in ACK check logic if the packet was not transmitted by driver.
                                                               Stored IP header for outgoing packet.
            nx_tcp_socket_state_closing.c                    Removed sending ACK message code if ACK did not acknowledge FIN.
            nx_tcp_socket_state_data_check.c                 Fixed the ACKed packets in order.
                                                               Fixed the bug for updating receive window.
                                                               Trimmed the data that out of receive window.
                                                               Optimized the logic when a packet with old data is received.
                                                               Modified the logic for SWS avoidance algorithm.
            nx_tcp_socket_state_established.c                Removed unused parameter.
            nx_tcp_socket_state_last_ack.c                   Removed sending ACK message code if ACK did not acknowledge FIN.
            nx_tcp_socket_state_syn_sent.c                   Fixed sequence number for simultaneous connection.
                                                               Checked maximum value of window scale when it was set.
            nx_tcp_socket_state_syn_received.c               Updated tx_window_advertised value.
                                                               Checked maximum value of window scale when it was set.
                                                               Removed duplicated out of window check.
            nx_tcp_window_scaling_option_get.c               Limited the maximum value of window scale.
            nx_nd_cache_init.c                               Removed the status check for TX API since internal call should be succeed.
            nx_nd_cache_interface_entries_delete.c           Removed duplicated deletion for destination table.
            nx_tcp_packet_send_rst.c                         Modified reset ack number, sequence number and ACK bit according to incoming packet ACK bit.
            nx_tcp_server_socket_relisten.c                  Released the protection before return.
            nx_udp_packet_receive.c                          Removed duplicated check for function pointer.
            nx_user.h                                        Added ASSERT macros. Remvoed unused macros.
                                                               Added macros defined in nx_api.h but not in nx_user.h.
                                                               Sorted options by module.
            nxd_ip_raw_packet_source_send.c                  Removed duplicate check for raw service enabled.
            nxd_ipv6_address_delete.c                        Fixed a bug that if_index may be used before initialized.
            nxd_ipv6_address_set.c                           Fixed a bug that mutex is not released before return.
                                                               Fixed link local duplicate address set.
            nxd_ipv6_default_router_add_internal.c           Returned error status when router table was full.
            nxd_ipv6_default_router_delete.c                 Returned error status when router table was not found.
            nxd_ipv6_default_router_entry_get.c              Optimized logic comparing the interface.
            nxd_ipv6_default_router_get.c                    Used the logic of _nxd_ipv6_default_router_entry_get.
            nxd_ipv6_destination_table_find_next_hop.c       Removed unused argument.
            nxd_ipv6_disable.c                               Cleaned up ND_CACHE when ICMP was enabled.
            nxd_ipv6_enable.c                                Corrected retransmit timer when it is zero.
            nxd_ipv6_interface_find.c                        Used first up interface for link local multicast.
                                                               Fixed null pointer access.
            nxd_nd_cache_entry_delete.c                      Removed duplicated deletion for destination table.
            nxd_tcp_client_socket_connect.c                  Fixed the bug for address version check, updated the header size.
                                                               Fixed loopback destination.
                                                               Fixed the bug for socket state since it is updated in connect cleanup.
            nxd_udp_socket_send.c                            Fixed statistics when IPv6 address was not valid.
            nxde_ip_raw_packet_source_send.c                 Added the check for packet pointer.
            nxde_ipv6_address_change_notify.c                Checked calling thread.
            nxde_ipv6_address_set.c                          Filtered address that was not unicast type.
            nxde_udp_socket_send.c                           Fixed checking for header area of packet.
            nxde_udp_socket_source_send.c                    Added the check for packet pointer.
            nxe_arp_dynamic_entry_set.c                      Added the check for IP address.
            nxe_arp_ip_address_find.c                        Added the check for invalid physical address.
            nxe_arp_static_entry_create.c                    Added the check for invalid physical address.
                                                               Added the check for IP address.
            nxe_arp_static_entry_delete.c                    Added the check for invalid physical address.
            nxe_ip_create.c                                  Added the priority check.
            nxe_packet_allocate.c                            Moved packet type check to _nx_packet_allocate since
                                                               it is necessary when _nx_packet_allocate is called
                                                               by internal functions.
            nxe_tcp_socket_create.c                          Checked window size when window scale was not enabled.
            nxe_tcp_socket_send.c                            Fixed checking for header area of packet.
            nxe_tcp_socket_disconnect_complete_notify.c      Added the check for input parameters.
            nxe_tcp_socket_establish_notify.c                Added the check for input parameters.
            nxe_tcp_socket_timed_wait_callback.c             Added the check for input parameters.
            nxe_udp_socket_send.c                            Fixed checking for header area of packet.
            nxe_udp_socket_source_send.c                     Fixed checking for header area of packet.


01/12/2015  NetX Duo generic code version 5.8. This release includes the
            following major features:


        Files are modified to remove deprecated macro for IPv6 path MTU:
            nx_icmpv6.h
            nx_user.h


        Files are added or modified to support ipv4 multicast feature:
            nx_ipv4_multicast_interface_join.c
            nx_ipv4_multicast_interface_leave.c
            nxe_ipv4_multicast_interface_join.c
            nxe_ipv4_multicast_interface_leave.c


        Files are modified to fix compiler warnings:
            nx_arp_packet_receive.c
            nx_icmpv4_packet_process.c
            nx_icmpv6.h
            nx_icmpv6_dest_table_find.c
            nx_icmpv6_packet_process.c
            nx_icmpv6_process_echo_reply.c
            nx_icmpv6_process_echo_request.c
            nx_icmpv6_process_na.c
            nx_icmpv6_process_ns.c
            nx_icmpv6_process_ra.c
            nx_icmpv6_process_redirect.c
            nx_icmpv6_send_error_message.c
            nx_icmpv6_send_ns.c
            nx_icmpv6_send_queued_packets.c
            nx_icmpv6_send_rs.c
            nx_icmpv6_validate_neighbor_message.c
            nx_icmpv6_validate_ra.c
            nx_igmp_packet_process.c
            nx_igmp_periodic_processing.c
            nx_invalidate_destination_entry.c
            nx_ip_checksum_compute.c
            nx_ip_dispatch_process.c
            nx_ip_forward_packet_process.c
            nx_ip_fragment_assembly.c
            nx_ip_fragment_packet.c
            nx_ip_packet_receive.c
            nx_ipv4_packet_receive.c
            nx_ipv6_address_find_prefix.c
            nx_ipv6_fragment_process.c
            nx_ipv6_option_error.c
            nx_ipv6_packet_copy.c
            nx_ipv6_packet_receive.c
            nx_ipv6_packet_send.c
            nx_ipv6_prefix_list_add_entry.c
            nx_ipv6_process_fragment_option.c
            nx_ipv6_process_hop_by_hop_option.c
            nx_ipv6_process_routing_option.c
            nx_ipv6_util.c
            nx_nd_cache_add.c
            nx_nd_cache_add_entry.c
            nx_nd_cache_find_entry.c
            nx_packet_copy.c
            nx_packet_data_append.c
            nx_packet_data_retrieve.c
            nx_tcp_no_connection_reset.c
            nx_tcp_packet_process.c
            nx_tcp_packet_send_ack.c
            nx_tcp_packet_send_fin.c
            nx_tcp_packet_send_rst.c
            nx_tcp_packet_send_syn.c
            nx_tcp_socket_bytes_available.c
            nx_tcp_socket_mss_set.c
            nx_tcp_socket_send.c
            nx_tcp_socket_send_internal.c
            nx_tcp_socket_state_ack_check.c
            nx_tcp_socket_state_data_check.c
            nx_udp_packet_receive.c
            nx_udp_socket_receive.c
            nxd_ipv6_address_set.c
            nxd_ipv6_default_router_add_internal.c
            nxd_ipv6_default_router_entry_get.c
            nxd_ipv6_default_router_get.c
            nxd_ipv6_destination_table_find_next_hop.c
            nxd_ipv6_disable.c
            nxd_ipv6_interface_find.c
            nxd_ipv6_prefix_router_timer_tick.c
            nxd_ipv6_search_onlink.c
            nxd_nd_cache_hardware_address_find.c
            nxd_nd_cache_ip_address_find.c
            nxd_tcp_client_socket_connect.c
            nxd_udp_socket_send.c
            nxde_icmp_ping.c
            nxde_icmp_source_ping.c
            nxde_ip_raw_packet_send.c
            nxe_ip_create.c
            nxe_packet_pool_create.c
            nxe_tcp_socket_create.c
            nxe_tcp_socket_send.c
            nxe_udp_socket_create.c
            nxe_udp_socket_send.c
            nxe_udp_source_extract.c


        Files are modified to optimize NX_PACKET_STRUCT:
            nx_api.h
            nx_arp_dynamic_entry_set.c
            nx_arp_packet_receive.c
            nx_arp_packet_send.c
            nx_icmp_interface_ping6.c
            nx_icmp_ping.c
            nx_icmpv4_packet_process.c
            nx_icmpv6_packet_process.c
            nx_icmpv6_process_echo_reply.c
            nx_icmpv6_process_echo_request.c
            nx_icmpv6_process_na.c
            nx_icmpv6_process_ns.c
            nx_icmpv6_process_packet_too_big.c
            nx_icmpv6_process_ra.c
            nx_icmpv6_process_redirect.c
            nx_icmpv6_send_error_message.c
            nx_icmpv6_send_ns.c
            nx_icmpv6_send_queued_packets.c
            nx_icmpv6_send_rs.c
            nx_igmp_packet_process.c
            nx_igmp_periodic_processing.c
            nx_ip_dispatch_process.c
            nx_ip_forward_packet_process.c
            nx_ip_fragment_assembly.c
            nx_ip_fragment_disable.c
            nx_ip_fragment_packet.c
            nx_ip_fragment_timeout_check.c
            nx_ip_packet_receive.c
            nx_ip_packet_send.c
            nx_ip_raw_packet_send.c
            nx_ip_raw_packet_source_send.c
            nx_ipv4.h
            nx_ipv4_packet_receive.c
            nx_ipv6.h
            nx_ipv6_fragment_process.c
            nx_ipv6_packet_receive.c
            nx_ipv6_packet_send.c
            nx_packet_allocate.c
            nx_packet_copy.c
            nx_packet_data_append.c
            nx_packet_data_extract_offset.c
            nx_packet_pool_create.c
            nx_packet_release.c
            nx_packet_transmit_release.c
            nx_ram_network_driver.c
            nx_rarp_packet_receive.c
            nx_rarp_packet_send.c
            nx_tcp_fast_periodic_processing.c
            nx_tcp_packet_process.c
            nx_tcp_packet_send_ack.c
            nx_tcp_packet_send_fin.c
            nx_tcp_packet_send_rst.c
            nx_tcp_packet_send_syn.c
            nx_tcp_server_socket_relisten.c
            nx_tcp_socket_bytes_available.c
            nx_tcp_socket_receive.c
            nx_tcp_socket_receive_queue_flush.c
            nx_tcp_socket_send_internal.c
            nx_tcp_socket_state_ack_check.c
            nx_tcp_socket_state_data_check.c
            nx_tcp_socket_state_transmit_check.c
            nx_tcp_socket_transmit_queue_flush.c
            nx_udp_socket_receive.c
            nx_udp_socket_source_send.c
            nxd_ip_raw_packet_source_send.c
            nxd_ipv6_raw_packet_send_internal.c
            nxd_udp_packet_info_extract.c
            nxd_udp_socket_send.c
            nxd_udp_socket_source_send.c
            nxde_udp_packet_info_extract.c
            nxde_udp_socket_send.c
            nxe_ip_raw_packet_send.c
            nxe_ip_raw_packet_source_send.c
            nxe_tcp_socket_send.c
            nxe_udp_packet_info_extract.c
            nxe_udp_socket_send.c
            nxe_udp_socket_source_send.c


        Files are modified to support the dual packet pool feature:
            nx_api.h
            nx_arp_gratuitous_send.c
            nx_arp_packet_send.c
            nx_icmpv6_send_ns.c
            nx_icmpv6_send_rs.c
            nx_igmp_periodic_processing.c
            nx_ip_create.c
            nx_ip_auxiliary_packet_pool_set.c
            nx_rarp_packet_send.c
            nx_tcp_packet_send_ack.c
            nx_tcp_packet_send_fin.c
            nx_tcp_packet_send_rst.c
            nx_tcp_packet_send_syn.c
            nx_user.h
            nxe_ip_auxiliary_packet_pool_set.c


        Files are modified to optimize NX_UDP_SOCKET_STRUCT:
            nx_api.h
            nx_udp_socket_create.c
            nxd_udp_socket_send.c


        Files are added or modified to support the link status change feature:
            nx_api.h
            nx_arp_interface_entries_delete.c
            nx_icmpv6.h
            nx_ip.h
            nx_ip_deferred_link_status_process.c
            nx_ip_driver_link_status_event.c
            nx_ip_link_status_change_notify_set.c
            nx_ip_thread_entry.c
            nx_nd_cache_interface_entries_delete.c
            nxe_ip_link_status_change_notify_set.c


        Files are added or modified in order to fact out the IPv4 packet transmit process:
            nx_ip_driver_packet_send.c
            nx_ip_header_add.c
            nx_ip_packet_send.c


        Files are modified to consolidate IGMP-related data structure in the IP instance:
            nx_api.h
            nx_igmp_multicast_check.c
            nx_igmp_packet_process.c
            nx_igmp_periodic_processing.c
            nx_ip_packet_send.c


        Files are added or modified to support the simple IPv4 routing and the NAT feature:
            nx_api.h
            nx_icmpv4_packet_process.c
            nx_ip_forward_packet_process.c
            nx_ip_fragment_forward_packet.c
            nx_ip_packet_send.c
            nx_ipv4_packet_receive.c
            nx_tcp_free_port_find.c
            nx_tcp_client_socket_bind
            nx_tcp_no_connection_reset.c
            nx_tcp_packet_process.c
            nx_tcp_server_socket_listen
            nx_tcp_server_socket_relisten.c
            nx_udp_free_port_find.c
            nx_udp_socket_bind.c
            nx_user.h


        Files are modified to support user defined random function:
            nx_api.h


        Files are modified to support the router advertisement flag callback feature:
            nx_api.h
            nx_icmpv6.h
            nx_icmpv6_process_ra.c
            nxd_icmpv6_ra_flag_callback_set.c
            nxde_icmpv6_ra_flag_callback_set.c


        Files are modified to support the ARP conflict defend feature:
            nx_api.h
            nx_arp_packet_receive.c
            nx_arp_periodic_update.c
            nx_ip_address_set.c
            nx_ip_interface_address_set.c
            nx_user.h


        Files are added or modified to optimized the logic for ARP dynamic entry deletion:
            nx_arp_dynamic_entries_invalidate.c
            nx_arp_dynamic_entry_delete.c
            nx_arp_entry_allocate.c
            nx_arp_entry_delete.c
            nxe_arp_entry_delete.c
            nx_arp_static_entry_delete.c
            nx_arp_static_entry_delete_internal.c
            nx_ip_create.c


        Files are added or modified to support IPv4 multicast join and leave feature:
            nx_igmp.h
            nx_igmp_multicast_interface_join.c
            nx_igmp_multicast_interface_join_internal.c
            nx_igmp_multicast_interface_leave.c
            nx_igmp_multicast_interface_leave_internal.c
            nx_igmp_multicast_join.c
            nx_igmp_multicast_leave.c
            nx_igmp_packet_process.c
            nx_igmp_periodic_processing.c
            nxe_igmp_multicast_interface_join_internal.c
            nxe_igmp_multicast_interface_leave.c
            nxe_igmp_multicast_interface_leave_internal.c


        Files are modified to support the router alert feature:
            nx_igmp_periodic_processing.c
            nx_ip_fragment_packet.c
            nx_ip_packet_send.c
            nx_ipv4.h


        Other modified files:
            nx_api.h                          Added new APIs for ipv4 multicast and interface detach, added definition of reassembly
                                                added definition of reassembly time, added new service nx_ip_gateway_address_clear,
                                                removed duplicate declarations, mapped the old APIs to new APIs, fixed a bug that
                                                nx_ipv4_packet_receive is mapped to _nx_igmp_multicast_leave_internal which is nonexistent.
            nx_arp.h                          Added new APIs for ARP dynamic entry delete, static entry delete internal and interface entries
                                                delete, added ARP defend deature.
            nx_arp_packet_receive.c           Fixed that packet is used after released,
                                                added a feature that responds to a conflict GARP packet,
                                                added an ARP man in the middle detection feature (NX_ARP_MAC_CHANGE_NOTIFICATION_ENABLE),
                                                blocked adding entries to ARP cache with zero sender IP address,
                                                prevent an ARP request matching an ARP entry sender address to change the mac address.
            nx_arp_static_entry_create.c      Fixed a bug that interface is not initialized before used.
            nx_icmp_interface_ping6.c         Fixed a bug for sequence when nx_ip_icmp_sequence is greater than 65535.
            nx_icmpv4_packet_process.c        Fixed checksum zero for echo reply packet.
            nx_icmpv6_DAD_failure.c           Fixed a bug that address was not removed from interface.
            nx_icmpv6_perform_DAD.c           Optimized process logic.
            nx_icmpv6_send_error_message.c    Fixed endianness of the offending packet, fixed handling multicast packet,
                                                added logic to ensure data to copy does not exceed the ICMPv6 packet boundary.
            nx_icmpv6_send_queued_packets.c   Fixed the bug for unspecified address check.
                                              Cleaned up the nd_entry after fragment processing.
            nx_icmpv6_packet_process          Modified the logic of checksum calculation.
            nx_icmpv6_dest_table_add.c        Protected cache with mutex nx_nd_cache_protection.
            nx_icmpv6_process_redirect.c      Protected cache with mutex nx_nd_cache_protection.
            nx_ip.h                           Added new service nx_ip_gateway_clear,
                                                added function to compute checksum for fragments,
            nx_ipv4.h                         Added new service nx_ip_gatewar_clear.
            nx_ip_create.c                    Supported loopback interface capability,
            nx_ip_checksum_compute.c          Optimized the logic.
                                                fixed a bug when the priority of the calling thread is lower than IP thread.
            nx_ip_fragment_assembly.c         Added definition of reassembly time, fixed a bug in fragment queue.
            nx_ip_fragment_packet.c           Fixed checksum calculation when fragment is performed,
                                                copied interface from header packet, fixed size of each fragment,
                                                fixed a bug that NX_DISABLE_IP_TX_CHECKSUM option was ignored.
            nx_ip_fragment_timeout_check.c    Fixed the endian of offset flag before sending ICMPv6 error message.
                                                Fixed a problem with reset of the tail fragment.
                                                Fixed an error for reconnecting around a dropped fragment.
            nx_ip_gateway_address_set.c       Modified the logic to disallow a zero IP address.
            nx_ip_packet_receive.c            Added packet drop statisics for invalid packet.
            nx_ip_packet_send.c               Fixed destination address for non local network,
                                                fixed a bug in loopback interface processing,
                                                optimized the logic,
            nx_ip_route_find.c                Fixed a bug in loopback interface processing,
                                                skipped interface which is down when finding route and gateway.
            nx_ip_raw_packet_processing.c     Fixed a bug that interrupt is not restored when no thread waiting for packets.
            nx_ip_static_route_add.c          Fixed a bug that route table may overflow,
                                                added interface record when shifting route entries,
                                                fixed a bug that unsigned number overflows.
            nx_ip_static_route_delete.c       Added interface record when shifting route entries.
            nx_ip_max_payload_size_find.c     Fixed a bug that src_address was set incorrectly,
                                                removed unnecessary check for NULL pointer of IPv6 address.
            nx_ipv4_packet_receive.c          Supported processing fragmentation immediately,
                                                supported checking for source IP address.
                                                added a feature that receive unicast DHCP message.
            nx_ipv6_fragment_process.c        Fixed checksum calculation when fragment is performed,
                                                used the same packet pool for original packet and fragmentations.
                                              Increased the IP packet and bytes sent count.
            nx_ipv6_packet_copy.c             Fixed copy length check for destination packet.
            nx_ipv6_packet_send.c             Fixed checksum calculation when fragment is performed, optimized the logic.
            nx_ipv6_prefix_list_delete_entry.c
                                              Fixed IPv6 address when leave multicast group.
            nx_ipv6_process_fragment_option.c Supported processing fragmentation immediately,
                                                fixed the endian of offset flag before sending ICMPv6 error message.
            nxd_ip_raw_packet_source_send.c   Fixed source address selection for IPv6.
            nxd_ipv6_address_set.c            Fixed duplicate address set, fixed a bug when ip_address is null.
            nxd_ipv6_default_router_add_internal.c
                                              Checked router address whether it is reachable.
            nxd_ipv6_default_router_get.c     Got index from interface.
            nxd_ipv6_default_router_number_of_entries_get.c
                                              Got index from interface.
            nxd_ipv6_disable.c                Supported loopback address. Fixed a compiler error.
            nxd_ipv6_enable.c                 Supported loopback address.
            nxd_ipv6_interface_find.c         Fixed return status when there is no address in interface,
                                                supported loopback address, checked interface link status.
            nxd_ipv6_raw_packet_send_internal.c
                                              Fixed source address selection for IPv6.
            nxd_ipv6_stateless_address_autoconfig_enable.c
                                              Reset the solicitation count.
            nxd_ipv6_stateless_address_autoconfig_disable.c
                                              Reset the solicitation count.
            nxd_ipv6_multicast_interafce_leave.c
                                              Fixed the bug that return success status when find the same entry.
            nx_nd_cache.h                     Updated time of ND cache to RFC recommended values.
            nx_nd_cache_add.c                 Protected cache with mutex nx_nd_cache_protection.
            nx_nd_cache_find_entry.c          Removed the mutex release that is not necessary.
            nx_nd_cache_find_entry_by_mac_addr.c
                                              Fixed a bug that check the interface pointer before use.
            nxd_nd_cache_entry_delete.c       Fixed a bug that mutex is not released before return.
            nx_packet_copy.c                  Removed the size check to avoid failure to copy for chain packet.
            nx_packet_data_extract_offset.c   Used memcpy to optmize data copy.
            nx_packet_data_retrieve.c         Used memcpy to optmize data copy.
            nx_packet_data_append.c           Fixed a bug that releases already released packet.
            nx_packet_pool_create.c           Cleared pool structure before used.
            nx_tcp_mss_option_get.c           Fixed endless loop when option length is not set.
            nx_tcp_packet_process.c           Checked source address for syn packets that are queued.
            nx_tcp_server_socket_relisten.c   Fixed a bug that syn_received_notify was not called.
            nx_tcp_socket_delete.c            Not allowed to delete before resources are cleaned.
            nx_tcp_socket_packet_process.c    Fixed a bug ACKs, URGs, RSTs should be processed even sequence
                                                is out of window.
            nx_tcp_socket_send.c:             Moved process logic to internal function.
            nx_tcp_socket_send_internal.c     Fixed a bug when socket is not connected, supported
                                                to send small segmentation when length of packet is less than window size.
            nx_tcp_socket_state_ack_check.c   Fixed cwnd calculation. Fixed window size when ACK is duplicated.
            nx_tcp_socket_state_data_check.c  Supported to limit the number of packets that are out of order.
            nx_tcp_socket_state_transmit_check.c
                                              Moved logic when window size is non zero to send internal function.
            nx_tcp_transmit_cleanup.c         Removed adjusting sequence since packet in queue would
                                                never contain TCP header.
            nx_user.h                         Added definition for IP reassembly time,
                                                added symbol that allow IP fragment reassemble immediately,
                                                updated time of ND cache to RFC recommended values,
                                                added source address check for incoming packet,
                                                supported to limit the number of packets that are out of order.
            nx_udp_packet_receive.c           Fixed the endian of UDP header before sending ICMPv6 error message.
            nx_udp_socket_delete.c            Removed error checking that has been checked in nxe.
            nx_udp_socket_receive.c           Set packet pointer to NULL if no packet was available.
                                                Removed special process of all ones checksum.
            nxd_udp_socket_send.c             Fixed source address selection for IPv6.
            nxe_icmp_interface_ping6.c        Checked interface validity.
            nxde_icmp_source_ping.c           Checked interface validity.
            nxe_igmp_multicast_interface_join.c
                                              Fixed the bug for IP protectio operation.
            nxe_ip_gateway_address_set.c
                                              Added the interface status check.
            nxe_ip_interface_attach.c         Modified invalid IP address check.
            nxe_ip_interface_physical_address_get.c
                                              Fixed a dead recursive call bug.
            nxe_ip_interface_status_check.c   Added interface validation checking.
            nxde_ip_raw_packet_source_send.c  Fixed address_index check.
            nxde_ipv6_stateless_address_autoconfig_enable.c
                                              Modified the comment and fixed the bug.
            nxde_ipv6_stateless_address_autoconfig_disable.c
                                              Modified the comment and fixed the bug.
            nxde_ipv6_multicast_interface_leave.c
                                              Modified the comment and fixed the bug.
            nxde_ipv6_multicast_interface_join.c
                                              Modified the comment and fixed the bug.
            nxde_ipv6_default_router_number_of_entries_get.c
                                              Modified the comment and fixed the bug.
            nxde_ipv6_default_router_get.c
                                              Modified the comment and fixed the bug.
            nxde_ipv6_default_router_entry_get.c
                                              Modified the comment and fixed the bug.
            nxde_ipv6_address_delete.c
                                              Modified the comment and fixed the bug.
            nxde_nd_cache_entry_set           Added the ID check for IP instance.
            nxe_packet_release.c              Modified the return value.
            nxe_packet_transmit_release.c     Modified the return value.
            nxe_tcp_client_socket_connect.c   Added server address check,
            nxe_tcp_socket_queue_depth_notify_set.c
                                              Added input parameters check,
            nxe_tcp_socket_receive_notify.c   Added input parameters check,
            nxe_tcp_socket_transmit_configure.c
                                              Added tcp feature check,
            nxe_tcp_socket_window_update_notify_set.c
                                              Added input parameters check,
            nxe_udp_socket_source_send.c      Improved the error checking logic.
            nx_ram_network_driver.c           Received special MAC address for IPv6 multicast address,
                                              Correctly set the next IP.

        Files added:
            nx_ip_gateway_address_clear.c
            nx_ip_interface_detach.c
            nx_ip_packet_checksum_compute.c
            nxe_ip_gateway_address_clear.c
            nxe_ip_interface_detach.c





01/31/2013  NetX Duo generic code version 5.7. This release includes the
            following major features:


        Files are modified to allow conditional compilation for IP fragmentation support:
            nx_arp_dynamic_entry_set.c
            nx_arp_packet_receive.c
            nx_ip_fragment_disable.c
            nx_ip_fragment_enable.c
            nx_ip_fragment_packet.c
            nx_ip_fragment_timeout_check.c
            nx_ip_info_get.c
            nx_ip_packet_send.c
            nx_ipv6_packet_send.c
            nx_ipv6_process_fragment_option.c


        Files are added or modified to support the interface capability feature:
            nx_icmp_interface_ping6.c
            nx_icmp_ping.c
            nx_icmpv4_packet_process.c
            nx_icmpv6_packet_process.c
            nx_icmpv6_process_echo_request.c
            nx_icmpv6_process_ns.c
            nx_icmpv6_send_error_message.c
            nx_icmpv6_send_ns.c
            nx_icmpv6_send_rs.c
            nx_igmp_multicast_leave.c
            nx_igmp_packet_process.c
            nx_igmp_periodic_processing.c
            nx_ip_checksum_compute.c
            nx_ip_interface_capability_get.c
            nx_ip_interface_capability_set.c
            nx_ip_fragment_packet.c
            nx_ip_packet_send.c
            nx_ip_thread_entry.c
            nx_ipv4_packet_receive.c
            nx_ipv6_packet_send.c
            nx_packet_allocate.c
            nx_packet_copy.c
            nx_packet_release.c
            nx_tcp_packet_process.c
            nx_tcp_packet_send_fin.c
            nx_tcp_packet_send_rst.c
            nx_tcp_packet_send_syn.c
            nx_tcp_socket_send_internal.c
            nx_udp_socket_receive.c
            nxd_udp_socket_send.c
            nxe_ip_interface_capability_get.c
            nxe_ip_interface_capability_set.c


        Files are modified to allow the chained packet feature to be removed:
            nx_packet_allocate.c
            nx_packet_copy.c
            nx_packet_data_append.c
            nx_packet_data_extract_offset.c
            nx_packet_data_retrieve.c
            nx_packet_release.c


        Files are added or modified to support the IPv6 address change notify feature:
            nx_icmpv6_DAD_failure.c
            nx_icmpv6_perform_DAD.c
            nx_icmpv6_process_ra.c
            nx_ipv6_prefix_list_delete.c
            nx_ipv6_prefix_list_delete_entry.c
            nxd_ipv6_address_change_notify.c
            nxd_ipv6_address_delete.c
            nxd_ipv6_address_set.c
            nxde_ipv6_address_change_notify.c


        Files are added or modified to support the IP raw filter feature and
        the raw receive queue depth feature:
            nx_ip_raw_packet_enable.c
            nx_ip_raw_packet_filter_set.c
            nx_ip_raw_packet_processing.c
            nx_ip_raw_receive_queue_max_set.c
            nxe_ip_raw_packet_filter_set.c
            nxe_ip_raw_receive_queue_max_set.c


        Files are modified to reset the TCP internal timer when closing a socket:
            nx_tcp_client_socket_unbind.c
            nx_tcp_server_socket_accept.c
            nx_tcp_server_socket_listen.c
            nx_tcp_server_socket_relisten.c
            nx_tcp_server_socket_unaccept.c
            nx_tcp_server_socket_unlisten.c
            nx_tcp_socket_state_fin_wait2.c
            nx_tcp_socket_state_syn_received.c


        Other modified files:
          nx_arp_enable.c                         Cleaned up redundant logic.
          nx_icmpv6_dest_table_add.c              Protected cache with mutex nx_nd_cache_protection.
          nx_icmpv6_process_na.c                  Modified the logic to set incoming interface to be the
                                                    address requested in the NA message.
          nx_icmpv6_process_redirect.c            Protected cache with mutex nx_nd_cache_protection.
          nx_icmpv6_send_queued_packets.c         Convert destination address to host byte order before
                                                    calling nx_icmpv6_dest_table_find.
          nx_igmp_periodic_processing.c           Fixed a bug preventing the loop from decrementing all
                                                    group update times.
          nx_ip_create.c                          Initializes the device table and the address table.
          nx_ip_dispatch_process.c                Added upper layer protocol processing for IPv4
          nx_ip_driver_direct_command.c           Modified function name
          nx_ip_fragment_assembly.c               Simplified the logic by calling nx_ip_dispatch_process()
                                                    for processing upper layer protocols.
          nx_ip_fragment_packet.c                 Removed an extra alignment check
          nx_ip_max_payload_size_find.c           Added a case for IPsec
          nx_ip_raw_packet_source_send.c          Modified the constant for the raw packet type
          nx_ip_raw_packet_send.c                 Modified the constant for the raw packet type
          nx_ip_static_route_add.c                Record the physical interface the route is attached to.
          nx_ipv4_packet_receive.c                Simplified the logic by calling nx_ip_dispatch_process()
                                                    for processing upper layer protocols.
          nx_ipv6_fragment_process.c              Fixed a compiler warning.
          nx_ipv6_packet_receive.c                Added IPv6 multicast support
          nx_ipv6_packet_send.c                   Fixed a bug in the logic that does the IPv6 address
                                                    search, added a case where IPv6 address to MAC address
                                                    mapping is not needed.
          nx_ipv6_prefix_list_delete.c            Optimized the logic that computes the interface index.
          nx_ipv6_util.c                          Fixed the all router multicast address.
          nx_nd_cache_add.c                       Fixed compiler warnings, protected cache with mutex
                                                    nx_nd_cache_protection.
          nx_nd_cache_find_entry.c                Fixed a bug where an incorrect index value is used,
                                                    removed mutex release that is not necessary.
          nx_tcp_fast_periodic_processing.c       Fixed a bug that prevents TCP retry limit to be reached.
          nx_tcp_no_connection_reset.c            Fixed for IPsec.
          nx_tcp_packet_process.c                 Validate MSS value, validate IP address, added internal
                                                    callback function.
          nx_tcp_socket_disconnecte.c             Corrected TCP ACK number when sending a RST.
          nx_tcp_socket_packet_process.c          Improved the handling of validating incoming TCP
                                                    segments.
          nx_tcp_socket_receive.c                 Corrected the logic checking the receive queue against
                                                    the TCP socket state.
          nx_tcp_socket_send.c                    Added logic to handle error status returned from
                                                    nx_tcp_socket_internal to fix a packet leak.
          nx_tcp_socket_state_ack_check.c         Fixed a bug determining if packets can be released from
                                                    the queue when the transmit window wraps, also
                                                    modified the return value.
          nx_tcp_socket_state_data_check.c        Optimized the logic for handling incoming TCP data
                                                    segments.
          nx_tcp_socket_state_syn_received.c      Updated the acknowledged receive sequence.
          nx_tcp_socket_state_syn_sent.c          Fixed a logic for invalid ACK check.
          nx_udp_packet_receive.c                 Fixed compiler warnings.
          nx_udp_socket_source_send.c             Removed redundant code.
          nxd_ip_raw_packet_sourcee_send.c        Added additional parameters this service takes.
          nxd_ip_raw_packet_send.c                Added additional parameters this service takes.
          nxd_ipv6_address_get.c                  Simplified the logic that finds the address index.
          nxd_ipv6_default_router_add_internal.c  Fixed compiler warning.
          nxd_ipv6_interface_find.c               Added IPv6 multicast support, added a case where the
                                                    destination address is an offlink address.
          nxd_ipv6_router_solicitation_check.c    Cleaned up a line of statement.
          nxd_nd_cache_entry_set.c                Bug fix: Use IPv6 address index to find physical
                                                    interface.
          nxd_udp_packet_info_extract.c           Simplified the logic that finds the interface index.
          nxd_udp_socket_send.c                   Making sure the checksum is always generated for
                                                    IPv6 packets.
          nxd_udp_socket_source_send.c            Fixed the IP address detection logic.
          nxde_ip_raw_packet_source_send.c        Added additional parameters this service takes.
          nxde_ip_raw_packet_send.c               Added additional parameters this service takes.


       Files added:
          nx_ip_gateway_address_get.c
          nx_ip_interafce_address_mapping_configure.c
          nx_ip_interface_mtu_set.c
          nx_ip_interface_physical_address_get.c
          nx_ip_interface_physical_address_set.c
          nx_tcp_socket_queue_depth_notify_set.c
          nxd_ipv6_default_router_entry_get.c
          nxd_ipv6_default_router_number_of_entries_get.c
          nxd_ipv6_disable.c
          nxd_ipv6_multicast_interface_join.c
          nxd_ipv6_multicast_interafce_leave.c
          nxd_ipv6_stateless_address_autoconfig_disable.c
          nxd_ipv6_stateless_address_autoconfig_enable.c
          nxde_ipv6_default_router_entry_get.c
          nxde_ipv6_default_router_number_of_entries_get.c
          nxde_ipv6_disable.c
          nxde_ipv6_stateless_address_autoconfig_disable.c
          nxde_ipv6_stateless_address_autoconfig_enable.c
          nxde_ipv6_multicast_interface_join.c
          nxde_ipv6_multicast_interface_leave.c
          nxe_ip_gateway_address_get.c
          nxe_ip_interface_mtu_set.c
          nxe_ip_interface_physical_address_get.c
          nxe_ip_interface_physical_address_set.c
          nxe_tcp_socket_queue_depth_notify_set.c

       Files renamed:

               File Name in Release 5.6                              File Name in Release 5.7

           nx_ip_raw_packet_interface_send.c                      nx_ip_raw_packet_source_send.c
           nx_udp_socket_interface_send.c                         nx_udp_socket_source_send.c
           nxd_ip_raw_packet_interface_send.c                     nxd_ip_raw_packet_source_send.c
           nxd_udp_socket_interface_send.c                        nxd_udp_socket_source_send.c
           nxd_icmp_interface_ping.c                              nxd_icmp_source_ping.c
           nxe_ip_raw_packet_interface_send.c                     nxe_ip_raw_packet_source_send.c
           nxe_udp_socket_interface_send.c                        nxe_udp_socket_source_send.c
           nxde_ip_raw_packet_interface_send.c                    nxde_ip_raw_packet_source_send.c
           nxde_udp_socket_interface_send.c                       nxde_udp_socket_source_send.c
           nxde_icmp_interface_ping.c                             nxde_icmp_source_ping.c





10/10/2011  NetX generic code version 5.6. This release includes the following major features:

          * IPv4 and IPv6 multihome support
          * TCP window scaling
          * Allow applications to configure TCP Keep-alive feature on a per-socket basis
          * Added support for TCP state change callback functions.
          * Allow ICMP checksum operation to be removed
          * Added support for IPsec

        Files modified in order to support multihome
            nx_api.h
            nx_arp.h
            nx_arp_dynamic_entries_invalidate.c
            nx_arp_dynamic_entry_set.c
            nx_arp_gratuitous_send.c
            nx_arp_packet_receive.c
            nx_arp_packet_send.c
            nx_arp_periodic_update.c
            nx_arp_static_entry_create.c
            nx_icmp.h
            nx_icmp_ping.c
            nx_icmp_ping6.c
            nx_icmpv6.h
            nx_icmpv6_DAD_failure.c
            nx_icmpv6_packet_process.c
            nx_icmpv6_process_echo_request.c
            nx_icmpv6_process_na.c
            nx_icmpv6_process_ns.c
            nx_icmpv6_process_ra.c
            nx_icmpv6_send_error_message.c
            nx_icmpv6_send_ns.c
            nx_icmpv6_send_queued_packets.c
            nx_icmpv6_send_rs.c
            nx_icmpv5_packet_process.c
            nx_igmp.h
            nx_igmp_multicast_check.c
            nx_igmp_multicast_join.c
            nx_igmp_multicast_leave.c
            nx_ip.h
            nx_ip_create.c
            nx_ip_delete.c
            nx_ip_dispatch_process.c
            nx_ip_driver_direct_command.c
            nx_ip_fragment_packet.c
            nx_ip_gateway_address_set.c
            nx_ip_max_payload_size_find.c
            nx_ip_packet_receive.c
            nx_ip_packet_send.c
            nx_ip_status_check.c
            nx_ip_thread_entry.c
            nx_ip_static_route_add.c
            nx_ipv4.h
            nx_ipv4_packet_receive.c
            nx_ipv6.h
            nx_ipv6_address_find_prefix.c
            nx_ipv6_fragment_process.c
            nx_ipv6_multicast.c
            nx_ipv6_packet_receive.c
            nx_ipv6_packet_send.c
            nx_ipv6_prefix_list_delete_entry.c
            nx_nd_cache.h
            nx_nd_cache_add.c
            nx_packet_allocate.c
            nx_packet_copy.c
            nx_ram_network_driver.c
            nx_tcp_fast_periodic_processing.c
            nx_tcp_packet_process.c
            nx_tcp_packet_send_ack.c
            nx_tcp_packet_send_fin.c
            nx_tcp_packet_send_syn.c
            nx_tcp_socket_mss_set.c
            nx_tcp_socket_send.c
            nx_tcp_socket_state_transmit_check.c
            nx_udp.h
            nx_udp_socket_create.c
            nxd_ip_raw_packet_send.c
            nxd_ipv6_default_router_add.c
            nxd_ipv6_router_solicitation_check.c
            nxd_nd_cache_entry_set.c
            nxd_nd_cache_ip_address_find.c
            nxd_udp_socket_send.c
            nxde_ipv6_default_router_add.c
            nxde_nd_cache_entry_set.c
            nxde_nd_cache_ip_address_find.c
            nxe_arp_gratuitous_send.c
            nxe_igmp_multicast_join.c
            nxe_ip_gateway_address_set.c
            nxe_ip_status_check.c
            nxe_tcp_socket_send.c

        Files changed to allow optionally exclude the ICMPv6 Error Messages feature
            nx_icmpv6.h
            nx_icmpv6_send_error_message.c
            nx_ip_dispatch_process.c
            nx_ip_fragment_assembly.c
            nx_ip_fragment_timeout_check.c
            nx_ipv6_process_fragment_option.c
            nx_ipv6_process_routing_option.c
            nx_udp_packet_receive.c
            nx_user.h

        Files changed to support TCP window scaling:
            nx_tcp.h
            nx_tcp_mss_option_get.c
            nx_tcp_packet_process.c
            nx_tcp_packet_send_ack.c
            nx_tcp_packet_send_fin.c
            nx_tcp_packet_send_syn.c
            nx_tcp_socket_create.c
            nx_tcp_socket_send.c
            nx_tcp_socket_state_ack_check.c
            nx_tcp_socket_state_data_check.c
            nx_tcp_socket_state_syn_sent.c
            nx_tcp_socket_state_syn_received.c
            nx_user.h
            nxe_tcp_socket_create.c


        Files changed to support per-socket keepalive option:
            nx_tcp_periodic_processing.c
            nx_tcp_socket_create.c
            nx_tcp_socket_state_ack_check.c
            nx_tcp_socket_state_established.c
            nx_tcp_socket_state_syn_received.c
            nx_tcp_socket_state_syn_sent.c

        Files changed to support TCP state change callback functions:
            nx_tcp.h
            nx_tcp_socket_connection_reset.c
            nx_tcp_socket_create.c
            nx_tcp_socket_state_fin_wait1.c
            nx_tcp_socket_state_fin_wait2.c
            nx_tcp_socket_state_last_ack.c
            nx_tcp_socket_state_syn_received.c

        Added a check to make sure this function only operates on an entry owned by ip_ptr.
            nx_nd_cache_fast_periodic_update.c
            nx_nd_cache_find_entry_by_mac_addr.c
            nx_nd_cache_find_entry_and_add.c
            nx_nd_cache_find_entry.c
            nx_nd_cache_slow_periodic_update.c

        Files changed to allow ICMP checksum operation to be removed:
            nx_icmp_ping.c
            nx_icmpv4_packet_process.c
            nx_icmpv6_process_echo_request.c
            nx_icmpv6_process_ns.c
            nx_icmpv6_send_error_message.c
            nx_icmpv6_send_ns.c
            nx_icmpv6_send_rs.c


        Files changed to support IPsec:
            nx_icmp_ping.c
            nx_icmpv4_packet_process.c
            nx_icmpv6_DAD_clear_NDCache_entry.c
            nx_icmpv6_DAD_failure.c
            nx_icmpv6_packet_process.c
            nx_icmpv6_perform_DAD.c
            nx_icmpv6_process_echo_reply.c
            nx_icmpv6_process_echo_request.c
            nx_icmpv6_process_na.c
            nx_icmpv6_process_ns.c
            nx_icmpv6_send_error_message.c
            nx_icmpv6_validate_neighbor_message.c
            nx_ip_dispatch_process.c
            nx_ip_max_payload_size_find.c
            nx_ip_packet_send.c
            nx_ip_thread_entry.c
            nx_ipv4_packet_receive.c
            nx_ipv6_packet_send.c
            nx_ipv6_perform_min_path_MTU_discovery.c
            nx_packet_allocate.c
            nx_packet_copy.c
            nx_tcp_no_connection_reset.c
            nx_tcp_packet_send_ack.c
            nx_tcp_packet_send_fin.c
            nx_tcp_packet_send_rst.c
            nx_tcp_packet_send_syn.c
            nx_tcp_socket_create.c
            nx_tcp_socket_send_internal.c
            nx_udp_packet_receive.c
            nxd_udp_socket_send.c
            nxe_ip_max_payload_size_find.c

        Other modified files:
            nx_api.h                              Added macro NX_PACKET_HEADER_PAD_SIZE to allow an application
                                                  to specify the number of ULONG words padded towards the end of the
                                                  NX_PACKET structure, giving the starting address of the paylaod
                                                  area to a desired alignment.
            nx_icmpv6_dest_table_find.c           Allowed this function to update the path MTU information
            nx_icmpv6_destination_table_periodic_update.c
                                                  Upadted the path MTU logic, optimized the search process
            nx_icmpv6_perform_DAD.c               Added an option that allows caller to specify an IPv6 address for DAD.
            nx_icmpv6_process_echo_reply.c        Added ICMP statistical counter, removed ICMP header before passing the packet
                                                  to the thread
            nx_icmpv6_process_na.c                Optimized the NA packet process
            nx_icmpv6_process_ra.c                Optimized the destination table operation, added ICMP counters
            nx_icmpv6_process_redirect.c          Added ICMP statistical counter, optimized internal operation
            nx_igmp_loopback_disable.c            Added mutex protection
            nx_igmp_loopback_enable.c             Added mutex protection
            nx_igmp_packet_process.c              Allowed IGMP statistical counters to be compiled out,
                                                  impoved the handling of IGMPv1 packets
            nx_ip_address_change_notify.c         Added mutex protection
            nx_ip_address_get.c                   Added mutex protection
            nx_ip_address_set.c                   Added mutex protection
            nx_ip_checksum_compute.c              Fixed a compiler warning when the IPv6 feature is not enabled
            nx_ip_delete.c:                       Clear the nx_ip_id field after the IP internal is cleaned up.
            nx_ip_gateway_address_set.c           Added missing mutex release if no interface found, allow the gateway to be cleared
            nx_ip_fragment_assembly.c             Improved fragment matching per RFC 791, fixed a compiler warning
            nx_ip_packet_receive.c                Added VOID* cast to avoid compiler warnings.
            nx_ip_packet_send.c                   Added check for non null packet interface or next hop (e.g. gateway)
                                                  Fixed a bug where the prepend_ptr was incorrectedly adjusted before
                                                  calling nx_packet_transmit_release.
            nx_ipv6.h                             Added and modified internal API prototypes
            nx_ipv6_fragment_process.c            Release all fragments when discarding a fragment
                                                  Added counter for total_fragments sent.
            nx_ipv6_packet_send.c                 Fixed a bug where the prepend_ptr was incorrectedly adjusted before
                                                  calling nx_packet_transmit_release.
            nx_ipv6_util.h                        Optimized internal operations, added a check for the FF05:: multicast range
            nx_ip_status_check.c:                 Added the configurable wait option NX_IP_STATUS_CHECK_WAIT_TIME
            nx_ipv6_option_error.c                simplify the logic
            nx_ipv6_packet_copy.c                 Fixed a compiler warning
            nx_nd_cache_delete_internal.c         Optimized the destination table search process
            nx_packet_release                     Removed an IPv6 conditional compilation so the IP version field is cleaned up
            nx_rarp_packet_receive.c              Added initialization to avoid compiler warnings
            nx_tcp_mss_option_get.c               Corrected the logic in the option length calculation.
            nx_tcp_no_connection_reset.c          Added a parameter to indicate source IPv6 address to use when sending the RST packet.
            nx_tcp_packet_send_ack.c              Skip TCP checksum calculation if the feature is turned off.
            nx_tcp_packet_send_fin.c              Skip TCP checksum calculation if the feature is turned off.
            nx_tcp_packet_send_rst.c              Skip TCP checksum calculation if the feature is turned off.
            nx_tcp_packet_send_syn.c              Skip TCP checksum calculation if the feature is turned off.
            nx_tcp_socket_packet_process.c        Added check for acceptable RST, moved TCP header optino process into nx_tcp_packet_process
            nx_tcp_periodic_process.c             Added per-socket keep-alive feature.
            nx_tcp_socket_receive                 Optimized internal logic, added netX trace event
                                                  Modified logic to always return a packet in the receive queue regardless of the TCP socket state
            nx_tcp_server_socket_accept.c         Clean up the socket data structure before responding to a new conenction.
            nx_tcp_socket_state_closing.c         Validate the ACK and SEQ number before closing down the socket
            nx_tcp_socket_state_ack_check.c       Fixed a corner case where the ACK number was incorrectly checked
                                                  Fixed another corner case when determining if packets can be released from the transmit queue
                                                  where the transmit window is wrapped.
            nx_udp_packet_receive.c               Optimized internal operations
            nx_udp_socket_bytes_available:        Modified output to error status if the socket port is not bound, corrected return value, fixed comiler warnings
            nx_udp_socket_receive.c               Removed redundant calls to checksum
            nx_user.h                             Added options to remove ICMP checksum computation
            nxd_icmp_enable.c                     Added mutex protection, optimized initilization process
            nxd_ipv6_find_max_prefix_length.c     Optimized the search algorithm
            nxd_ipv6_prefix_router_timer_tick.c   Clean up the destination table when a router times out
            nxd_ipv6_router_lookup.c              Check nd_cache_entry being valid before dereferencing it,
            nxd_ipv6_router_solicitation_check.c  Check router entry valid before updating its timer value optimized the router table search algorithm
            nxd_ipv6_search_onlink.c              Also search manually configured Ipv6 addresses for onlink nodes
            nxd_nd_cache_entry_delete.c           Make sure the ND cache entry exists before deleting it, also invalidated the destination table entry
            nxd_tcp_client_socket_connect.c       Do socket cleanup before sending the SYN packet
            nxde_ip_raw_packet_send.c             Added more error checking logic
            nxde_udp_socket_send.c                Added more error checking logic
            nxe_ip_gateway_address_set.c          Removed a requirement that ARP be enabled before setting IPv4 gateway address and
                                                  removed requirement that the service must be called from a thread
            nxe_ip_max_payload_size_find.c        Replaced source address with an index to the source address
            nxe_ip_static_route_add.c             Added a check to make sure the next hop address is directly reachable.
            nxe_ip_static_route_delete.c          Removed unused code
            nxe_packet_release.c                  Removed unreachable code
            nxe_packet_transmit_release.c         Removed unreachable code


        Files added:
            demo_netx_duo_multihome_tcp.c
            demo_netx_duo_multihome_udp.c
            nx_icmp_interface_ping6.c
            nx_icmpv6_dest_table_add.c
            nx_icmpv6_process_packet_too_big.c
            nx_igmp_multicast_interface_join.c
            nx_ip_driver_interface_direct_command.c
            nx_ip_interface_address_get.c
            nx_ip_interface_address_set.c
            nx_ip_interface_attach.c
            nx_ip_interface_info_get.c
            nx_ip_interface_status_check.c
            nx_ip_raw_packet_interface_send.c
            nx_ip_route_find.c
            nx_nd_cache_add_entry.c
            nx_packet_data_extract_offset.c
            nx_tcp_socket_disconnect_complete_notify.c
            nx_tcp_socket_establish_notify.c
            nx_tcp_socket_send_internal.c
            nx_tcp_socket_timed_wait_callback.c
            nx_tcp_window_scaling_option_get.c
            nx_udp_packet_info_extract.c
            nx_udp_socket_interface_send.c
            nxd_icmp_interface_ping.c
            nxd_ip_raw_packet_interface_send.c
            nxd_ipv6_address_delete.c
            nxd_ipv6_address_get.c
            nxd_ipv6_address_set.c
            nxd_ipv6_default_router_get.c
            nxd_udp_socket_interface_send.c
            nxde_icmp_interface_ping.c
            nxde_ip_raw_packet_interface_send.c
            nxde_ipv6_address_delete.c
            nxde_ipv6_address_get.c
            nxde_ipv6_address_set.c
            nxde_ipv6_default_router_get.c
            nxde_udp_packet_info_extract.c
            nxde_udp_socket_interface_send.c
            nxe_icmp_interface_ping6.c
            nxe_igmp_multicast_interface_join.c
            nxe_ip_driver_interface_direct_command.c
            nxe_ip_interface_address_get.c
            nxe_ip_interface_address_set.c
            nxe_ip_interface_attach.c
            nxe_ip_interface_info_get.c
            nxe_ip_interface_status_check.c
            nxe_ip_raw_packet_interface_send.c
            nxe_packet_data_extract_offset.c
            nxe_tcp_socket_disconnect_complete_notify.c
            nxe_tcp_socket_establish_notify.c
            nxe_tcp_socket_timed_wait_callback.c
            nxe_udp_packet_info_extract.c
            nxe_udp_socket_interface_send.c


        Files removed:
            nx_icmpv6_dest_table_find_and_add.c
            nx_icmpv6_dest_table_find_and_add.c
            nx_ip_static_routing_disable.c
            nx_ip_static_routing_enable.c
            nx_ipv6_process_packet_too_big.c
            nx_nd_cache_find_entry_and_add.c
            nxd_ipv6_interface_address_get.c
            nxd_ipv6_interface_address_set.c
            nxd_ipv6_linklocal_address_get.c
            nxd_ipv6_linklocal_address_set.c
            nxd_udp_socket_set_interface.c
            nxde_ipv6_interface_address_get.c
            nxde_ipv6_interface_address_set.c
            nxde_ipv6_linklocal_address_get.c
            nxde_ipv6_linklocal_address_set.c
            nxde_udp_socket_set_interface.c
            nxe_ip_static_routing_disable.c
            nxe_ip_static_routing_enable.c,


06/01/2010  NetX generic code version 5.5. This release includes the following major features:
            Path MTU Discovery and IPv6 Advertised Link MTU
            Internal debug modules removed (replaced with TraceX events)

            Other modifications are:

            nx_icmpv6_process_ra.c                   Path MTU support
                                                     Fixed bug in Neighbor Discovery cache processing
            nx_icmpv6_process_redirect.c             Path MTU support
            nx_icmpv6_send_error_message.c           Path MTU support
            nx_icmpv6_send_queued_packets.c          Path MTU support
                                                     Fixed a bug where NA packet is received how queued packets requiring fragmentation are sent
            nx_ip_static_route_add.c                 Renamed define NX_IP_STATIC_ROUTING_SUPPORTED to NX_ENABLE_IP_STATIC_ROUTING
            nx_ip_static_route_delete.c              Renamed define NX_IP_STATIC_ROUTING_SUPPORTED to NX_ENABLE_IP_STATIC_ROUTING
            nx_ip_static_route_find.c                Renamed define NX_IP_STATIC_ROUTING_SUPPORTED to NX_ENABLE_IP_STATIC_ROUTING
            nx_ip_static_route_enable.c              Renamed define NX_IP_STATIC_ROUTING_SUPPORTED to NX_ENABLE_IP_STATIC_ROUTING
            nx_ip_static_route_disable.c             Renamed define NX_IP_STATIC_ROUTING_SUPPORTED to NX_ENABLE_IP_STATIC_ROUTING
            nx_ip_thread_entry.c                     Path MTU support
            nx_ipv6_packet_send.c                    Path MTU support
                                                     Added a check if source and destination IP addresses are the same as part of Denial of service attack,
                                                     Added check for suitable next hop; no packet transmitted if not found by routing algorithm */
                                                     Fixed bug how multicast packets are detected
            nx_tcp_packet_process.c                  Modified RST packets sent in response to invalid data packets to include proper ACK number
            nx_tcp_packet_send_rst.c                 Send a RST with proper ACK number in response to invalid data packet.
            nx_tcp_socket_packet_process.c           Removed duplicate logic that detects and sets MSS number from peer
                                                     Added logic for sending ACKs for out-of-order packet
                                                     Added check for duplicated SYNs
            nx_tcp_socket_state_data_check.c         Modified to send ACKs for out-of-order data packets
                                                     modified handling invalid RST control message
                                                     Added check for duplicated incoming SYNs
                                                     Fixed bug (corner case) handling overlapping sequence numbers
                                                     Make _nx_tcp_socket_state_data_trim and _nx_tcp_socket_state_data_trim_front
                                                     non-static function.
            nx_tcp_socket_state_syn_sent.c           Modified detection and handling of unacceptable ACK before sending RST packet
            nxd_icmp_enable.c                        Path MTU support
            nxd_ipv6_enable.c                        Replaced literal router solicitation parameters with macros defined in nx_user.h
            nxd_ipv6_find_max_prefix_length.c        Optimized the prefix match algorithm
            nxd_udp_socket_send.c                    Corrected placement of IPSec ENABLED conditional code,
                                                     Added check for IPv6 logical outgoing interface
            nxe_ip_static_routing_disable.c          Renamed define NX_IP_STATIC_ROUTING_SUPPORTED to NX_ENABLE_IP_STATIC_ROUTING
            nxe_ip_static_routing_enable.c           Renamed define NX_IP_STATIC_ROUTING_SUPPORTED to NX_ENABLE_IP_STATIC_ROUTING
            nx_icmpv6.h                              Path MTU support
            nx_nd_cache.h                            Removed unused defines for Router and ND protocols
            nx_user.h                                Added #defines for router solicitation parameters
                                                     Added NX_PACKET_HEADER_PAD_SIZE to pad towards the end of the NX_PACKET structure.


11/23/2009  NetX generic code version 5.4. This release includes the following major features:
            Multiple IPv6 address support added
            Path MTU and IPv6 Advertised Link MTU support removed

            Other modifications are:

            nx_ip_fragment_assembly.c                 Added check for invalid length (exceed maximum size limit)
            nx_ip_max_payload_size.c                  New API:computes max packet payload that will not require fragmentation
            nx_ip_packet_send.c                       Corrected NX_IP_LIMITIED_BROADCAST to NX_IP_LIMITED_BROADCAST as destination IP
            nx_ipv6_packet_receive.c                  Added support for multiple IPv6 addresses
            nx_ipv6_packet_send.c                     Made packet fragmentation conditional; if not enabled and fragmentation is required drop the packet
                                                      Added mutex protection around Neighbor Discovery cache table operations
            nx_ipv6_utils.c                           Fixed bug in IPv6_Address_Type() for detecting multicast address type
            nx_tcp_no_connection_reset.c              For socket in CLOSED state, RST packet sequence number set to incoming ACK number
            nx_tcp_fast_periodic_processing.c         Replaced reference to primary IP global address with transmit socket outgoing interface address
            nx_tcp_packet_process.c                   Added call to nxd_tcp_no_connection_reset depending if IPv6 is enabled on the IP instance if a RST
                                                      must be sent
                                                      Update the socket outgoing interface to the received packet interface
            nx_tcp_packet_send_ack.c                  Added support for multiple IPv6 addresses
            nx_tcp_packet_send_fin.c                  Added support for multiple IPv6 addresses
            nx_tcp_packet_send_rst.c                  Added support for multiple IPv6 addresses
            nx_tcp_packet_send_syn.c                  Added support for multiple IPv6 addresses
            nx_tcp_socket_create.c                    Initialize socket outgoing interface with NULL instead of IP global address
            nx_tcp_socket_send.c                      Added support for multiple IPv6 addresses
            nx_tcp_socket_state_data_check.c          Fixed minor compiler warning with conditional coding around IP block pointer declaration
            nx_tcp_socket_state_transmit_check.c      Renamed nx_tcp_window_update_callback_notify with nx_tcp_socket_window_update_notify
                                                      Added support for multiple IPv6 addresses
            nx_tcp_socket_window_update_notify_set.c  Renamed file from  nx_tcp_socket_window_notify to nx_tcp_socket_window_notify_set
            nx_udp_socket_create.c                    Initialize socket outgoing interface with NULL instead of IP global address
            nx_udp_socket_receive.c                   Corrected placement of conditional #defines around extracting packet source and destination address
            nx_udp_source_extract.c                   Modified for performing IPv4 packet extraction only
            nxd_icmp_enable.c                         Removed path MTU support
            nxd_icmp_ping.c                           Added check for IPv6 enabled for sending IPv6 echo request packets
            nxd_ipv6_enabled.c                        Send an error status return if not IPv6 enabled
            nxd_ipv6_find_max_prefix_length.c         New function: finds the longest matching prefix between two IPv6 addresses
            nxd_ipv6_interface_address_get.c          New API: returns IPv6 address and prefix length based in the input interface index
            nxd_ipv6_interface_address_set.c          New API: Sets the IPv6 address and prefix length of the input interface index
            nxd_ipv6_interface_find.c                 Added multiple IPv6 address support
            nxd_ipv6_linklocal_address_get.c          Replace reference to obsoleted IP link local address with IP instance zero index interface (designated
                                                      link local)
            nxd_ipv6_linklocal_address_get.c          Replace reference to obsoleted IP link local address with IP instance zero index interface (designated
                                                      link local)
            nxd_ipv6_raw_packet_send_internal.c       Added check for valid IP instance outgoing interface for packet destination
            nx_nd_cache_entry_delete.c                Added TraceX support
            nxd_tcp_client_socket_connect.c           Added support for multiple IPv6 addresses
            nxd_tcp_socket_peer_info_get.c            Added TraceX support
            nxd_udp_socket_send.c                     Added support for multiple IPv6 addresses
            nxd_udp_socket_set_interface.c            Added support for multiple IPv6 addresses
            nxd_udp_source_extract.c                  Optimized the logic for retrieving the IP address
            nxde_ipv6_default_router_add.c            Updated call to nxd_ipv6_default_router_add() based on changes to that function
            nxde_udp_source_extract.c                 Added check for packet with invalid IP header
            nxe_udp_source_extract.c                  Added check for packet with invalid IP header
            nx_nd_cache.h                             Declared two new API, _nxd_nd_cache_entry_delete and _nxd_nd_cache_entry_set
            nx_tcp.h                                  Declared new API, _nxd_tcp_no_connection_reset
            nx_user.h                                 Removed NX_DISABLE_IPV6_PATH_MTU_DISCOVERY



08/03/2009  NetX generic code version 5.3. This release includes the following major features:
            Trace Events support
            IPSec support
            IGMP version 2 support

            Other modifications are:

            nx_igmp_enable.c                        IGMPv2 support
            nx_igmp_multicast_leave.c               IGMPv2 support
            nx_igmp_packet_process.c                IGMPv2 support
            nx_igmp_periodic_processing.c           IGMPv2 support
            nx_ip_checksum_compute.c                When adding last byte to the checksum,
                                                    cast the byte to unsigned short
            nx_ip_fragment_assembly.c               Fixed a packet size computation bug
            nx_ip_packet_send.c                     Use nx_ip_packet_deferred_receive for loopback
            nx_ipv6_packet_send.c                   Use nx_ip_packet_deferred_receive for loopback
            nx_ip_thread_entry.c                    Added IPv6 destination table support
            nx_tcp_socket_state_data_check.c        Optimized TCP out-of-order data receive logic
                                                    Added support for TCP congestion avoidance
            nx_tcp_socket_state_syn_received.c      Added support for TCP congestion avoidance
            nx_tcp_socket_state_syn_sent.c          Added support for TCP congestion avoidance
            nx_tcp_socket_state_transmit_check.c    Added support for TCP congestion avoidance
            nx_tcp_socket_windows_update_notify.c   Added support for TCP congestion avoidance
            nxd_tcp_client_socket_connect.c         Revised TCP loopback connection handling
            nx*.h                                   Modified comment(s).
            nx*.c                                   Modified comment(s).

12/30/2007  Initial NetX Duo generic code version 5.2. This release is based on NetX 5.1 for IPv4 support,
            with features developed for IPv6.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com

