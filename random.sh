#!/bin/bash

count_even=0
count_odd=0
count_prime=0

echo "Enter 25 numbers:"

for (( i=1; i<=25; i++ ))
do
    read -p "Number $i: " num

    # Check if number is even
    if (( num % 2 == 0 ))
    then
        even[$count_even]=$num
        ((count_even++))
    # Check if number is odd
    else
        odd[$count_odd]=$num
        ((count_odd++))
    fi

    # Check if number is prime
    is_prime=1
    if (( num <= 1 ))
    then
        is_prime=0
    else
        for (( j=2; j<=num/2; j++ ))
        do
            if (( num % j == 0 ))
            then
                is_prime=0
                break
            fi
        done
    fi

    if (( is_prime == 1 ))
    then
        prime[$count_prime]=$num
        ((count_prime++))
    fi
done

echo "Even numbers:"
for (( i=0; i<5; i++ ))
do
    echo "${even[$i]}"
done

echo "Odd numbers:"
for (( i=0; i<5; i++ ))
do
    echo "${odd[$i]}"
done

echo "Prime numbers:"
for (( i=0; i<5; i++ ))
do
    echo "${prime[$i]}"
done