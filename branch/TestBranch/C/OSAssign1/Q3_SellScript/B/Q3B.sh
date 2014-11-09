#!/bin/sh
#Display all executable file present in curremt directory.
#read filename
#ls -l /pratibind/$filename | grep ".........x"
for i in `ls` 
do
	if [ -f $i ] 
	then
		if [ -x $i ] 
		then
			echo "$i"
		fi
	fi
done
