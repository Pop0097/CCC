# Score: 6/15

# dictionary containing all numbers and their status as prime (true) or not prime (false)
primes = {}

def isPrime(num): # checks if the number is a prime number
    try: # checks dictionary to see if number already exists
        if primes[num]: # if prime
            return True
        else: # if not prime
            return False
    except KeyError: # if number not in dictionary
        prime = True
        divisor = 2

        if num%divisor == 0 and num != 2: # checks if even
            prime = False

        divisor = 3
        # checks all possible odd divisors
        while prime and divisor <= num/2 and num != 2:
            if num%divisor == 0:
                prime = False

            divisor = divisor+2

        # sets number in dictionary
        if prime:
            primes[num] = True
        else:
            primes[num] = False

        return prime

# gets input
input_number = int(input())
inputs = [0 for i in range(input_number)]

for i in range(input_number):
    inputs[i] = int(input())

# Finds responses
for i in inputs:
    doubled = i*2
    lower_bound = 2
    upper_bound = doubled-lower_bound
    found = False

    while not(found) and lower_bound <= i:
        if isPrime(lower_bound) and isPrime(upper_bound):
            print(str(lower_bound) + " " + str(upper_bound)) # prints answer if both bounds are prime numbers
            found = True

        if lower_bound == 2:
            lower_bound = lower_bound + 1
            upper_bound = upper_bound - 1
        else:
            lower_bound = lower_bound + 2
            upper_bound = upper_bound - 2


