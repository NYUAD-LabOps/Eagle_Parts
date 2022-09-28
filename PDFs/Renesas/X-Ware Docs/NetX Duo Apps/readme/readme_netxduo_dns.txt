Revision History for NetX Duo DNS

Release 5.11  07-15-2018

            demo_netxduo_dns.c                      Supported for disabling IPv4 feature.

            nxd_dns.c                               Added the check for record count pointer.
                                                      Functions are modified: 
                                                      _nxe_dns_ipv4_address_by_name_get()
                                                      _nxde_dns_ipv6_address_by_name_get()
                                                      _nxe_dns_domain_name_server_get()
                                                      _nxe_dns_domain_mail_exchange_get()
                                                      _nxe_dns_domain_service_get()

                                                    Supported for disabling IPv4 feature.

                                                    Dropped the chained packet to avoid memory overflow.

                                                    Improved packet length verification.

                                                    Fixed a bug that mutex is not released before return.

                                                    Improved internal logic.
                                                      Functions are modified:
                                                      _nx_dns_cname_get()
                                                      _nx_dns_host_text_get()
                                                      _nx_dns_authority_zone_start_get()
                                                      _nx_dns_host_resource_data_by_name_get()
                                                      _nx_dns_response_process()
                                                      _nx_dns_server_remove_internal()
                                                      _nx_dns_process_cname_type()
                                                      _nx_dns_process_txt_type()
                                                      _nx_dns_process_soa_type()
                                                      _nx_dns_cache_add_string()
                                                      _nx_dns_cache_delete_string()

Release 5.10  05-10-2016

            *.c                                     Modified comments.
            *.h                                     Modified comments.

Release 5.9   02-22-2016

            demo_netxduo_dns.c                      Unified ticks per second. 
            
                                                    Fixed compiler warnings.

            nxd_dns.h                               Unified ticks per second.

                                                    Removed the symbol NX_DNS_CLIENT_IP_GATEWAY_ADDRESS.
                                                    
            nxd_dns.c                               Unified ticks per second.

                                                    Modified the logic to send DNS query in _nx_dns_host_resource_rdata_by_name_get and 
                                                    _nx_dns_host_by_address_get_internal.

                                                    Modified the return status in _nx_dns_send_query_by_address. 

                                                    Modified the return status if answer_found is true in _nx_dns_response_process. 
                                                    
                                                    Modified the logic for setting the IP gateway server to be the DNS Server in _nx_dns_create.
                                                    
                                                    Added check for malformed packet.
            
                                                    Fixed compiler warnings.

                                                    Added the check for record_count_pointer.
 
Release 5.8   01-12-2015

        
            nxd_dns.c                               Added two new services, nx_dns_server_remove_all() which removes all DNS servers 
                                                    registered with the DNS Client, and nx_dns_info_by_name_get() which gets the
                                                    Service record associated with the specified host name.  These services sere
                                                    previously only available in NetX DNS Client. 

                                                    Fixed a bug in nxd_dns_response_process() that return error code if the packet 
                                                    does not contain the RR the application expects.

                                                    Fixed a bug in nx_dns_name_string_unencode() that return error code if the buffer
                                                    size can not store the all name string. 

                                                    Change the internal nxd_* function and nxd_* variables to nx_* function and nx_* variables.                                                
    
                                                    Added DNS CACHE feature.
    
            nxd_dns.h                               Added two new services, nx_dns_server_remove_all() and nx_dns_info_by_name_get().

                                                    Added DNS CACHE feature.


Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com

