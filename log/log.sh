#!/bin/sh

# run log_print
./log_print $1

# remove log.json
rm ./log.json

# move log.bak to log.json
mv ./log.bak ./log.json


