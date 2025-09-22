//String Reduction
// This program reduces a string containing only 'a', 'b', and 'c' characters
// using operations where we can replace any two adjacent different characters with the third character
#include <iostream>
#include <string>
using namespace std;

// Function to determine the minimum length possible after reductions
int StringReduction(const string& str) {
    int freq[3] = {0}; // Initialize frequency array for characters 'a', 'b', and 'c'

    // Count frequency of each character in the input string
    for (char ch : str) {
        freq[ch - 'a']++; // Convert char to index: 'a'->0, 'b'->1, 'c'->2
    }

    // If there's only one type of character in the string (two types have zero frequency),
    // then no reduction is possible because we need different adjacent characters
    if ((freq[0] == 0 && freq[1] == 0) || (freq[0] == 0 && freq[2] == 0) || (freq[1] == 0 && freq[2] == 0)) {
        return str.length(); // Return original length as no reduction can be performed
    }

    // Mathematical property: If all counts have the same parity (all even or all odd),
    // the string can be reduced to length 2
    // This is a proven property in string reduction problems with these operations
    if ((freq[0] % 2 == freq[1] % 2) && (freq[1] % 2 == freq[2] % 2))
        return 2;

    // Otherwise (if parities are different), the string can always be reduced to length 1
    // This also follows from mathematical properties of these reduction operations
    return 1;
}

int main() {
    string input; // Declare a string to store user input
    cin >> input; // Read the input string
    cout << StringReduction(input) << endl; // Call the function and output the result
    return 0; // End program with success code
}
