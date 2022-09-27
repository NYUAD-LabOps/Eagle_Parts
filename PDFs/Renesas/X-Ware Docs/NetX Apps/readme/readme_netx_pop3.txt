Revision History for NetX POP3


Release 5.11  07-15-2018

         demo_netx_pop3_client.c               Increased packet payload to 1460 from 500, and clear final_packet local variable in
                                                   the loop that iterates to capture all the packets in a mail item.
         nx_pop3_client.c                      Corrected the logic in _nx_pop3_client_mail_item_message_get for handling packets with only
                                                   the POP3 end marker tag indicating end of mail message.
                                               Dropped the chained packet to avoid memory overflow.
                                               Improved internal logic.
                                               Fixed the logic for handling message and command in one packet.

         nx_pop3_client.h                      Fixed the logic for handling message and command in one packet.

Release 5.10  05-10-2016

         nx_pop3_client.c                      Returned NX_SUCCESS only if the positive response consists of "+OK".
                                                 Functions are modified:
                                                 _nx_pop3_client_mail_item_get()
                                                 _nx_pop3_client_mail_item_delete()
                                                 _nx_pop3_client_quit()

NetX POP3 Client v5.9.

         demo_netx_pop3_client.c               Unified ticks per second. Used TX_TIMER_TICKS_PER_SECOND as default value of NX_IP_PERIODIC_RATE.
                                               Fixed compiler errors.

         nx_pop3_client.c                      Unified ticks per second. Used TX_TIMER_TICKS_PER_SECOND as default value of NX_IP_PERIODIC_RATE.
                                               Fixed compiler errors.
                                               Fixed number checking.

         nx_pop3_client.h                      Unified ticks per second. Used TX_TIMER_TICKS_PER_SECOND as default value of NX_IP_PERIODIC_RATE.



01-12-2015  Initial POP3 generic code version 5.8.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com

