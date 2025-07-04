
# Suggested completion order 

1. RoadRunner.c
    - perform_command
1. helloworld.c 
    [X] say_hello
1. core.c
    [X] checkin_command
        - Tests: should_provide_checkin_response

    [X] sleep_command
        - Tests: should_execute_good_sleep_cmd, should_error_on_bad_sleep_args
1. sys.c
    [?] hostname_command **CHECK WITH INSTRUCTORS**
        - Tests: should_provide_hostname_response, should_error_failed_hostname

1. Files.c
    [X] download_file_command
        - Tests: should_provide_download_response, should_error_on_bad_download_file_name
    [X] read_file
        - Tests: should_read_good_file, should_error_read_on_bad_file
    [X] write_file
        - Tests: should_write_file, should_error_on_write_null
            
1. sys.c
    [X] invoke_command
        - Tests: should_provide_valid_cmd_return, should_touch_file_with_invoke
1. roadrunner.c
    [X] connect_to_server
    [X] send_response
    [X] receive_command
1. commands.c
    [X] serialize_response
    [X] deserialize_command
1. files.c
    - deserialize_file_command
    - deserialize_upload_file_contents
    - upload_file_command
        - Tests:  should_provide_upload_response, should_error_on_bad_upload_file_name_length, should_error_on_bad_upload_content_length
1. proxy.c
    - deserialize_target_host
    - deserialize_target_and_local_ports
    - open_proxy
    - listen_for_connections
    - connect_to_target
    - setup_epoll
    - perform_proxy
1. sys.c
    - parse_conn_line
    - print_connections
    - hex_to_ipaddr
    - free_connections
    - get_netstat_command
        - Tests: should_error_fail_netstat, should_provide_valid_netstat
    - process_list_command
