#! /bin/bash
integer=1
: '
if [ $integer -eq 20 ]
then
    echo "integer is equal to 10"
else
    echo "integer is not equal to 10"
fi
'
while [ $integer -lt 10 ]
do
    echo " This is text test."
    integer=$(( integer+1 ))
done