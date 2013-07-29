#!/bin/sh
#Enter the file name as command Line argument.
#echo "Enter file nane." > /dev/tty
#read filename
if [ $# -ne 1 ]
	then
		echo "Please Enter the file name as commandLine argument."
		exit 1;
fi	

filename=$1
#replace all horse word from elephant from filename and redirect
# the output to temproray 
sed s/horse/elephant/g $filename > $$
mv $$ $filename
if [ $? -eq 0 ]
	then
		echo "$filename modify success."
fi
touch -m -t 201301011200  $filename
#last modification time.. `date -r emp.list`
if [ $? -eq 0 ]
	then
		echo "$filename date modify success."
fi
