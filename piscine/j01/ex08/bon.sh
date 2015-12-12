#!/bin/sh
ldapsearch -Q sn | grep sn: | grep -i BON | wc -l | tr -d ' '
