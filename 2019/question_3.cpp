#include <iostream>
#include <string>

using namespace std;

string table[3][3];
bool rowsSorted[3] = {false, false, false};
bool colsSorted[3] = {false, false, false};

void sortRows() {
    int numX = 0, undefinedIndex = 0, average = 0;

    for(int i = 0; i < 3; i++) { //sorts rows
        for(int j = 0; j < 3; j++) {
            if(table[i][j] == "X") {
                numX++;
                undefinedIndex = j;
            } else {
                average += stoi(table[i][j]);
            }
        }

        if(numX == 1) {
            average /= 2;
            table[i][undefinedIndex] = to_string(average);
            rowsSorted[i] = true;
        }
        numX = 0;
        average = 0;
    }
}

void sortColumns() {
    int numX = 0, undefined = 0, average = 0, lowest = 1000001, d = 0;

    for(int j = 0; j < 3; j++) { //sorts columns
        for(int i = 0; i < 3; i++) {
            if(table[i][j] == "X") {
                numX++;
                undefined = j;
            } else {
                average += stoi(table[i][j]);
                if(stoi(table[i][j]) < lowest) {
                    lowest = stoi(table[i][j]);
                }
            }
        }

        if(numX == 1) {
            average /= 2;
            table[undefined][j] = to_string(average);
            colsSorted[j] = true;
        }
        numX = 0;
    }
}

int main() {
    //gets input
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> table[i][j];
        }
    }

    sortRows();
    sortColumns();

    //Prints Answer
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}