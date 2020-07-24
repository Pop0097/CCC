# Score: 7/15

# Valid function
def valid(letter_frequency_needle, letter_frequency_haystack):
    for i in range(26):
        letter = chr(ord('a') + i)
        if letter_frequency_needle[letter] != letter_frequency_haystack[letter]:
            return False # EXITS FUNCTION

    return True

# Main function
# Gets inputs
needle = input()
haystack = input()

# Dictionaries for letter frequencies
letter_frequency_needle = {
    "a": 0
}
letter_frequency_haystack = {
    "a": 0
}

for i in range(26):
    letter = chr(ord('a') + i) # Increments characters
    # Initializes the dictonaries
    letter_frequency_needle[letter] = 0
    letter_frequency_haystack[letter] = 0

for i in needle: # Gets each character in the string
    letter_frequency_needle[i] = letter_frequency_needle[i] + 1 # Gets letter frequencies for needle

haystack_substring = ""
validPermutations = 0

already_used = {}

for i in range(len(haystack) - len(needle) + 1):
    haystack_substring = haystack[i:i+len(needle)] # Gets substring
    
    if i == 0:
        for j in haystack_substring:
            letter_frequency_haystack[j] = letter_frequency_haystack[j] + 1 # Gets frequency of letters in substring
    else:
        # Adjusts letter frequencies
        remove = haystack[i - 1]
        add = haystack[i + len(haystack_substring) - 1]
        letter_frequency_haystack[remove] = letter_frequency_haystack[remove] - 1
        letter_frequency_haystack[add] = letter_frequency_haystack[add] + 1

    already_found = hash(haystack_substring) # Converts substring to a hash

    # Sees if hash key is initailized using try and except clause
    try:
        if(already_used[already_found]):
            temp = 0
    except KeyError:
        already_used[already_found] = False

    # Sees if the substring is a unique permutation of the needle
    if not(already_used[already_found]) and valid(letter_frequency_needle, letter_frequency_haystack):
        already_used[already_found] = True
        validPermutations = validPermutations + 1

print(str(validPermutations)) # Answer




