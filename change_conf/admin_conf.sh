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
sudo ../log/log.sh change_ssid
sudo ../log/log.sh change_pwd

# make admin_conf.json file
../change_conf/make_admin_json $1 $2

# backup file
sudo ../initial_bakup/initial_bakup.sh

# restart ap
#sudo service hostapd restart
