#!/bin/sh

# print log
sudo /home/pi/project/esp_smart_ap/log/log.sh change_blocksite_category

# backup file
sudo /home/pi/project/esp_smart_ap/initial_bakup/initial_bakup.sh

# reload e2guardian
echo "restart e2guardian"
sudo e2guardian -q
sudo e2guardian
