Revision History for NetX Duo Telnet 

Release 5.11  07-15-2018

        nxd_telnet_client.h                 Removed NX_TELNET_MAX_OPTION_SIZE option and 
                                              nx_telnet_client_request_option from CLIENT_REQUEST structure.

        nxd_telnet_client.c                 Supported for disabling IPv4 feature.

        nxd_telnet_server.c                 Dropped the chained packet to avoid memory overflow.

Release 5.10  05-10-2016

            *.c                              Modified comments.
            *.h                              Modified comments.

Release 5.9   02-22-2016

            demo_netxduo_telnet.c            Unified ticks per second.

                                             Fixed compiler warnings.
            
            nxd_telnet_server.c              Added support for external packet pool creation for use when NX_TELNET_SERVER_OPTION_DISABLE
                                                   is not defined and the Telnet Server needs a packet pool to send Telnet options. 

                                             Created _nx_telnet_server_packet_pool_set() API for applications to set the Telnet Server packet
                                                   pool if NX_TELNET_SERVER_USER_CREATE_PACKET_POOL is defined.  The default is the Telnet Server
                                                   creates the packet pool.

                                             Cleared socket resource when telnet server is stopped. 
 
                                             Modified nx_telnet_server_process_options to move the offset for all responses to the ECHO request.

                                             Fixed a bug when packet contains command and data, data are not processed.

                                             Fixed compiler warnings.
                                          
            nxd_telnet_server.h              Added support for for external packet pool creation with configuration option 
                                                   NX_TELNET_SERVER_USER_CREATE_PACKET_POOL and API nx_telnet_server_packet_pool_set().
                                                   
                                             Unified ticks per second.

                                             Added event to stop telnet server.

            nxd_telnet_client.h              Removed unused macro.

Release 5.8   01-12-2015

            nxd_telnet_server.c              Added support for option negotiation. The supported options are "ECHO" and "Suppress Go Ahead". 
                                             Fixed a bug that connection end callback function was not invoked.
                                             Added logic to handle a RST where the socket is already closed.
                                             Added a callback to set remote echo (used by the NetX Duo SHELL Telnet driver).

            nxd_telnet_server.h              Added support for option negotiation. The supported options are "ECHO" and "Suppress Go Ahead". 

NetX Duo Telnet v5.2 Mar 7 2012  
  
            nxd_telnet_server.c              Added support for activity timeout disconnect callback. When a connection times out
                                                   NetX Duo Telnet Server calls the disconnect callback. Previously, it simply
                                                   closed the connection silently.

                                             Added a current open connection counter and new API 
                                                   nx_telnet_server_get_open_connection_count for retrieving the open conneciton count.

            nxd_telnet_server.h              Added support for the new API nx_telnet_server_get_open_connection_count

Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com

