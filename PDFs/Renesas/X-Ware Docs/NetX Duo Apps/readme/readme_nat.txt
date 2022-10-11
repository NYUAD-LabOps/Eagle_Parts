Revision History for NetX Duo NAT

Release 5.11  07-15-2018

            nx_nat.c                                Set different timeout for TCP and non-TCP seesion.
                                                      Functions are modified:
                                                      _nx_nat_inbound_entry_find()
                                                      _nx_nat_outbound_entry_find()

                                                    Added support for replacement when cache is full.
                                                      Function is modified:
                                                      _nx_nat_entry_create()

                                                    Corrected the logic for appending the overflowing data to the new packet.
                                                      Function is modified:
                                                      _nx_nat_ip_packet_send()

                                                    Improved packet length verification.
                                                      Function is modified:
                                                      _nx_nat_process_packet()

            nx_nat.h                                Added symbols for TCP and non-TCP session timeout.

                                                    Added NX_NAT_ENABLE_REPLACEMENT.

Release 5.10  05-10-2016

            *.c                                     Modified comments.
            *.h                                     Modified comments.

Release 5.9   02-22-2016

            demo_netx_nat.c                         Unified ticks per second. 

            nx_nat.c                                Unified ticks per second.

                                                    Fixed compiler warnings.

                                                    Modified the logic for packet processing and sending since all 
                                                      the fragments are assembled before forwarding.
                                                      Functions are modified:
                                                      _nx_nat_process_packet()
                                                      _nx_nat_ip_packet_send()

            nx_nat.h                                Unified ticks per second.

01-12-2015  Initial NAT generic code version 5.8.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com
