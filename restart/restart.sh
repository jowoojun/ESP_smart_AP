#!/bin/sh

# stop
sudo service hostapd stop
sudo service dnsmasq stop

# start 
# ifdown ifup
sudo ifdown wlan0; sudo ifup wlan0

# restart hostapd
sudo service hostapd start

# restart dnsmasq
sudo service dnsmasq start

