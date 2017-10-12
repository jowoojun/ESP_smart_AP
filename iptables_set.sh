#!/bin/bash
sudo iptables -t nat -A POSTROUTING -s 172.24.1.0/24 ! -d 172.24.1.0/24 -j MASQUERADE

sudo iptables -A PREROUTING -t nat -p tcp --destination-port 80 -j REDIRECT --to-ports 8080

sudo iptables -A PREROUTING -t nat -p tcp --destination-port 443 -j REDIRECT --to-ports 8080

sudo iptables-save | sudo tee /etc/iptables/rules.v4


sudo iptables -F
sudo iptables -X
sudo iptables -t nat -F
sudo iptables -t nat -X
sudo iptables -A INPUT -i lo -j ACCEPT
sudo iptables -A OUTPUT -o lo -j ACCEPT
sudo iptables -A INPUT -i wlan0 -j ACCEPT
sudo iptables -A OUTPUT -o wlan0 -j ACCEPT
sudo iptables -t nat -A PREROUTING -p tcp  --dport 80 -j REDIRECT --to 8080
sudo iptables -A POSTROUTING -t nat -o eth0 -j MASQUERADE
sudo iptables -A FORWARD -i wlan0 -j ACCEPT
sudo iptables-save > /etc/iptables.ipv4.nat
sudo sysctl -p

sudo e2guardian
sudo service tinyproxy start
