Revision History for NetX PPP 

Release 5.11  07-15-2018

         nx_ppp.c                               Supported for transmitting PPP over Ethernet.
                                                  Functions are modified or added:
                                                  _nx_ppp_netx_packet_transfer()
                                                  _nx_ppp_packet_receive()
                                                  _nx_ppp_packet_send_set()
                                                  _nx_ppp_packet_transmit()
                                                  _nx_ppp_process_deferred_raw_string_send()
                                                  _nx_ppp_receive_packet_get()
                                                  _nx_ppp_thread_entry()
                                                  _nxe_ppp_packet_receive()
                                                  _nxe_ppp_packet_send_set()
                                                  _nxe_ppp_create()
                                                  
                                                  _nx_ppp_crc_append()
                                                  _nx_ppp_process_deferred_ip_packet_send()
                                                  _nx_ppp_lcp_code_reject()
                                                  _nx_ppp_lcp_configure_reply_send()
                                                  _nx_ppp_lcp_configure_request_send()
                                                  _nx_ppp_lcp_configuration_retrieve()
                                                  _nx_ppp_lcp_state_machine_update()
                                                  _nx_ppp_lcp_terminate_ack_send()
                                                  _nx_ppp_lcp_terminate_request_send()
                                                  _nx_ppp_pap_authentication_request()
                                                  _nx_ppp_pap_authentication_ack()
                                                  _nx_ppp_pap_authentication_nak()
                                                  _nx_ppp_pap_login_valid()
                                                  _nx_ppp_pap_state_machine_update()
                                                  _nx_ppp_chap_challenge_send()
                                                  _nx_ppp_chap_challenge_respond()
                                                  _nx_ppp_chap_challenge_validate()
                                                  _nx_ppp_chap_state_machine_update()
                                                  _nx_ppp_ipcp_configure_check()
                                                  _nx_ppp_ipcp_configure_request_send()
                                                  _nx_ppp_ipcp_response_extract()
                                                  _nx_ppp_ipcp_response_send()
                                                  _nx_ppp_ipcp_state_machine_update()
                                                  _nx_ppp_ipcp_terminate_ack_send()
                                                  _nx_ppp_ipcp_terminate_send()
                                                  _nx_ppp_raw_string_send()
                                                  _nx_ppp_receive_packet_process()
                                                  
                                                Added state check before start PAP, CHAP and IPCP.
                                                  _nx_ppp_packet_receive()

                                                Corrected the logic for stopping PPP.
                                                  Functions are modified:
                                                  _nx_ppp_thread_entry()
                                                  _nx_ppp_lcp_state_machine_update()

                                                Corrected the logic for processing LCP message.
                                                  Function is modified: 
                                                  _nx_ppp_receive_packet_process()

                                                Corrected the logic for setting gateway address.
                                                  Function is modified: 
                                                  _nx_ppp_ipcp_state_machine_update()

                                                Set the flag to distinguish PPP Server and PPP Client.
                                                  Function is modified: 
                                                  _nx_ppp_receive_packet_process()

                                                Added functions to stop/start PPP.
                                                  Function are modified:
                                                  _nx_ppp_start()
                                                  _nx_ppp_stop()
                                                  _nxe_ppp_start()
                                                  _nxe_ppp_stop()

                                                Improved packet length verification.
                                                  Function are modified:
                                                  _nx_ppp_chap_challenge_respond()
                                                  _nx_ppp_chap_challenge_validate()
                                                  _nx_ppp_ipcp_configure_check()
                                                  _nx_ppp_ipcp_response_extract()
                                                  _nx_ppp_pap_login_valid()
                                                  _nx_ppp_receive_packet_process()

                                                Improved internal logic.
                                                  Function are modified:
                                                  _nx_ppp_chap_challenge_respond()
                                                  _nx_ppp_chap_challenge_validate()
                                                  _nx_ppp_chap_state_machine_update()
                                                  _nx_ppp_ipcp_state_machine_update()
                                                  _nx_ppp_lcp_state_machine_update()
                                                  _nx_ppp_pap_state_machine_update()

                                                Added echo request statistics and corrected the length field in _nx_ppp_ping_request().
 
         nx_ppp.h                               Supported for transmitting PPP over Ethernet.

                                                Added functions to stop/start PPP.

Release 5.10  05-10-2016

            nx_ppp.c                            Added break statements for the STOPPING state case for both nx_ppp_lcp_state_machine_update and nx_ppp_ipcp_state_machine_update.
            *.h                                 Modified comments.


Release 5.9   02-22-2016

         demo_netx_ppp.c                        Unified ticks per second.

                                                Fixed compiler warnings.

         nx_ppp.c                               Replaced hard numbers with PPP symbols for PPP codes, protocols, options and protocol states.

                                                Added _nx_ppp_debug_log_capture_protocol function to outputs the status of various protocols and timeouts of the specified PPP instance.

                                                Added support for the secondary DNS option in the IPCP protocol.

                                                Added a retry limit on IPCP NAK list requests with primary and secondary DNS options so that
                                                  IPCP can complete if either address is not available.

                                                Added NXE function for error checking.

                                                Fixed compiler warnings.

         nx_ppp.h                               Unified ticks per second.

                                                Defined PPP symbols for naked list options.

                                                Added _nx_ppp_debug_log_capture_protocol prototype.

                                                Modified the NX_PPP data block to contain a secondary DNS address and count of retries on IPCP
                                                  config requests with DNS address options.
 
                                                Added #defines for maximum retries on IPCP requests containing DNS options.

                                                Added services for setting and getting the primary and secondary DNS addresses.

                                                Added NXE function for error checking.

                                                Fixed the compiler error if defined NX_PPP_DISABLE_INFO.

01-12-2015  Initial PPP generic code version 5.8.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com 
