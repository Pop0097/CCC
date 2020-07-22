/* Score = 15/15 */

#include <iostream>
#include <algorithm>

int comparision(const void * p, const void * q) {

    //gets values at the given addresses (p and q) and casts them to integers
    int const *lhs = static_cast<int const*>(p);
    int const *rhs = static_cast<int const*>(q);

    return (lhs[0] < rhs[0]) ? -1 //if left side is smaller than right, return -1
            : ((rhs[0] < lhs[0]) ? 1 : 0); //if right side is larger than left, return 1. If none of conditions met, return 0.
}

int main() {

    int inputs = 0;
    std::cin >> inputs; //number of measurements that will be inputed

    int measurements[inputs][2]; //stores all measurements

    for(int row = 0; row < inputs; row++) {
        for(int col = 0; col < 2; col++) {
            std::cin >> measurements[row][col]; //gets inputs for measurements
        }
    }

    //uses qsort to sort the array
    std::qsort(measurements, inputs, sizeof(*measurements), comparision /*Passes two values*/);

    /* // Used for debugging to test if array is sorted
    for(int row = 0; row < inputs; row++) {
        for(int col = 0; col < 2; col++) {
            std::cout << measurements[row][col] << ", "; //gets inputs for measurements
        }
        std::cout << std::endl;
    }
     */


    float maxSpeed = 0, speed = 0, displacement = 0, time = 0;
    for(int i = 1; i < inputs; i++) {
        time = abs(measurements[i][0] - measurements[i-1][0]);
        displacement = abs(measurements[i][1] - measurements[i-1][1]);
        speed = (float) displacement/time*1.0;
        if(speed > maxSpeed) {
            maxSpeed = speed;
        }
    }

    std::cout << maxSpeed;

    return 0;
}
