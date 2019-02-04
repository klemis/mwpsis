#!/usr/bin/env bash
sed -i 1d output.csv
regex="x\[(.*),1\][[:space:]]+(.*)[[:space:]]"
printf "Specific route:<br><br>"
while read line
do
	[[ $line =~ $regex ]]	
	E_num=${BASH_REMATCH[1]}
	Mbits_value=${BASH_REMATCH[2]}
	printf "Edge : "; grep "^${E_num}:" E_doc.txt ;printf "Throughput : ${Mbits_value} [Mbits]<br><br>"
done < output.csv






