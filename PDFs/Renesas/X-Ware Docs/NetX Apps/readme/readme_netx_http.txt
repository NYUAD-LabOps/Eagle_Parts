Revision History for NetX HTTP

Release 5.11 07-15-2018

            nx_http_server.c              Fixed the logic for multi packet GET request.
                                          Improved internal logic.


Release 5.10 05-10-2016

            demo_netx_http.c              Fix a bug that memory of ram disk is corrupted.

            nx_http_client.c              Allow zero or more whitespaces between Content-Length and value
                                             in nx_http_client_content_length_get()

                                          Optimized the code.
                                            _nx_http_client_content_length_get()

                                          Fixed packet leak for invalid HTTP packet in _nx_http_client_get_start
                                            and _nx_http_client_get_packet.

                                          Corrected the logic in _nx_http_client_get_start when checking
                                            offset against the packet length

                                          Modified nx_http_client_get_start() and nx_http_client_put_start()
                                            to accept a URI resource string that refers to a full website
                                            e.g. http://abc.def.com/index.htm.

                                          Added nx_http_client_set_connect_port() service to allow the Client 
                                            to change the HTTP server port at runtime. 

            nx_http_client.h              Declare the nx_http_client_set_connect_port() service

Release 5.9. 02-22-2016

            demo_netx_http.c              Unified ticks per second. 
                                            Fixed compiler warnings.

            nx_http_client.h              Unified ticks per second. 

            nx_http_client.c              Removed trailing space on HTTP/1.0.

            nx_http_server.h              Unified ticks per second. 
                                            Declared missing function headers.

            nx_http_server.c              Cleared socket resource when stopped.
                                            Fixed first MIME type in the default array.
                                            Fixed compiler warnings.


01-12-2015  Initial HTTP generic code version 5.8.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com

