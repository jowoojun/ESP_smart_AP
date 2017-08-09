#!/bin/sh

#ruen the change_netmask.c file
sudo ./change_netmask $1

#remove the interfaces file
sudo rm /etc/network/interfaces
#change interfaces.bak to interfaces
sudo mv /etc/network/interfaces.bak /etc/network/interfaces
