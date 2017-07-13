#!/bin/sh

#create new interfaces file frome interfaces.bak
cat /home/pi/changgunLEE/esp_smart_ap/advance_setting/interfaces.bak > /etc/network/interfaces

#add wlan0 data
echo "iface wlan0 inet dhcp" >> /etc/network/interfaces

sudo service dhcpcd restart

