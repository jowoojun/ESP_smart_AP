#!/bin/sh

read ip

# specific ip internet on
sudo iptables -D FORWARD -s $ip -j DROP 
