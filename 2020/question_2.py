# Score: 11/15

class Cell:
    def __init__(self, r, c): # Default constructor
        self.row = r # Variables are public by default
        self.col = c

checked = [[False for i in range(1000)] for j in range(1000)] # 2D array with values as False
values = [[] for i in range(1000000)] # 2D array with all of the cells

# Possible Function
def possible(prev_cell):
    queue = [] # Initialize a queue
    queue.append(prev_cell) # Adds previous element to the queue

    while len(queue) > 0:
        temp_cell = queue[0] # Gets value of first element in the queue
        queue.pop(0) # Removes first element in queue at specified location
        jump_possibilities = values[temp_cell.row * temp_cell.col] # Array of all cells that can be jumped to

        for cell in jump_possibilities:
            if cell.row == 1 and cell.col == 1: # If in top left corner, then exit is possible
                return "yes" # END FUNCTION
            elif not(checked[cell.row][cell.col]): # If we have not searched the cell before
                checked[cell.row][cell.col] = True
                queue.append(cell) # Add cell to queue

    return "no" # If no escape is found

# Main function
rows = int(input())
cols = int(input())

prev_cell = Cell(0, 0)

for i in range(1, rows + 1):
    numbers = list(map(int, input().split())) # Makes an array of integer inputs
    for j in range(1, cols + 1):
        temp = Cell(i, j)
        values[numbers[j - 1]].append(temp)

        if i == rows and j == cols:
            prev_cell = temp

print(possible(prev_cell)) # answer

