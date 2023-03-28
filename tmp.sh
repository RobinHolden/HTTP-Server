#!/bin/sh

total=0
good=0

rm tmp.out
for test in tests/testFile/*; do
	if [ -f "$test" ]; then
		./http-server $test >> ./tmp.out 2>&1
		if [ "$?" -eq 1 ]; then
			good=$(($good+1))
		else
			echo "$test    Not Valid"
		fi
		total=$(($total+1))
	fi
done

echo "End: $good/$total positive tests."
