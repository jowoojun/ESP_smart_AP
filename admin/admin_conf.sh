#!/bin/sh

# run change_ssid.c
sudo ./change_ssid $1

# remove conf file and change bak file to conf file
sudo rm /etc/hostapd/hostapd.conf
sudo mv /etc/hostapd/hostapd.bak /etc/hostapd/hostapd.conf


# Add a log text in log file
sudo ../log/log_print change_ssid

# run change_pwd.c
sudo ./change_pwd $2

# remove conf file and change bak file to conf file
sudo rm /etc/hostapd/hostapd.conf
sudo mv /etc/hostapd/hostapd.bak /etc/hostapd/hostapd.conf

# Add a log text in log file
sudo ../log/log_print change_pwd
