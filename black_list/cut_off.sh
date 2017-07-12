#!/bin/sh

read ip

# specific ip internet off
sudo iptables -I FORWARD 1 -s $ip -j DROP
