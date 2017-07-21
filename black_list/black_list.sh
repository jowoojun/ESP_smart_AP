#!/bin/sh

if [ "$1" = "allow" ];then
    #run allow.c
       
    iptables="iptables -D FORWARD -m mac --mac-source $2 -j DROP"
    
    sudo $iptables

    sudo ./allow
    
    sudo rm /home/pi/changgunLEE/esp_smart_ap/black_list/list.sh
    sudo mv /home/pi/changgunLEE/esp_smart_ap/black_list/list.bak /home/pi/changgunLEE/esp_smart_ap/black_list/list.sh

    sudo chmod 755 /home/pi/changgunLEE/esp_smart_ap/black_list/list.sh
fi

if [ "$1" = "cut" ];then
    #run cut.c

    iptables="iptables -A FORWARD -m mac --mac-source $2 -j DROP"
    
    sudo $iptables
    
    sudo ./cut $2
    
    sudo rm /home/pi/changgunLEE/esp_smart_ap/black_list/list.sh
    sudo mv /home/pi/changgunLEE/esp_smart_ap/black_list/list.bak /home/pi/changgunLEE/esp_smart_ap/black_list/list.sh

    sudo chmod 755 /home/pi/changgunLEE/esp_smart_ap/black_list/list.sh
fi

if [ "$1" = "initial" ];then
    sudo ./iptables_reset.sh
fi
