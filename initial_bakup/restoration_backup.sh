#!/bin/sh

# make interfaces initial bakup file
sudo mv /etc/network/interfaces.inbak /home/initial_bakup/interfaces

# make dnsmasq.conf initial bakup file
sudo mv /etc/dnsmasq_conf.inbak /home/initial_bakup/dnsmasq.conf

# make hostapd.conf initial bakup file
sudo mv /etc/hostapd/hostapd_conf.inbak /home/initial_bakup/hostapd.conf

# make bannedsitelist initial bakup file
sudo mv /usr/local/etc/e2guardian/lists/bannedsitelist.inbak /usr/local/etc/e2guardian/lists/bannedsitelist
