#!/bin/bash


if [ -z "$1" ]; then

echo "Test Failed: no Parameters"  >&2
exit 1

else
if [ -e /bin/$1 ]; then
echo $?
echo "Test Succeded" >&2
else
echo $?
echo "Test Failed: "

fi
fi
