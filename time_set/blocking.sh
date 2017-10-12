#/bin/sh

# run time_set

echo "$9"
if [ "1" = "$9" ]; then
  ./time_set $1 $2 $3 $4 $5 $6 $7 $8
echo "timeset"
else
  pkill time_set 
echo "kil timeset"
fi

