#Write a shell script for implementation of control flow statements. 


echo "Enter your age:"
read age 

if [ $age -lt 18 ]; then 
    echo "You are minor"
elif [ $age -ge 18 ] && [ $age -lt 55 ]; then
    echo "You are Adult"
else
    echo "You are old age"
fi 


echo "number using for loop."
for i in {1..10}; do
    echo $i
done

echo "number using while loop"
count=0
while [ $count -lt 10 ]; do 
    echo $count
    ((count++))
done 

#!/bin/bash

# Function to check if a number is even or odd
check_even_odd() {
    num=$1
    if [ $((num % 2)) -eq 0 ]; then
        echo "$num is even"
    else
        echo "$num is odd"
    fi
}

# Function to print numbers from 1 to n using a for loop
print_numbers() {
    n=$1
    echo "Numbers from 1 to $n:"
    for (( i=1; i<=n; i++ )); do
        echo -n "$i "
    done
    echo ""
}

# Function to print even numbers from 1 to n using a while loop
print_even_numbers() {
    n=$1
    echo "Even numbers from 1 to $n:"
    i=1
    while [ $i -le $n ]; do
        if [ $((i % 2)) -eq 0 ]; then
            echo -n "$i "
        fi
        ((i++))
    done
    echo ""
}

# Function to perform different operations based on user input using a case statement
perform_operation() {
    echo "Enter an operation (add/sub/mul/div):"
    read operation
    echo "Enter two numbers:"
    read num1
    read num2

    case $operation in
        "add")
            result=$((num1 + num2))
            echo "Result of addition: $result"
            ;;
        "sub")
            result=$((num1 - num2))
            echo "Result of subtraction: $result"
            ;;
        "mul")
            result=$((num1 * num2))
            echo "Result of multiplication: $result"
            ;;
        "div")
            if [ $num2 -ne 0 ]; then
                result=$((num1 / num2))
                echo "Result of division: $result"
            else
                echo "Error: Division by zero"
            fi
            ;;
        *)
            echo "Invalid operation"
            ;;
    esac
}

# Main script
while true; do
    echo "1. Check if a number is even or odd"
    echo "2. Print numbers from 1 to n"
    echo "3. Print even numbers from 1 to n"
    echo "4. Perform arithmetic operations"
    echo "0. Exit"

    read choice

    case $choice in
        1)
            echo "Enter a number:"
            read num
            check_even_odd $num
            ;;
        2)
            echo "Enter a number:"
            read n
            print_numbers $n
            ;;
        3)
            echo "Enter a number:"
            read n
            print_even_numbers $n
            ;;
        4)
            perform_operation
            ;;
        0)
            echo "Exiting the program..."
            exit 0
            ;;
        *)
            echo "Invalid choice"
            ;;
    esac
done