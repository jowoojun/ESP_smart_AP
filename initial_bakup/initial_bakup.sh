#!/bin/sh

# make interfaces initial bakup file
sudo cp /etc/network/interfaces /home/initial_bakup/interfaces.inbak

# make dnsmasq.conf initial bakup file
sudo cp /etc/dnsmasq.conf /home/initial_bakup/dnsmasq_conf.inbak

# make hostapd.conf initial bakup file
sudo cp /etc/hostapd/hostapd.conf /home/initial_bakup/hostapd_conf.inbak
