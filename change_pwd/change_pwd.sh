#!/bin/sh

# run change_ssid.c
sudo ./change_pwd $1

# remove conf file and change bak file to conf file
sudo rm /etc/hostapd/hostapd.conf
sudo mv /etc/hostapd/hostapd.bak /etc/hostapd/hostapd.conf

# restart hostapde
sudo service hostapd restart
