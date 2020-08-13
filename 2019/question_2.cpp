/* Score: 15/15 */

#include <iostream>
#include <map>

using namespace std;

map<int, int> primes;

bool isPrime(int num) { //checks if number is prime

    if(primes[num] == 1){ //if prime
        return true;
    } else if(primes[num] == 2) { //if not prime
        return false;
    } else { //if we do not know its status
        bool prime = true;

        int divisor = 2;
        if(num%divisor == 0) { //if even
            prime = false;
        } else { //if odd
            divisor = 3;
            while(prime && divisor <= num/2) {
                if(num%divisor == 0) {
                    prime = false;
                }
                divisor += 2;
            }
        }

        //stores result in map for quicker access in the future
        if(prime) {
            primes[num] = 1; //true
        } else {
            primes[num] = 2; //false
        }

        return prime;
    }
}

int main() {
    //gets inputs
    int inputs = 0;
    cin >> inputs;

    int * arr = new int[inputs];

    for(int i = 0; i < inputs; i++) {
        cin >> arr[i];
    }

    int doubled = 0;
    bool found;
    int lowerBound = 0, upperBound = 0;

    for(int i = 0; i < inputs; i++) { //goes through each number in the array
        doubled = arr[i]*2;
        lowerBound = 2; //lower bound of the average
        upperBound = doubled-lowerBound; //upper bound of the average
        found = false;

        while(!found && lowerBound <= arr[i]) { //goes through possible value pairs until a value is found where both bounds are prime
            if(isPrime(lowerBound) && isPrime(upperBound)) { //if both bounds are prime
                cout << lowerBound << " " << upperBound << endl;
                found = true;
            }

            if(lowerBound == 2) {
                upperBound--;
                lowerBound++;
            } else {
                upperBound -= 2;
                lowerBound += 2;
            }
        }
    }
}