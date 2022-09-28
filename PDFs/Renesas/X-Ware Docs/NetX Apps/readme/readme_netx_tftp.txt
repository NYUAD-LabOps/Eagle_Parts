Revision History for NetX TFTP

Release 5.11  07-15-2018

            nx_tftp_client.c                       Improved packet length verification.

                                                   Corrected the field size of block number.

            nx_tftp_server.c                       Improved packet length verification.

                                                   Improved internal logic.

                                                   Corrected the field size of block number.

            nx_tftp_client.h                       Corrected the field size of block number.

            nx_tftp_server.h                       Corrected the field size of block number.

Release 5.10  05-10-2016

            *.c                                    Modified comments.
            *.h                                    Modified comments.

Release 5.9   02-22-2016

            demo_netx_tftp.c                       Unified ticks per second.

                                                   Fixed compiler warnings.

            nx_tftp_server.c                       Added support for a retransmit feature where a packet is
                                                   retransmitted if the correct data or ACK from the TFTP Client
                                                   is not received within user specified timeout period.

                                                   Added logic to handle duplicate WRITE or READ requests e.g. the 
                                                   TFTP server is delayed responding to the first request and while
                                                   processing it receives one or more duplicate requests (which are dropped).

                                                   Fixed packet leak.

                                                   Fixed compiler warnings.

            nx_tftp_server.h                       Added support for a retransmit feature.

            nx_tftp_client.c                       Fixed compiler warnings.

01-12-2015  Initial TFTP Client generic code version 5.8.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com
