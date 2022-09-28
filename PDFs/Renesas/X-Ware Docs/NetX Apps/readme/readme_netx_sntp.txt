Revision History for NetX SNTP

Release 5.11  07-15-2018

            nx_sntp_client.c                Modified nx_sntp_client_utility_convert_seconds_to_date causing the date to be off by one day if NX_SNTP_CURRENT_YEAR
                                              is older than the current date and a leapyear has occurred between that year and the current date.
                                            Removed useless code.
                                            Improved internal logic.
            nx_sntp_client.h                Modified comments.

Release 5.10  05-10-2016

            *.c                             Modified comments.
            *.h                             Modified comments.

Release 5.9   02-22-2016

            demo_netx_sntp_client.c         Unified ticks per second.
                                            Updated the demo for creating SNTP client packet pool.
                                            Fixed compiler warnings.

            nx_sntp_client.c                Modified nx_sntp_client_get_msecs_diff to simplify the logic
                                            Modified nx_sntp_client_server_clock_dispersion_check to simplify the logic
                                            Reworked the logic in nx_sntp_client_utility_get_msec_diff to add back in flag for postive or 
                                              negative difference. Some use cases in NetX SNTP Client regard a negative difference as an error. 
                                            Modified nx_sntp_client_utility_convert_secs_to_date to handle a date stamp in a year 
                                              after NX_SNTP_CURRENT_YEAR.
                                            Created new API  nx_sntp_client_request_unicast_time() to request unicast updates asynchronously of the
                                              SNTP Client thread task. 
                                            Simplified the completion status logic for _nx_sntp_client_process_update_packet
                                            Removed unnecessary input for _nx_sntp_client_receive_time_update and _nx_sntp_client_apply_sanity_checks. 
                                            Fixed the logic to check if the update time has expired without a response. 
                                            Modified nx_sntp_client_initialize_broadcast to handle invalid parameter input. 
                                            Created nx_sntp_client_set_time_update_notify to set a callback when the SNTP Client receives a valid 
                                              SNTP update. 
                                            Simplified logic for valid packet processing in _nx_sntp_client_process_broadcast.
                                            Simplified error code in _nx_sntp_client_apply_sanity_checks.
                                            Modifiied _nx_sntp_client_process_time_data to add status check for adding msec to ntp time.
                                            Unified ticks per second.
                                            Fixed compiler warnings.


            nx_sntp_client.h                Modified nx_sntp_client_server_clock_dispersion_check declaration for changes to input args
                                            Created new API  nx_sntp_client_request_unicast_time()
                                            Removed unnecessary input for _nx_sntp_client_receive_time_update and _nx_sntp_client_apply_sanity_checks, 
                                            Added support for nx_sntp_client_set_time_update_notify() callback.
                                            Unified ticks per second.
                                            Fixed a bug when multiple packets were received and the first one was invalid,
                                              other packets were not processed in time.
                                            Removed unused macros.
                                            Fixed compiler warnings.


Release 5.8   01-12-2015                    Initial Release


Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com



