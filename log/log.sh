#! /bin/sh

# compile c file
gcc -o switch_json switch_json.c

#log file to change log.josn file
sudo ./switch_json

# clean the file ap_system.log
# sudo echo "" > ap_system.log

# remove binary file
rm switch_json

