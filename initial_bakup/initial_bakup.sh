#!/bin/sh

# make interfaces initial bakup file
sudo cp /etc/network/interfaces /etc/network/interfaces.inbak

# make dnsmasq.conf initial bakup file
sudo cp /etc/dnsmasq.conf /etc/dnsmasq_conf.inbak

# make hostapd.conf initial bakup file
sudo cp /etc/hostapd/hostapd.conf /etc/hostapd/hostapd_conf.inbak

# make bannedsitelist initial bakup file
sudo cp /usr/local/etc/e2guardian/lists/bannedsitelist /usr/local/etc/e2guardian/lists/bannedsitelist.inbak
