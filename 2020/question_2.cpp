/* Score: 13/15 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Cell { //cell class will represent all of the present cells
public:
    int row;
    int col;

    Cell() {
        row = 0;
        col = 0;
    }

    Cell(int r, int c) {
        row = r;
        col = c;
    }
};

//1000 was chosen because it is the maximum values for M and N (range is 1 to 1000 inclusive)
bool checked[1000][1000]; //keep track if cells have been checked or now
vector<vector<Cell>> vals(1000000); //values of the cells can range from 1 to 1000000. If a cell has a specific value (say 10), it will be stored in the child vector at the tenth element of the parent vector

string possible(Cell prev_cell) {
    queue<Cell> cells;
    cells.push(prev_cell); //adds prev_cell to the end of the queue

    while(cells.size() > 0) {
        Cell tempCell = cells.front();
        cells.pop();
        vector<Cell> jumpPossibilities = vals[tempCell.row * tempCell.col]; //gets vector of all cells that have the correct value

        for(Cell jump: jumpPossibilities) {
            if(jump.row == 1 && jump.col == 1) { //if cell is at the top-left corner, then we have escaped :))
                return "yes"; //returns "yes" and EXITS FUNCTION
            } else if(!checked[jump.row][jump.col]) { //if the cell has not been searched yet... 
                checked[jump.row][jump.col] = true; 
                cells.push(jump); //... we add it to the back of the queue and eventually, as the while loop loops, it will use this cell as a reference to look for paths to escape
            }
        }
    }
    
    return "no"; //if the size of the cells queue becomes zero, it means no escape was possible
}

int main() {

    //gets number of rows and columns
    int rows = 0, columns = 0;
    cin >> rows >> columns;

    Cell prev_cell;

    int input = 0;
    //coordinates start at 1, so the counter starts at 1 as well
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= columns; j++) {
            cin >> input; //value of the cell
            Cell temp(i, j); //creates a cell object
            vals[input].push_back(temp); //adds cell

            if(i == rows && j == columns) {
                prev_cell = temp; //sets the starting cell at bottom right corner
            }
        }
    }

    cout << possible(prev_cell); //calls function to see if there is a possibility for escape
    return 0;
}