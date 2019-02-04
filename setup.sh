#!/bin/bash

SRC=${1?Error: no name given}
DST=${2?Error: no name given}
MBITS=${3?Error: no name given}

DIR=/home/camel/MwPSiS-Projekt-master

cd "$DIR"

echo "Collected values :<br><br>"
echo "Source: $(($SRC))   Target: $(($DST))   Demand in mbps: $(($MBITS))<br><br>"

cp project_default.mod project.mod
echo -e "param : h  s t :=\n 1       $MBITS  $SRC  $DST\n;\n\nend;" >> project.mod 

start=$(($(date +%s%N)/1000000));
cbc project.mod% solve solution output.csv | grep -i "objective value" | sed 's/Optimal - objective value /Cost: /' | cut -f1 -d "." | tr '\n' 'Y' | sed 's/Y/\<br\>/g'
end=$(($(date +%s%N)/1000000)); 

echo "Execution time: "$(((end-start)/1000))"s<br><br>"

./map_csv.sh

rm project.mod
