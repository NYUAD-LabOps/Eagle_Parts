Revision History for NetX Duo HTTP Client and NetX Duo Server 

Release 5.11 07-15-2018

            demo_netxduo_http.c            Supported for disabling IPv4 feature.

            nxd_http_server.c              Fixed the logic for multi packet GET request.
                                           Improved internal logic.

            nxd_http_client.c              Supported for disabling IPv4 feature.


Release 5.10  05-10-2016

            demo_netxduo_http.c            Fix a bug that memory of ram disk is corrupted.

            nxd_http_client.c              Allow zero or more whitespaces between Content-Length and value
                                             in nx_http_client_content_length_get()
                                             
                                           Optimized the code.
                                             _nx_http_client_content_length_get()

                                           Fixed packet leak for invalid HTTP packet in _nxd_http_client_get_start
                                             and _nx_http_client_get_packet.

                                           Corrected the logic in _nxd_http_client_get_start when checking
                                             offset against the packet length

                                           Modified nxd_http_client_get_start() and nxd_http_client_put_start()
                                             to accept a URI resource string that refers to a full website
                                             e.g. http://abc.def.com/index.htm.

                                           Added nx_http_client_set_connect_port() service to allow the Client 
                                             to change the HTTP server port at runtime. 

            nxd_http_client.h              Declare the nx_http_client_set_connect_port() service
 
Release 5.9. 02-22-2016

            demo_netxduo_http.c            Unified ticks per second. 
                                             Fixed compiler warnings.

            nxd_http_client.h              Unified ticks per second. 

            nxd_http_client.c              Removed trailing space on HTTP/1.0.

            nxd_http_server.h              Unified ticks per second. 
                                             Declared missing function headers.

            nxd_http_server.c              Cleared socket resource when stopped. 
                                             Fixed first MIME type in the default array.
                                             Fixed compiler warnings.

Release 5.8 01-12-2015

            nxd_http_client.c              Fixed a bug that username and password might be NULL.
                                           Added size check for nxe_http_client_create.
            nxd_http_client.h              Added size check for nxe_http_client_create.

            nxd_http_server.c              Fixed the logic in _nx_http_server_get_client_request to handle 
                                           multipacket Get requests.                            
                                           Added cache feature.
                                           Supported user defined MIME maps.
                                           Supported packet chain feature.
                                           Supported multipart upload feature.
                                           Unified response line.
                                           Fixed compiler warnings.
                                           Fixed memory leak when packet is chained.
                                           Supported escape character.
                                           Supported absolute URI.
                                           Added separate input pointer to authenticate function if authentication is required. 
                                           Return on internal error code.
                                           Added size check for nxe_http_server_create.
                                           Added timeouts for receive, accept, send and disconnect.
                                           Defined values and structures for new features in nxd_http_server.c.
                                           Added new services for new features in nxd_http_server.c.
                                           Supported invalid user/password callback function.

            nxd_http_server.h              Supported multipart upload feature.
                                           Unified response line.
                                           Supported to response date in header.
                                           Removed declarations for _nxe version.
                                           Added cache feature.
                                           Supported user defined MIME maps.
                                           Added new services for new features in nxd_http_server.c.
                                           Added size check for nxe_http_server_create.
                                           Added timeouts for receive, accept, send and disconnect.
                                           Modified NX_HTTP_MAX_STRING to ensure room for encoded string.

Release 5.2 01-31-2013

            nxd_http_server.c              Created _nx_http_server_content_length_get_extended and                            
                                           _nx_http_server_content_get_extended services which will accept 
                                           empty (content-length = 0) PUT and POST requests. 

                                           Corrected 411 error codes in HTTP server replies to 400 error codes
                                           since 411 error code is when the HTTP server refuses to accept a
                                           request without a defined content-length. HTTP 1.0 permits requests 
                                           without Content-length but does not permit Content-length that does 
                                           not match the message body. 

Release 5.1 11-21-2011

            nxd_http_client.h              Created a separate header file for HTTP Client and HTTP Server                            
                                                    

            nxd_http_server.h              Created a separate header file for HTTP Client and HTTP Server                            

  
                             


Initial Release 5.0

Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com

