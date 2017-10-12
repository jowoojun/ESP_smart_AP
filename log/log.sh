#!/bin/sh

# run log_print
../log/log_print $1

# remove log.json
rm ../info/log.json

# move log.bak to log.json
mv ../info/log.bak ../info/log.json


