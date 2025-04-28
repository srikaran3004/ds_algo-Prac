// Answered!
// 30 marks

// 1. Square Off!
// Rohan likes square numbers, so much so that he wants to convert all characters into a specific pattern.

// For each character, replace it with closest character (as per ASCII table) whose ASCII value is a square number.



// Input: ZOPSMART

// Output: QQQQQ@QQ

// Explanation:

// Here are the ASCII values for each character in "ZOPSMART":

// Z: 90

// O: 79

// P: 80

// S: 83

// M: 77

// A: 65

// R: 82

// T: 84



// Converting to nearest ASCII values which are square numbers: 81 81 81 81 81 64 81 81

// Converting it back to Characters: QQQQQ@QQ

// Sample Test Cases

// Input:

// ZOPSMART

// Output:

// QQQQQ@QQ

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Precompute all perfect squares <= 127
vector<int> precomputeSquares() {
    vector<int> squares;
    for (int i = 0; i * i <= 127; ++i) {
        squares.push_back(i * i);
    }
    return squares;
}

// Find closest square for a given character
char closestSquareChar(char ch, const vector<int>& squares) {
    int ascii = int(ch);
    int closest = squares[0];
    int minDiff = abs(ascii - closest);

    for (int sq : squares) {
        int diff = abs(ascii - sq);
        if (diff < minDiff || (diff == minDiff && sq < closest)) {
            minDiff = diff;
            closest = sq;
        }
    }
    return char(closest);
}

int main() {
    string input;
    cin >> input;

    vector<int> squares = precomputeSquares(); // Precompute once

    for (char ch : input) {
        cout << closestSquareChar(ch, squares);
    }
    cout << endl;

    return 0;
}
