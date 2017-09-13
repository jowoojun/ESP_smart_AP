#!/bin/sh

# compile c file 
gcc -o change_ip change_ip.c
gcc -o change_netmask change_netmask.c
gcc -o change_DHCPrange change_DHCPrange.c

# run change_ip.c
sudo ./change_ip $1

# remove interfaces file and change interfaces.bak file to interfaces file
sudo rm /etc/network/interfaces
sudo mv /etc/network/interfaces.bak /etc/network/interfaces

# remove dnsmasq.conf file and change dnsmasq.bak file to dnsmasq.conf file
sudo rm /etc/dnsmasq.conf
sudo mv /etc/dnsmasq.bak /etc/dnsmasq.conf

#run the change_netmask.c file
sudo ./change_netmask $2

#remove the interfaces file
sudo rm /etc/network/interfaces
#change interfaces.bak to interfaces
sudo mv /etc/network/interfaces.bak /etc/network/interfaces

#run the change_DHCPrange.c 
sudo ./change_DHCPrange $3 $4

#remove dnsmasq.conf
sudo rm /etc/dnsmasq.conf

#change the name of dnsmasq.bak to dnsmasq.conf
sudo mv /etc/dnsmasq.bak /etc/dnsmasq.conf

# remove binary files
rm change_ip
rm change_netmask
rm change_DHCPrange


