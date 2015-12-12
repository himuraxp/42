#!/bin/sh
if [ ifconfig == "" ]
then
	echo "Je suis perdu!\n"
else
	ifconfig | grep "inet " | cut -d " " -f 2
fi
