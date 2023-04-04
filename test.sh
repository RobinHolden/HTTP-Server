#!/bin/sh

total=0
good=0

rm -f tmp.out
for test in fuzzer/testFile/*; do
	if [ -f "$test" ]; then
		./http-server $test >/dev/null 2>&1
		if [ "$?" -eq 1 ]; then
			good=$(($good+1))
		else
			echo "$test    Not Valid"
		fi
		total=$(($total+1))
	fi
done

echo "End: $good/$total positive tests."
