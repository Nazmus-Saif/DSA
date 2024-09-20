def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

# Create an array with numbers from 1 to 1000
numbers = list(range(1, 1001))

# Find and print all prime numbers in the array
prime_numbers = [num for num in numbers if is_prime(num)]

print("Prime numbers from 1 to 1000 are:")
print(prime_numbers)



""" Factor Finding: When you want to find all factors of a number 𝑛𝑢𝑚 num, you need to check divisibility starting 
from 1 up to 𝑛𝑢𝑚 num. However, you can optimize this process by recognizing that for any pair of factors (𝑎,𝑏)
(a,b), one factor will always be less than or equal to 𝑛𝑢𝑚 num​.

Prime Checking: To check if a number 𝑛𝑢𝑚 is prime, you need to verify that it has no divisors other than 1 and itself. 
Instead of checking all numbers up to 𝑛𝑢m (which would be inefficient), you only need to check up to 𝑛𝑢𝑚 num​. """