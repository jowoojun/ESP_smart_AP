#!/bin/sh

#ifdown ifup
sudo ifdown wlan0; sudo ifup wlan0

#restart hostapd
sudo service hostapd restart

#restart dnsmasq
sudo service dnsmasq restart

