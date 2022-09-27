Revision History

03-11-2018  ThreadX generic code version 5.8 Service Pack 1 (SP1). To install SP1, simply 
            copy the files in SP1 into the same directory of your ThreadX 5.8 distribution
            and then rebuild the ThreadX library as well as the application code.
            
            SP1 includes the following modifications:
            
                        File                                    Changes
                        
                tx_api.h                            Added a macro to disable warning of 
                                                    parameter not used.
                tx_event_flags_set_notify.c         Removed the warning of parameter not used.
                tx_mutex_get.c                      Changed logic to update the priority inheritance
                                                    priority level.
                tx_mutex_priority_change.c          Removed update of the priority inheritance
                                                    priority level.
                tx_mutex_put.c                      Changed logic to properly update the priority 
                                                    inheritance priority level.
                tx_queue_send_notify.c              Removed the warning of parameter not used.
                tx_semaphore_put_notify.c           Removed the warning of parameter not used.
                tx_thread_entry_exit_notify.c       Removed the warning of parameter not used.

