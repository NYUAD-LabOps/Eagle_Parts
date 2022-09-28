Revision History for NetX Duo SNMP Agent

Release 5.11  07-15-2018

            nxd_snmp.c                      Supported for disabling IPv4 feature.
                                            Dropped the chained packet to avoid memory overflow.
                                            Added buffer length check.
                                            Fixed packet leak issue.
                                            Modified logic of converting to UCHARs for the buffer.
                                            Removed logic setting boot count to one if not set.
                                            Fixed a bug to use the trap security flags instead of the agent security flags.
                                            Fixed bug to use context name from get request if agent context name not set.
                                            Improved internal logic.
                                            Modified nx_snmpv3_agent_engineboot_set to accept boot count of zero
                                            Fixed nx_snmp_utility_object_data_get, nx_snmp_object_counter64_get/set, 
                                              nx_snmp_object_octet_string.get for errors in data processing.
                                             Added new parsing route nx_snmp_tlv_parse_data to parse the Type-Length-Value
                                              field as per ASN1 specificactions, this also handles the 'long form' for integer types
                                            Added check for counter64 type to nx_snmp_v1/v2/v3_processing 
                                            Added an error response to nx_snmp_v1/v2/v3_processing if nx_snmp_object_data_get returns an error
                                              instead of failing silently.
                                            Modified nx_snmp_utility_object_data_get to accept a null IPv4 address. 


            nxd_snmp.h                      Removed #include nx_tcp.h
                                            Added macros for ASN1/BER standard symbols used in TLV parsing routine 
                                            Added new error returns relevant to the TLV parsing added.
                                            Redefined IPv6 address type as NX_SNMP_ASN1_OCTET_STRING

            demo_snmp_helper.h              Removed #include nx_tcp.h and references to TCP configuration options defined in nx_tcp.h.
                                            Added a get_octet_callback() which is similar to the get_callback except that it includes the length
                                               arguement to accomodate the nx_snmp_object_octet_string_get API
                                            Added a length field to MIB table for reading octet strings which not 0x0 delimited. 
                                            Simplified the table to a few dozen OIDs instead of a hundreds of OID for ease of use.
                                            Added atIPv6NetworkAddress[16] and MIB table entry for it for testing IPv6 address types

            demo_netxduo_snmp.c             Simplified mib2_variable_update to be a comment that this is where MIB data can be updated at runtime. 
                                            Removed printf statements.
                                            Added check of status returns from SNMP API that were missing them. 

            demo_netxduo_mib2.c             Removed the demo file since demo_netx_snmp.c is sufficient to demonstrate the use of SNMP API
                                               for managing the MIB table. 
                          


Release 5.10  05-10-2016

            *.c                             Modified comments.
            *.h                             Modified comments.


Release 5.9   02-22-2016

            demo_netxduo_mib2.c             Unified ticks per second.
                                              Fixed compiler warnings.

            demo_netxduo_snmp.c             Unified ticks per second.
                                              Fixed compiler warnings.

                                            Replace #ifdef ENABLE_V3 with #ifndef NX_SNMP_DISABLE_V3 to eliminate compile errors
                                                if NX_SNMP_DISABLE_V3 is defined in SNMP.

            demo_snmp_helper.h              Fixed compiler warnings.

            nxd_snmp.c
                                            Modified nx_snmp_version3_report_send() :
                                                1) never encrypt data in a report response
                                                2) never to set encryption or reportable bit in security header flags field,
                                                3) if sending time synchronization report, only use authentication even if encryption is enabled,
                                                4) never send boot data in response to a discovery request.

                                            Modified nx_snmp_version3_process() :
                                                1) Flags in the security header should never have reportable bit sent
                                                2) never send boot data if authentication is not enabled.

                                            Modified nx_snmp_version3_process where it sets the request_type_ptr
                                                for returning the request packet with an error status.

                                            Renamed _nx_snmp_utility_request_type_set_A5 to _nx_snmp_utility_request_type_set_multibyte
                                            Removed _nx_snmp_utility_request_type_set (use only _nx_snmp_utility_request_type_set_1byte)

                                            Modified nx_snmp_send_error_response() and nx_snmp_encrypt_pdu for handling SNMPV3 request packet PDUs
                                                for error messages when security is enabled.

                                            Replaced 1 byte data size fields with 2 byte data size fields in sequence headers in trap send,
                                                and SNMP message process functions, wherever there is a possibility the data may exceed 128 bytes
                                                (and thus require 2 bytes).

                                            Modified logic in data object get functions to determine the size of the data size field rather than
                                                assume 2 bytes (e.g. _nx_snmp_utility_community_get, _nx_snmp_utility_object_id_get,
                                                _nx_snmp_utility_object_data_get).

                                            Fixed a bug in _nx_snmp_agent_encrypt_pdu for not adjusting encrypted PDU length for non-zero padding.

                                            Added a null pointer check for the object list pointer in the trap functions when going through
                                                the PDU object list items.

                                            Added NX_SNMP_V3_DISABLE conditional compile directives around global PDU processing variables and in
                                                _nx_snmp_version_error_response relevant for V3 security specific processing.

                                            Fixed compiler warnings.

                                            Minor correction masking the length variable.



            nxd_snmp.h
                                            Renamed _nx_snmp_utility_request_type_set_A5 to _nx_snmp_utility_request_type_set_multibyte.

                                            Removed _nx_snmp_utility_request_type_set (use only _nx_snmp_utility_request_type_set_1byte).

                                            Changed the order of internal functions for more logical grouping.

                                            Unified ticks per second.

                                            Added #ifdef NX_SNMP_V3_DISABLE checks around #includes for authentication
                                                and encryption key processing, and around API fucntions that compute and activate keys.

                                            Removed unused extern nx_system_ticks_per_second.


Release 5.8   01-12-2015

            nxd_snmp.c                       Renamed API to be consistent with Express Logic names:

                                                     nx_snmp_agent_get_current_version to nx_snmp_agent_current_version_get
                                                     nx_snmp_agent_set_current_version to nx_snmp_agent_current_version_set
                                                     nx_snmp_agent_set_private_string to nx_snmp_agent_private_string_set
                                                     nx_snmp_agent_set_public_string to nx_snmp_agent_public_string_set
                                                     nx_snmp_agent_received_private_string to nx_snmp_agent_private_string_test

                                             Simplified the logic in _nx_snmp_agent_private_string_test.

                                             Used zero as terminal of string in _nx_snmp_agent_private_string_set
                                                     and _nx_snmp_agent_public_string_set.

                                             Created nx_snmp_agent_public_string_set to set the SNMP Agent public string.

                                             Created nx_snmp_agent_get_type_test to determine if an SNMP message received
                                                     is a GET or SET type.

                                             Modified nx_snmp_version_1_process, nx_snmp_version_2_process and nx_snmp_version_3_process
                                                     to support the nx_snmp_agent_get_type_test service (save the request
                                                     type of the current received message).

                                             Created nxd_snmp_agent_trapv2_oid_send and nxd_snmp_agent_trapv3_oid_send services.

            nxd_snmp.h                       Renamed API to be consistent with Express Logic names:
                                                     nx_snmp_agent_get_current_version to nx_snmp_agent_current_version_get
                                                     nx_snmp_agent_set_version to nx_snmp_agent_version_set
                                                     nx_snmp_agent_set_private_string to nx_snmp_agent_private_string_set
                                                     nx_snmp_agent_set_public_string to nx_snmp_agent_public_string_set
                                                     nx_snmp_agent_received_private_string to nx_snmp_agent_private_string_test

                                             Added new API nx_snmp_agent_public_string_set and nx_snmp_agent_request_get_type_test

                                             Created nxd_snmp_agent_trapv2_oid_send and nxd_snmp_agent_trapv3_oid_send services.

NetX Duo SNMP Agent v5.2

            nxd_snmp.c                       Added support for packet chaining

                                             Moved nx_udp_socket_bind call from nx_snmp_agent_create to nx_snmp_agent_start
                                                   moved nx_udp_socket_unbind in nx_snmp_agent_stop. This prevent packets from
                                                   piling up on the receive queue before the SNMP agent thread can start processing them.

                                             Corrected how SNMPv3 packets are encrypted by adding an extra sequence between the top level
                                                   PDU sequence and the engine ID. nx_snmp_version_3_process, nx_snmp_version_3_report_send
                                                   and nx_snmp_agent_encrypt_pdu modified accordingly.

                                             Added trap security to provide authentication and encryption for trap messages. The keys for trap message processing
                                                   can take separate passwords than the keys for processing responses messages.

                                             Added logic to handle empty strings in _nx_snmp_object_id_get

                                             Modified nx_snmp_version_3_process and nx_snmp_version_3_discovery to fix bugs handling discovery requests.

                                             Modified nx_snmp_version_3_process to fix bugs when authentication enabled.

                                             Added support for negative INTEGER data types in _nx_snmp_utility_object_data_get

                                             Added _nx_snmp_agent_v3_context_boots_get()

                                             Added support for setting SNMP version at run time and creating private community strings:

                                               Created nx_snmp_agent_get_current_version to determine the SNMP version of the most recent
                                                   SNMP manager packet sent to the agent.

                                               Created nx_snmp_agent_set_version to set the enable/disable the SNMP agent for SNMPV1,
                                                    SNMPV2, and SNMPv3.  These run time settings are overridden by the #defines
                                                    (NX_SNMP_DISABLE_V1, NX_SNMP_DISABLE_V2,  and NX_SNMP_DISABLE_V3 ).  Enabling the SNMP
                                                    agent for SNMPv1 at run time has no effect if NX_SNMP_DISABLE_V3 is defined.

                                               Created nx_snmp_agent_set_private_string to set the SNMP Agent private string. This enables
                                                    the agent to have public and private data, and if it will accept the SNMP manager
                                                    packet SET requests.

                                               Created nx_snmp_agent_set_public_string to set the SNMP Agent public string. The default value
                                                    is "public".  Previously the NetX Duo SNMP Agent did not evaluate the community string
                                                    and as such allowed all SET requests and all data was considered public.

                                               Created nx_snmp_agent_received_private_string to compare the community string
                                                    in the received SNMP packet with the Agent private string for a match.

                                             Modified nx_snmp_agent_version_1_process and nx_snmp_agent_version_2_process to
                                                    send an error report if an unsupported object type is received.

                                             Modified key use services to accept a null key pointer in the error handler; this allows the caller
                                                    to disable authentication or encryption at run time.


            nxd_snmp.h                       Added new API nx_snmp_agent_get_current_version, nx_snmp_agent_set_version,
                                                     nx_snmp_agent_set_private_string, nx_snmp_agent_set_public_string, and
                                                     nx_snmp_agent_received_private_string

                                             Modified the NX_SNMP_AGENT control block to support the new API/features.



Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com

