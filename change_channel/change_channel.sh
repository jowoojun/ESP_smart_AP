#!/bin/sh

# initial bakup file
sudo cp /etc/hostapd/hostapd.conf /etc/hostapd/hostapd.initial_bakup

# run change_channel.c
sudo ./change_channel $1

# remove conf file and change bak file to conf file
sudo rm /etc/hostapd/hostapd.conf
sudo mv /etc/hostapd/hostapd.bak /etc/hostapd/hostapd.conf

# restart hostapde
sudo service hostapd restart
