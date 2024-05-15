#Write a shell script to find factorial of a given number. 

echo "Enter the number:"
read number
factorial=1
for ((i=1;i<=$number;i++))
do 
    factorial=$((factorial*i))
done
echo "Factorial of $number is : $factorial"




