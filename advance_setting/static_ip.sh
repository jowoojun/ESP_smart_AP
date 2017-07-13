#!/bin/sh

#create new interfaces file frome interfaces.bak
cat /home/pi/changgunLEE/esp_smart_ap/advance_setting/interfaces.bak > /etc/network/interfaces

#input
read -p "new ip address:" ip
read -p "new netmask:" nm
read -p "new network:" nw
read -p "new broadcast:" bc
read -p "new ip address limit(start):" is 
read -p "new ip address limit(end):" ie

# change interface file adding wlan0 data
echo "iface wlan0 inet static" >> /etc/network/interfaces
echo "address $ip" >> /etc/network/interfaces
echo "netmask $nm" >> /etc/network/interfaces
echo "network $nw" >> /etc/network/interfaces
echo "broadcast $bc" >> /etc/network/interfaces

# delete dnsmasq.conf
sudo rm /etc/dnsmasq.conf

# change dnsmasq file
echo "listen-address=$ip" > /etc/dnsmasq.conf
echo "dhcp-range=$is,$ie,12h" >> /etc/dnsmasq.conf
cat /home/pi/changgunLEE/esp_smart_ap/advance_setting/dnsmasq.bak >> /etc/dnsmasq.conf
