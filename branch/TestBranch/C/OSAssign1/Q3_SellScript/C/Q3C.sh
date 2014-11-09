#!/bin/sh

#File name	:	file_extension.sh
#description	:	modify the file name with date and extension eg tem.txt to tem-20121225.txt
#created By	:	Pratibind Kunar Jha

#current date in yearmonthday formate.
ISODATE=`date +%G%m%d`

#echo "Enter File name with extension."
#read filename
if [ $# -ne 1 ]
then
	echo "Please provide the filename as command line argument."
	exit 1;
fi
filename=$1
#check file name is vaild or not.
if [ ! -f $filename ]
	then
   		echo "Please Enter a Valid file name."
   		exit 1;
fi
#f_name=`basename $filename`

#find the length of a filename.
length=`expr $filename | wc -c`
end_pos=`expr $length - 1`

#echo "$length"

#find the index postion of chracter '.' !
index_of_dot=`expr $filename : '[^.]*.'`

#echo "$index_of_dot"

#checking for existance of extension of file.
if [ $index_of_dot -eq $end_pos ]
then
	echo "file name is without extension."
	
	#file name cancatenate ith date without extension of a file
	strs=$filename-$ISODATE
else
	#echo "$index_of_dot"
	
	pos=`expr $index_of_dot - 1`

	#retrive the filename without extension.
	strs=`expr $filename | cut -c 1-$pos`

	#retive the extension part of filename with '.' !
	extension=`expr $filename | cut -c $index_of_dot-$end_pos`

	#concatenate the filename with date and extension.
	strs=$strs-$ISODATE$extension
fi

#echo "$extension"
#echo "$pos"
#echo "$strs"

if [ -f $strs ]
then
	echo "$strs already exist in file system."
	exit 1;
fi

mv $filename $strs

if [ $? ]
then
	echo "$filename has modified to $strs successfully."
fi
