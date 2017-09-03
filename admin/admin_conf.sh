#!/bin/sh

# compile c file change_ssid.c and chage_pwd.c
gcc -o change_ssid change_ssid.c
gcc -o change_pwd change_pwd.c

# run change_ssid.c
sudo ./change_ssid $1

# remove conf file and change bak file to conf file
sudo rm /etc/hostapd/hostapd.conf
sudo mv /etc/hostapd/hostapd.bak /etc/hostapd/hostapd.conf

# run change_pwd.c
sudo ./change_pwd $2

# remove conf file and change bak file to conf file
sudo rm /etc/hostapd/hostapd.conf
sudo mv /etc/hostapd/hostapd.bak /etc/hostapd/hostapd.conf

# remove binay files
rm change_ssid
rm change_pwd
