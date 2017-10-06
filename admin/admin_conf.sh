#!/bin/sh

# run change_ssid.c
sudo /home/pi/project/esp_smart_ap/admin/change_ssid $1

# remove conf file and change bak file to conf file
sudo rm /etc/hostapd/hostapd.conf
sudo mv /etc/hostapd/hostapd.bak /etc/hostapd/hostapd.conf

# run change_pwd.c
sudo /home/pi/project/esp_smart_ap/admin/change_pwd $2

# remove conf file and change bak file to conf file
sudo rm /etc/hostapd/hostapd.conf
sudo mv /etc/hostapd/hostapd.bak /etc/hostapd/hostapd.conf

# Add a log text in log file
sudo /home/pi/project/esp_smart_ap/log/log_print change_ssid
sudo /home/pi/project/esp_smart_ap/log/log_print change_pwd

# backup file
sudo /home/pi/project/esp_smart_ap/initial_bakup/initial_bakup.sh
