#!/bin/sh
cat $1 | grep -i "nicolas" | grep -i "bomber" | awk '{print $(NF-1)}' | grep "-"
