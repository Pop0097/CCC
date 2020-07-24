# Score: 15/15

def partition(arr, low, high): # Partition function
    i = low-1 # Index of smaller element
    pivot = arr[high][0] # Pivot which will be moved to the correct spot

    for j in range(low, high):
        if arr[j][0] <= pivot: # If the value is smaller than the pivot
            i = i+1 # Increments index of smaller element
            arr[i],arr[j] = arr[j],arr[i] # Switches elements

    arr[i + 1], arr[high] = arr[high], arr[i + 1] # Switches elements
    return (i + 1)

def quickSort(arr, low, high): # Quick sort function
    if low < high:
        partitionIndex = partition(arr, low, high) # Partition index

        # Continues sorting
        quickSort(arr, low, partitionIndex-1)
        quickSort(arr, partitionIndex+1, high)


input_amount = int(input()) # Number of inputs provided

# 2D arrays are initialized like this: [[number of elements with value x] number of rows of that array]
inputs = [[0 for i in range(2)] for j in range(input_amount)] # Defines a 2D array initialized with 0s

for row in range(input_amount):
    # Python does not separate inputs with a space like C++, you have to take input as a string and split it
    inputs[row][0], inputs[row][1] = map(int, input().split()) # Takes in inputs one at a time and then splits them by the space and stores them as integers

# Sort array in ascending order by time
len = len(inputs)
quickSort(inputs, 0, len-1) # Calls function to quick sort

maxSpeed = 0
speed = 0
displacement = 0
time = 0

for i in range(1, input_amount):
    time = abs(inputs[i][0] - inputs[i-1][0])
    displacement = abs(inputs[i][1] - inputs[i - 1][1])
    speed = displacement/time # calculates speed

    if speed > maxSpeed: # if speed beats max speed
        maxSpeed = speed

print(str(maxSpeed)) # answer
