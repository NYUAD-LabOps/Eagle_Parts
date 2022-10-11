Revision History for NetX Duo TFTP Client

Release 5.11  07-15-2018

            nxd_tftp_client.c                      Supported for disabling IPv4 feature.
            
                                                   Improved packet length verification.

                                                   Corrected the field size of block number.

            nxd_tftp_server.c                      Improved packet length verification.

                                                   Improved internal logic.

                                                   Corrected the field size of block number.

            nxd_tftp_client.h                      Corrected the field size of block number.

            nxd_tftp_server.h                      Corrected the field size of block number.

Release 5.10  05-10-2016

            *.c                                    Modified comments.
            *.h                                    Modified comments.


Release 5.9   02-22-2016

            demo_netxduo_tftp.c                    Unified ticks per second.

                                                   Fixed compiler warnings.

            nxd_tftp_server.c                      Added support for a retransmit feature where a packet is
                                                   retransmitted if the correct data or ACK from the TFTP Client
                                                   is not received within user specified timeout period.

                                                   Added logic to handle duplicate WRITE or READ requests e.g. the 
                                                   TFTP server is delayed responding to the first request and while
                                                   processing it receives one or more duplicate requests (which are dropped).

                                                   Fixed packet leak.

                                                   Fixed compiler warnings.

            nxd_tftp_server.h                      Added support for a retransmit feature.

            nxd_tftp_client.c                      Fixed compiler warnings.

Release 5.8   01-12-2015
        
            nxd_tftp_server.c                      Remove the MULTI_HOME macro definition.   

                                                   Added support for packet chaining.

            nxd_tftp_server.h                      Remove the MULTI_HOME macro definition.    
        
            nxd_tftp_client.c                      Fixed packet leaks in nx_tftp_client_file_read and nx_tftp_client_file_open.

                                                   Remove the MULTI_HOME macro definition.
                                                   
                                                   Modified nx_tftp_client_file_write and nx_tftp_client_file_open (write request) to save server
                                                   error type and message to TFTP Client if an ACK is not received after data is sent.
                                                   
                                                   Modified nx_tftp_client_file_read to fix bug parsing the server error type from the server 
                                                   if an error code is received.                                                        



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com
