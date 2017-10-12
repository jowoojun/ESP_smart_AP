#!/bin/sh

# run change_ip.c
sudo ../change_conf/change_ip $1

# remove interfaces file and change interfaces.bak file to interfaces file
sudo rm /etc/network/interfaces
sudo mv /etc/network/interfaces.bak /etc/network/interfaces

# remove dnsmasq.conf file and change dnsmasq.bak file to dnsmasq.conf file
sudo rm /etc/dnsmasq.conf
sudo mv /etc/dnsmasq.bak /etc/dnsmasq.conf

#run the change_netmask.c file
sudo ../change_conf/change_netmask $2

#remove the interfaces file
sudo rm /etc/network/interfaces
#change interfaces.bak to interfaces
sudo mv /etc/network/interfaces.bak /etc/network/interfaces

#run the change_DHCPrange.c 
sudo ../change_conf/change_DHCPrange $3 $4

#remove dnsmasq.conf
sudo rm /etc/dnsmasq.conf

#change the name of dnsmasq.bak to dnsmasq.conf
sudo mv /etc/dnsmasq.bak /etc/dnsmasq.conf

# make json file
../change_conf/make_ip_json $1 $2 $3 $4
../change_conf/make_ap_json $3 $4

# Add a log tet in logfile
sudo ../log/log.sh change_ip 
sudo ../log/log.sh change_netmask 
sudo ../log/log.sh change_DHCPrange

# backup file
sudo ../initial_bakup/initial_bakup.sh

# restart ap system
sudo ../change_conf/restart.sh
