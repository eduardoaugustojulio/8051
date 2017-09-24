#!/bin/bash
	


if [ $# -eq 1 ]; then
	if [[ $1 == *.ihx ]]; then
		packihx $1
	fi	
fi
