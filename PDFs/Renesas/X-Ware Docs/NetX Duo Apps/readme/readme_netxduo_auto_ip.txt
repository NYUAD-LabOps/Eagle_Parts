Revision History for NetX Duo Auto IP

Release 5.11  07-15-2018

             *.c                                       Modified comments.
             *.h                                       Modified comments.

Release 5.10  05-10-2016

             nx_auto_ip.c                              Optimized the logic for detecting address conflict.
                                                         Functions are modified or deleted:
                                                         _nx_auto_ip_arp_packet_send()
                                                         _nx_auto_ip_conflict()
                                                         _nx_auto_ip_create()
                                                         _nx_auto_ip_delete()
                                                         _nx_auto_ip_thread_entry()

                                                       Fixed the bug for checking interface status.
                                                         Function is modified:
                                                         _nx_auto_ip_thread_entry()
                                                       
             nx_auto_ip.h                              Optimized the logic for detecting address conflict.

Release 5.9   02-22-2016

             demo_netx_auto_ip.c                       Used TX_TIMER_TICKS_PER_SECOND as default value of NX_IP_PERIODIC_RATE.

                                                       Fixed compiler warnings.

             nx_auto_ip.c                              Fixed one bug that hardware address is set as zero if IP instance is uninitialized.

                                                       Fixed compiler warnings.

                                                       Corrected the value of NX_AUTO_IP_END_ADDRESS.

The following files have been modified in Auto IP v5.8 since v5.2 as follows:
  

             nx_auto_ip.c                              Added NX_RAND to replace rand to get the random value.


The following files have been modified in Auto IP v5.2 since v5.1 as follows:
  

             nx_auto_ip.c                              Fixed a bug causing an infinate loop
                                                       Added support for NetX Duo (5.5 and later) to run over IPv4 when IPv6 is enabled.

             nx_auto_ip.h                              Added support for NetX Duo (5.5 and later) to run over IPv4 when IPv6 is enabled.


Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com
