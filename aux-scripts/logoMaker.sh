#!/bin/sh

name0=${1%.*}
name1=${1##*.}

if [ "$name1" != "png" ]; then
	echo "input file mast be png"
	exit -1
fi

pngtopnm $1 > "$name0.pnm"
pnmquant 224 "$name0.pnm" > "${name0}_clut224.pnm"
pnmtoplainpnm "${name0}_clut224.pnm" > "${name0}_clut224.ppm"


rm "$name0.pnm" "${name0}_clut224.pnm"
