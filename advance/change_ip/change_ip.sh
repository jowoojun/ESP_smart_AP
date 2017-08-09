#! /bin/sh

# run change_ip.c
sudo ./change_ip $1

# remove interfaces file and change interfaces.bak file to interfaces file
sudo rm /etc/network/interfaces
sudo mv /etc/network/interfaces.bak /etc/network/interfaces

# remove dnsmasq.conf file and change dnsmasq.bak file to dnsmasq.conf file
sudo rm /etc/dnsmasq.conf
sudo mv /etc/dnsmasq.bak /etc/dnsmasq.conf
