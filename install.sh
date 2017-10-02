#!/bin/sh

# admin setting
gcc -o admin/change_ssid admin/change_ssid.c
gcc -o admin/change_pwd admin/change_pwd.c

# ip setting
gcc -o ip/change_ip ip/change_ip.c
gcc -o ip/change_netmask ip/change_netmask.c
gcc -o ip/change_DHCPrange ip/change_DHCPrange.c

# time setting
gcc -o time_set/time_set time_set/time_set.c


gcc -o log/log_print log/log_print.c
