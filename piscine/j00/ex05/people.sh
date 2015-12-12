#!/bin/sh
ldapsearch -Q uid="z*" cn | grep cn: | sort -r | sed "s/cn: //g"
