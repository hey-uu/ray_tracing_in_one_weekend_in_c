#!/bin/bash

num=0;
FILE="result/image$num.ppm"
while true
do
	if ! [ -f "$FILE" ];
	then
		break;
	else
		num=$(($num + 1));
		echo $FILE;
		FILE="result/image$num.ppm";
	fi
done

./ray_tracing > $FILE 2> result/error_log