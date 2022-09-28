Revision History for NetX SMTP 

Release 5.11  07-15-2018

        nx_smtp_client.c                Fix compiler errors when event trace is enabled.
                                        Dropped the chained packet to avoid memory overflow.
                                        Improved packet length verification.
        
Release 5.10  05-10-2016

        *.c                             Modified comments.
        *.h                             Modified comments.

Release 5.9   02-22-2016

        demo_netx_smtp_client.c         Unified ticks per second.

                                        Fixed compiler warnings.

        nx_smtp_client.c                Unified ticks per second.

                                        Removed unused code and simplified SMTP client data types

                                        Fixed packet leaks in various functions

                                        Added logic for SMTP servers not configured for authentication

                                        Added option for SMTP Client to skip authentication (NX_SMTP_CLIENT_AUTH_NONE)

                                        Fixed problems handling multi-packet response from the server to client EHLO

                                        Check socket state and delete TCP socket in nx_smtp_client_delete() before clearing SMTP Client memory

                                        Modified _nx_smtp_utility_parse_server_services() not to set AUTH type if the current 250 packet does not
                                           contain the AUTH keyword. Otherwise the client authentication type may not be set correctly.

                                        Fixed compiler warnings.

        nx_smtp_client.h                Unified ticks per second. Remove definitions of NX_SMTP_MILLISECONDS_PER_TICK and NX_SMTP_TICKS_PER_SECOND.

                                        Added logic for SMTP servers not configured for authentication

                                        Added option for SMTP Client to skip authentication (NX_SMTP_CLIENT_AUTH_NONE)

                                        Removed unused code and simplified SMTP client data types


Release 5.8   01-12-2015                Initial Release.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com
