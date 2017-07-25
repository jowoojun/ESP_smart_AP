#!/bin/sh

#make initial bakup
sudo cp interfaces interfaces.initial_bakup

#have to change the interface
#choose ip way
if [ "$1" =  "static" ];then 
    # setting for static ip
    # run C file 
    sudo ./change_static_ip
fi

if [ "$1" =  "dynamic" ];then 
    # setting for dynamic ip
    # run C file
    sudo ./change_dynamic_ip
fi

sudo rm /etc/network/interfaces
sudo mv /etc/network/interfaces.bak /etc/network/interfaces

exit 0;
