# def is_palindrome(n):
#     # Convert number to string and check if it reads the same forwards and backwards
#     return str(n) == str(n)[::-1]

# # Initialize sum variable
# sum_palindromes = 0

# # Iterate through numbers from 100 to 999
# for num in range(100, 1000):
#     if is_palindrome(num):
#         sum_palindromes += num

# # Print the sum of palindrome numbers
# print("Sum of palindrome numbers between 100 and 999:", sum_palindromes)

# Initialize sum variable
sum_palindromes = 0

# Iterate through numbers from 100 to 999
for num in range(100, 1000):
    string1 = str(num)
    string2 = string1[::-1]
    if string1 == string2:
        sum_palindromes += num

# Print the sum of palindrome numbers
print("Sum of palindrome numbers between 100 and 999:", sum_palindromes)
