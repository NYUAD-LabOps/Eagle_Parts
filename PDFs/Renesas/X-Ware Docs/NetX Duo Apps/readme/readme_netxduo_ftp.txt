Revision History for NetX Duo FTP

Release 5.11  07-15-2018

         nxd_ftp_client.c                       Supported for disabling IPv4 feature. 

                                                Dropped the chained packet to avoid memory overflow.

                                                Improved internal logic.

         nxd_ftp_server.c                       Made the sprintf formats the same for LIST the command case in nx_ftp_server_command_process().

                                                Added a sanity check for minimum packet payload size of the FTP server in _nx_ftp_server_create_internal().

                                                Supported for disabling IPv4 feature.

                                                Dropped the chained packet to avoid memory overflow.

                                                Improved internal logic.

                                                Corrected the logic for processing login/out.

                                                Fixed a bug that causes crash when month is invalid.

         nxd_ftp_server.h                       Created a configuration option for defining minimum FTP server packet pool payload, NX_FTP_SERVER_MIN_PACKET_PAYLOAD,
                                                  and created an error status NX_FTP_INSUFFICIENT_PACKET_PAYLOAD if the payload is too small.     

                                                Supported for disabling IPv4 feature.

Release 5.10  05-10-2016

         nxd_ftp_server.c                       Renamed _nx_ftp_server_control_disonnect_processing to nx_ftp_server_control_disconnect_processing.
                                                Added a check on status return from FileX file write and file create calls in _nx_ftp_server_command_process
                                                  and _nx_ftp_server_data_process. 

         nxd_ftp_server.h                       Renamed _nx_ftp_server_control_disonnect_processing to nx_ftp_server_control_disconnect_processing.

         nxd_ftp_client.c                       Added support for PASV, passive transfer mode
                                                Added IPv6 support to nx_ftp_client_directory_listing_get

         nxd_ftp_client.h                       Added support for PASV, passive transfer mode


Release 5.9   02-22-2016 

         demo_netxduo_ftp.c                     Unified ticks per second.

                                                Fixed compiler warnings.

         nxd_ftp_client.c                       Fixed compiler warnings.

         nxd_ftp_server.c                       Cleared socket resource when ftp server is stopped.

                                                Optimized the logic.

                                                Fixed a bug for calculating the length of file info.

                                                Fixed compiler warnings.

         nxd_ftp_server.h                       Unified ticks per second. 

                                                Added event to stop ftp server.

Revision History for FTPv6 Client and FTPv6 Server for NetX 5.8
  
         nxd_ftp_client.c                       Added _nx_ftp_client_connect_internal function and modified the _nxd_ftp_client_connect function.
                                                
                                                Added '|' character as the delimiter type for EPRT.  
 

         nxd_ftp_client.h                       Added declaration for _nx_ftp_client_connect_internal function. 

         nxd_ftp_server.c                       Added support for packet chain
                                   
                                                Fixed complier warning

                                                Added _nx_ftp_server_create_internal function and modified the _nx_ftp_server_create function. 

         nxd_ftp_server.h                       Added declaration for _nx_ftp_server_create_internal function. 

Revision History for FTPv6 Client and FTPv6 Server for NetX 5.2

         nxd_ftp_client.c                       Moved data socket disconnect ahead of releasing the
                                                port and removing from the listen queue, flush server 
                                                FTP messages from previous open request before starting 
                                                the current open file request, added an unnaccept call 
                                                if the data socket accept call fails, disconnect data 
                                                socket if an error occurs on the control socket ending 
                                                the file open request, increment the data port in the 
                                                event the FTP server puts the data socket in a timed wait,
                                                fixed the source of the IPv6 address in the number to 
                                                ascii converstion routine, flush server FTP messages 
                                                from previous open request before starting the current
                                                open file request, added an unnaccept call if the data 
                                                socket accept call fails, disconnect data socket if an
                                                error occurs on the control socket ending the file open 
                                                request, increment the data port in the event the FTP 
                                                server puts the data socket in a timed wait.
         nxd_ftp_client.h                       Added client data socket port to increment data port 
                                                binding on successive connections.
         nxd_ftp_server.c                       Added a cast to the FTP server pointer, added a check for 
                                                whether or not IPv6 is enabled in NetX Duo.
         nxd_ftp_server.h                       Added conditional IPv6 check for IPv6 specific 
                                                function declarations.
         

Revision History for FTPv6 Client and FTPv6 Server for NetX 5.1
  
         nxd_ftp_server.c                       Added support for multihoming and NetX Duo 5.6
         nxd_ftp_client.c                       Added support for multihoming and NetX Duo 5.6
         nxd_ftp.h                              Added support for multihoming and NetX Duo 5.6             



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com  

