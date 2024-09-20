number = int(input("enter number: "))
divider = 2

while divider < number:
    if number % divider == 0:
        print(f"{number} is not a prime number")
        break
    divider += 1
    if divider == number:
        print(f"{number} is a prime number")

# in the above code divider divide the number until its equal to the number if divider completely divide the number then it is not 
# a prime number else its is a prime number because when number == divider then it will be a prime number cause only the number
# itself 