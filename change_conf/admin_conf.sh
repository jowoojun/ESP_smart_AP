#!/bin/sh

# run change_ssid.c
sudo ../change_conf/change_ssid $1

# remove conf file and change bak file to conf file
sudo rm /etc/hostapd/hostapd.conf
sudo mv /etc/hostapd/hostapd.bak /etc/hostapd/hostapd.conf

# run change_pwd.c
sudo ../change_conf/change_pwd $2

# remove conf file and change bak file to conf file
sudo rm /etc/hostapd/hostapd.conf
sudo mv /etc/hostapd/hostapd.bak /etc/hostapd/hostapd.conf

# Add a log text in log file
sudo ../log/log_print change_ssid
sudo ../log/log_print change_pwd

# backup file
sudo ../initial_bakup/initial_bakup.sh

# restart ap
sudo service hostapd stop
sudo service hostapd start
