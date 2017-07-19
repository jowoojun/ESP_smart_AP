#!/bin/sh

read -p "main_DNS:" main_DNS
read -p "sub_DNS:" sub_DNS

#add DNS address
echo "server=$main_DNS , $sub_DNS" >>  >> /etc/dnsmasq.conf

