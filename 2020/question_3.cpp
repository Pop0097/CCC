/* Score: 15/15 */

#include <iostream>
#include <map> //basically like a dictionary in Python (use a key to access a value)
#include <string>

using namespace std;

bool valid(map<char, int> map1, map<char, int> map2) {
    
    for(int i = 0 ; i < 26 ; i++) {
        char letter = 'a' + i; //the "i" increments the ASCII value which in turn moves through the alphabet
        if(map1[letter] != map2[letter]) { //if the counters do not match
            return false; //FUNCTOIN ENDS to save iteration and runtime
        }
    }
    
    return true; //if all counter values are the same, then true is returned
}

int main() {
    string needle = "", haystack = "";
    cin >> needle >> haystack;

    map<char, int> letterFrequency_n, letterFrequency_h; //maps how many times each letter appears in the needle "n" and haystack "h" when searching through the string/substrings

    for(int i = 0 ; i < needle.size() ; i++) {
        //needle[i] outputs a character
        letterFrequency_n[needle[i]]++; //stores the frequency of each letter in the needle 
    }

    string haystackSubstring = "";
    int validPermutations = 0;
    map<size_t, bool> alreadyUsed; //stores all of the permutations that have already been observed

    for(int i = 0 ; i < haystack.size() - needle.size() + 1 ; i++ ) {
        haystackSubstring = haystack.substr(i, needle.size()); //gets a substring in the haystack the size of the needle 
        if(i == 0) {
            for(int j = 0 ; j < haystackSubstring.size() ; j++) {
                letterFrequency_h[haystackSubstring[j]]++; //stores the frequency of each character in the substring
            }
        } else {
            char remove = haystack[i - 1], add = haystack[i + haystackSubstring.size() - 1]; //instead of running another for loop, when we move one letter to the right, we can remove the first letter in haystackSubstring and add a new one to the end (this reduces queries)
            letterFrequency_h[remove]--; //reduce the count for the removed character
            letterFrequency_h[add]++; //increase the count of the added character
        }

        hash<string> alreadyFound; //stores the permutation that we identified as an integer (saves memory)
        size_t permutation = alreadyFound(haystackSubstring); //stores the substring as a size_t datatype by hashing it (hashes store values as size_t)
        
        if(!alreadyUsed[permutation] && valid(letterFrequency_n, letterFrequency_h)) {
            alreadyUsed[permutation] = true; //sets the already used value to true if it is valid
            validPermutations++; //increases count for valid permutations
        }
        
    }

    cout << validPermutations; //answer
    return 0;
}
