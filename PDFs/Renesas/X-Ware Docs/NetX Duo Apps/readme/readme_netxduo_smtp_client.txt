Revision History for NetX Duo SMTP Client

Release 5.11  07-15-2018

        demo_netxduo_smtp_client.c      Supported for disabling IPv4 feature.

        nxd_smtp_client.c               Fix compiler errors when event trace is enabled.
                                        Supported for disabling IPv4 feature.
                                        Dropped the chained packet to avoid memory overflow.
                                        Improved packet length verification.

        nxd_smtp_client.h               Removed unused API macro nxd_smtp_mail_send.     
        
Release 5.10  05-10-2016

        *.c                             Modified comments.
        *.h                             Modified comments.


Release 5.9   02-22-2016

        demo_netxduo_smtp_client.c      Unified ticks per second.

                                        Fixed compiler warnings.

        nxd_smtp_client.c               Unified ticks per second.

                                        Removed unused code and simplified SMTP client data types

                                        Fixed packet leaks in various functions

                                        Added logic for SMTP servers not configured for authentication

                                        Added option for SMTP Client to skip authentication (NX_SMTP_CLIENT_AUTH_NONE)

                                        Fixed problems handling multi-packet response from the server to client EHLO

                                        Check socket state and delete TCP socket in nx_smtp_client_delete() before clearing SMTP Client memory

                                        Modified _nx_smtp_utility_parse_server_services() not to set AUTH type if the current 250 packet does not
                                           contain the AUTH keyword. Otherwise the client authentication type may not be set correctly.

                                        Fixed compiler warnings.


        nxd_smtp_client.h               Unified ticks per second. Remove definitions of NX_SMTP_MILLISECONDS_PER_TICK and NX_SMTP_TICKS_PER_SECOND.

                                        Added logic for SMTP servers not configured for authentication

                                        Added option for SMTP Client to skip authentication (NX_SMTP_CLIENT_AUTH_NONE)

                                        Removed unused code and simplified SMTP client data types

Note 1. Applications written for versions of NetX SMTP Client older than v5.3 will not work
with v5.3 or v5.8. There were no releases between v5.3 and v5.8. 

Note 2. Applications written for NetX Duo SMTP Client v5.2 will work with v5.8. There were no releases between 
v5.2 and v5.8. 


Release 5.8   01-12-2015

This service packet includes the following modifications:

        nxd_smtp_client.c  Fixed error in invalid pointer check in _nxe_smtp_mail_send.
                           Fixed compiler error when IPv6 is disabled in _nxd_smtp_client_create.
                           Fixed bug checking for invalid pointers.
                           Fixed a typo in _nx_smtp_cmd_message.
                           Fixed case insensitive compare for challenge word.
                           Corrected 5.2 release date from 04-15-13 to 04-15-2013

        nxd_smtp_client.h  Corrected 5.2 release date from 04-15-13 to 04-15-2013

Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com

