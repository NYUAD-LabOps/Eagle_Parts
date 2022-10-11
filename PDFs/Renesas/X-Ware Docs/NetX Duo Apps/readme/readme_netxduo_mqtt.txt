Revision History for NetX Duo MQTT


Release 5.11  07-15-2018

            nxd_mqtt_client.c           Improved packet length verification.
                                        Removed the usage of global variable for MQTT client.
                                        Added logic to prevent packet ID value from being zero.
                                        Fixed a bug that packet may be queued by TLS and can not be received.
                                        Added a symbol for user to set initial packet ID value.
                                        Improved internal logic.
                                        Modified _nxd_mqtt_process_disconnect to use the NXD_MQTT_SOCKET_TIMEOUT as the wait option
                                        Modified _nxd_mqtt_packet_allocate to use TLS packet allocate for TLS socket.  TLS packet allocate routine is able to 
                                          take into consideration the TLS header size, including the crypto initial vector area.
                                        Modified _nxd_mqtt_client_publish to fix packet leak, and use packet append API instead of memcpy to prevent data 
                                          overflow the packet strcutre.
                                        Modified _nxd_mqtt_client_sub_unsub to fix a ptoential packet leak under error conditions.
                                        Modified _nxd_mqtt_client_disconnect to not exit if the send message calls returns an error. Added a call to delete the timer
                                          so that a subsequent connect call will not error out when it tries to create the already existing timer. 
                                        Modified _nxd_mqtt_thread_entry to delete the TCP socket. Added logic to check if 
                                          timer, event flag group are already deleted before deleting. Moved the socket delete call to the end of the function  
                                        Modified _nxd_mqtt_client_create to create the socket instead of in the connect call. Delete the MQTT thread if an error occurs.
                                        Modified _nxd_mqtt_client_connect to remove the socket create call, and removed socket delete calls where an error is handled. 
                                        Delete the timer if an error occurs. Replaced NX_WAIT_FOREVER with NXD_MQTT_SOCKET_TIMEOUT on the socket receive calls.  
                                        Modified _nxd_mqtt_client_delete to wait for the nxd_mqtt_client_thread_entry to complete processing the DELETE event. 
                                        Modified _nxde_mqtt_client_login_set to allow user to set username but not password.
                                        Added call to delete the MQTT thread after the DELETE event is finished processing. 
                                        Supported user defined memory functions.
                                        Added symbols NXD_MQTT_REQUIRE_TLS, NXD_MQTT_SECURE_MEMCPY, NXD_MQTT_SECURE_MEMCMP, NXD_MQTT_SECURE_MEMSET, NXD_MQTT_SECURE_MEMMOVE for
                                          security requirement.
                                        Checked topic name and message lengths in runtime.
                                        Allowed zero length of username and password. 

            nxd_mqtt_client.h           Added NXD_MQTT_SOCKET_TIMEOUT to put a finite timeout for nx_tcp_socket_disconnect. 
                                        The default value is NX_WAIT_FOREVER so no difference in behavior should be observed. 
                                        Supported user defined memory functions.
            
Release 5.10  08-01-2017                Initial release.

Copyright(c) 1996-2018 Express Logic, Inc.


Express Logic, Inc.
11423 West Bernardo Court
San Diego, CA  92127

www.expresslogic.com

