                        Express Logic's FileX

1. Revision History


03/30/2018  FileX generic code version 5.5 Service Pack 1 (SP1).  To install SP1, simply copy 
            files in SP1 into the same directory of your FileX 5.5 distribution and then rebuild
            the FileX library as well as the application code. SP1 includes the following modifications:

            fx_api.h                                        Fixed minor version number.
            fx_fault_tolerant.h                             Added macros so user can define port-specific operations.
            fx_fault_tolerant_enable.c                      Updated the available clusters when 
                                                              additional information was used.
            fx_fault_tolerant_write_log_file.c              Added macros so user can define port-specific operations.
            fx_file_extended_allocate.c                     Corrected the file offset.
            fx_file_extended_best_effort_allocate.c         Corrected the file offset.
            fx_file_extended_truncate_release.c             Cleared FAT chain when fault tolerant was enabled.
            fx_file_write.c                                 Fixed a bug where data was overwritten when fault tolerant was enabled,
                                                              improved overwrite performance when the data to be overwritten are in one sector.
            fx_media_check.c                                Fixed entries of root directory.
            fx_media_check_FAT_chain_check.c                Fixed the upper bound check for the cluster value.
            fx_media_flush.c                                Added bitmap flush for exFAT, and fixed bug for exFAT directory entry write.
            fx_media_close.c                                Fixed a bug for exFAT directory entry write.
            fx_utility_logical_sector_write.c               Invalidated the cache entries when they were
                                                              polluted by fault tolerant.
            fx_directory_entry_write.c                      Fixed a bug that lower case name used for short name.                


Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com

