#!/bin/sh
cat /etc/passwd | sed '/#/d' | sed -n 'n;p' | rev | cut -d : -f 7 | sort -r | awk 'NR >= ENVIRON["FT_LINE1"] && NR <= ENVIRON["FT_LINE2"]' | tr '\n' ' ' | sed 's/ /, /g' | sed 's/\(.*\),/\1./'
