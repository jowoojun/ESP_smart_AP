#!/bin/sh
#delete hostapd.conf
sudo rm /etc/hostapd/hostapd.conf

#change ssid
echo "#This is the name of the network" > /etc/hostapd/hostapd.conf
echo "ssid=$1\n" >> /etc/hostapd/hostapd.conf

#change pwd
echo "#The network passphrase" >> /etc/hostapd/hostapd.conf
echo "wpa_passphrase=$2\n" >>  /etc/hostapd/hostapd.conf

#hostapd_conf.bak add to hostapd.conf
cat /home/pi/changgunLEE/esp_smart_ap/normal_setting/hostapd_conf.bak >> /etc/hostapd/hostapd.conf

#restart hostadp
sudo service hostapd restart

#print msg
echo change ssid and pwd
echo restart hostapd

