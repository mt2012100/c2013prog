#!/bin/sh
#display all number from 1 to 2i.
echo  "Please Enter i values."
read x
j=1
i=$x
k=`expr $i \* 2`
echo "values output is."
while [ $j -le $k ]
do
    echo "$j"
   j=`expr $j + 1`
done
