def swap_without_temp_variable(a, b):
    print(f"Before Swapping: a = {a}, b = {b}")
    
    # Swap values without using a temporary variable
    a = a + b  # Add both numbers and store result in a
    b = a - b  # Subtract b from the new value of a to get the original value of a and store it in b
    a = a - b  # Subtract the new value of b from the new value of a to get the original value of b and store it in a
    
    print(f"After Swapping: a = {a}, b = {b}")

a = 5
b = 10
swap_without_temp_variable(a, b)