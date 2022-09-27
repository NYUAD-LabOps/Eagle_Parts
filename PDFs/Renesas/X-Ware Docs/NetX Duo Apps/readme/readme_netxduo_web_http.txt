Revision History for NetX Duo Web HTTP


Release 5.11  07-15-2018

            nx_web_http_client.c          Added support for chunked transfer.
                                            Functions are added or modified:
                                            _nx_web_http_client_chunked_size_get()
                                            _nx_web_http_client_cleanup()
                                            _nx_web_http_client_memicmp()
                                            _nx_web_http_client_process_header_fields()
                                            _nx_web_http_client_response_body_get()
                                            _nx_web_http_client_response_read()
                                            _nx_web_http_client_response_byte_expect()
                                            _nx_web_http_client_response_chunked_get()
                                            _nx_web_http_client_request_chunked_set()
                                            _nx_web_http_client_request_packet_send()
                                            _nx_web_http_client_request_initialize()
                                            _nxe_web_http_client_request_chunked_set()
                                            _nxe_web_http_client_request_packet_send()
                                            _nx_web_http_client_delete()

                                          Corrected the TCP header size in _nxe_web_http_client_put_packet().

                                          Added support for keep-alive.
                                            Functions are added or modified:
                                            _nx_web_http_client_connect()
                                            _nx_web_http_client_process_header_fields()
                                            _nx_web_http_client_secure_connect()

                                          Corrected the wait option.
                                            Functions are modified:
                                            _nx_web_http_client_request_initialize()
                                            _nx_web_http_client_request_header_add()
                                            _nx_web_http_client_request_send()

                                          Added support for returning all the status code in _nx_web_http_client_response_body_get().

                                          Fixed the issue of TCP socket cleanup in _nx_web_http_client_secure_connect().

            nx_web_http_client.h          Added support for chunked transfer.

                                          Added support for keep-alive.

                                          Added support for returning all the status code.

            nx_web_http_server.c          Added support for chunked transfer.
                                            Functions are added or modified:
                                            _nx_web_http_server_content_get()
                                            _nx_web_http_server_packet_content_find()
                                            _nx_web_http_server_packet_get()
                                            _nx_web_http_server_content_get_extended()
                                            _nx_web_http_server_receive_data()
                                            _nx_web_http_server_get_process()
                                            _nx_web_http_server_put_process()
                                            _nx_web_http_server_callback_packet_send()
                                            _nx_web_http_server_request_read()
                                            _nx_web_http_server_request_byte_expect()
                                            _nx_web_http_server_chunked_size_get()
                                            _nx_web_http_server_request_chunked_get()
                                            _nxe_web_http_server_response_chunked_set()
                                            _nx_web_http_server_response_chunked_set()
                                            _nx_web_http_server_chunked_check()
                                            _nx_web_http_server_get_entity_header()
                                            _nx_web_http_server_boundary_find()

                                          Modified packet allocation function.
                                            Functions are added or modified:
                                            _nx_web_http_server_basic_authenticate()
                                            _nx_web_http_server_calculate_content_offset()
                                            _nx_web_http_server_callback_data_send()
                                            _nx_web_http_server_digest_authenticate()
                                            _nx_web_http_server_get_process()
                                            _nx_web_http_server_generate_response_header()
                                            _nx_web_http_server_response_packet_allocate()
                                            _nxe_web_http_server_response_packet_allocate()

            nx_web_http_server.h          Added support for chunked transfer.

                                          Added packet allocation function.

            nx_tcpserver.c                Corrected the wait time of TCP server socket accepting in _nx_tcpserver_connect_process().

            nx_tcpserver.h                Modified the default thread priority of TCP server.

            nx_web_http_common.h          Added support for returning all the status code.

            demo_netxduo_https.c          Fixed the compile errors.

Release 5.10  05-15-2018      Initial release.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com  

