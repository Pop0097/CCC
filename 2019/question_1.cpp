/* Score: 15/15 */

#include <iostream>
#include <string.h>

using namespace std;

int main() {
    string input = "";
    cin >> input;

    int nums[2][2] = {{1, 2}, {3, 4}};
    int temp[2][2] = {{1, 2}, {3, 4}};

    for(int i = 0; i < input.length(); i++) {
        if (input.at(i) == 'V') { //reflection across y axis
            nums[0][0] = temp[0][1];
            nums[0][1] = temp[0][0];
            nums[1][0] = temp[1][1];
            nums[1][1] = temp[1][0];
        } else { //reflection across x axis
            nums[0][0] = temp[1][0];
            nums[0][1] = temp[1][1];
            nums[1][0] = temp[0][0];
            nums[1][1] = temp[0][1];
        }
        memcpy(temp, nums, sizeof(temp)); //copies nums to temp
    }

    //prints answer
    for(int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}