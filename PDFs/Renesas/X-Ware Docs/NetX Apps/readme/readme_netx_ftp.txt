Revision History for NetX FTP

Release 5.11  07-15-2018

        nx_ftp_client.c                        Dropped the chained packet to avoid memory overflow.

                                               Improved internal logic.

        nx_ftp_server.c                        Made the sprintf formats the same for LIST the command case in nx_ftp_server_command_process().

                                               Added a sanity check for minimum packet payload size of the FTP server in _nx_ftp_server_create_internal().

                                               Dropped the chained packet to avoid memory overflow.

                                               Improved internal logic.

                                               Corrected the logic for processing login/out.

                                               Fixed a bug that causes crash when month is invalid.

        nx_ftp_server.h                        Created a configuration option for defining minimum FTP server packet pool payload, NX_FTP_SERVER_MIN_PACKET_PAYLOAD,
                                                 and created an error status NX_FTP_INSUFFICIENT_PACKET_PAYLOAD if the payload is too small.

Release 5.10  05-10-2016


        nx_ftp_server.c                        Renamed _nx_ftp_server_control_disonnect_processing to nx_ftp_server_control_disconnect_processing.
                                               Added a check on status return from FileX file write and file create calls in _nx_ftp_server_command_process
                                                 and _nx_ftp_server_data_process. 

        nx_ftp_server.h                        Renamed _nx_ftp_server_control_disonnect_processing to nx_ftp_server_control_disconnect_processing.

        nx_ftp_client.c                        Added support for PASV, passive transfer mode

        nx_ftp_client.h                        Added support for PASV, passive transfer mode

        



Release 5.9   02-22-2016 

         demo_netxduo_ftp.c                     Unified ticks per second.

                                                Fixed compiler warnings.

         nx_ftp_client.c                        Fixed compiler warnings.

         nx_ftp_server.c                        Cleared socket resource when ftp server is stopped.

                                                Optimized the logic.

                                                Fixed a bug for calculating the length of file info.

                                                Fixed compiler warnings.

         nx_ftp_server.h                        Unified ticks per second.

                                                Added event to stop ftp server.

01-12-2015  Initial FTP Client generic code version 5.8.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com                            
