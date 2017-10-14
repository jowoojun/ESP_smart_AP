#/bin/sh

# print log
../log/log.sh time_set

# make json file
../time_set/make_time_set_json $1 $2 $3 $4 $5 $6 $7 $8 $9

# run time_set
if [ "1" = "$9" ]; then
   ../time_set/time_set $1 $2 $3 $4 $5 $6 $7 $8 $9 & 
echo "timeset"
else
  pkill time_set 
echo "kil timeset"
fi

