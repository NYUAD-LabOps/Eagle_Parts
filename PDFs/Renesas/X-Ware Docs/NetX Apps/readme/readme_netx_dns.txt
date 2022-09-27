Revision History for NetX DNS

Release 5.11  07-15-2018

            nx_dns.c                                Added the check for record count pointer.
                                                      Functions are modified: 
                                                      _nxe_dns_ipv4_address_by_name_get()
                                                      _nxe_dns_domain_name_server_get()
                                                      _nxe_dns_domain_mail_exchange_get()
                                                      _nxe_dns_domain_service_get()

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

            demo_netx_dns.c                         Unified ticks per second. 
            
                                                    Fixed compiler warnings.

            nx_dns.h                                Unified ticks per second.
            
                                                    Removed the symbol NX_DNS_CLIENT_IP_GATEWAY_ADDRESS.

            nx_dns.c                                Unified ticks per second.

                                                    Modified the logic to send DNS query in _nx_dns_host_resource_rdata_by_name_get and 
                                                    _nx_dns_host_by_address_get_internal.

                                                    Modified the return status in _nx_dns_send_query_by_address. 

                                                    Modified the return status if answer_found is true in _nx_dns_response_process. 
                                                    
                                                    Modified the logic for setting the IP gateway server to be the DNS Server in _nx_dns_create.                                                    
                                                    
                                                    Added check for malformed packet.
            
                                                    Fixed compiler warnings.

                                                    Added the check for record_count_pointer.

01-12-2015  Initial DNS generic code version 5.8.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com

