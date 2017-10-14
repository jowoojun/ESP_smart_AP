#!/bin/sh

# admin setting
gcc -o change_conf/change_ssid change_conf/change_ssid.c
gcc -o change_conf/change_pwd change_conf/change_pwd.c

# ip setting
gcc -o change_conf/change_ip change_conf/change_ip.c
gcc -o change_conf/change_netmask change_conf/change_netmask.c
gcc -o change_conf/change_DHCPrange change_conf/change_DHCPrange.c

# time setting
gcc -o time_set/time_set time_set/time_set.c
gcc -o time_set/make_time_set_json time_set/make_time_set_json.c

gcc -o log/log_print log/log_print.c

gcc -o block/filtering block/filtering.c

# make json file.c 
gcc -o change_conf/make_ip_json change_conf/make_ip_json.c
gcc -o change_conf/make_admin_json change_conf/make_admin_json.c
gcc -o change_conf/make_ap_json change_conf/make_ap_json.c
