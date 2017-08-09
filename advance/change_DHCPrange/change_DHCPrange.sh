#!/bin/sh

#run the change_DHCPrange.c 
sudo ./change_DHCPrange $1 $2

#remove dnsmasq.conf
sudo rm /etc/dnsmasq.conf

#change the name of dnsmasq.bak to dnsmasq.conf
sudo mv /etc/dnsmasq.bak /etc/dnsmasq.conf

