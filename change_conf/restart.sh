#!/bin/sh

# stop
sudo service hostapd stop
sudo service dnsmasq stop

# start 
# ifdown ifup
sudo ifdown wlan0; sudo ifup wlan0

# restart dnsmasq
sudo service dnsmasq start

# restart hostapd
sudo service hostapd start


