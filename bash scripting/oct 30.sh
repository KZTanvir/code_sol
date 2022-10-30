echo "Enter Number a: "
read a
echo "Enter Number b: "
read b
echo " $a $b "
echo "Before Swapping: a = $a and b = $b"
c=$a
a=$b
b=$c
echo "After Swapping: a = $a and b = $b"

if [ $a -lt $b ]
then
    echo "$a is less than $b"
else
    echo "$a is greater than $b"
fi