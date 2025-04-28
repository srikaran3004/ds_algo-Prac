// Answered!
// 20 marks

// 2. ZIGZAG String
// The string "ZOPSMART" is written in a zigzag pattern on 2 rows like this:

// ZPMR

// OSAT

// The read them line by line: ZPMROSAT



// Input: String of length 'k'

// Output: ZigZag pattern in `n` rows, read line by line where n = smallest number whose cube is lesser than or equal to k.



// Example:

// Input: ZOPSMART

// Output:ZPMROSAT

// Explanation: Input length is 16, so n would be 2. Zigzag pattern as explained above and then read line by line.

// Sample Test Cases

// Input:

// ZOPSMART

// Output:

// ZPMROSAT

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to calculate n
int getRowCount(int length) {
    int n = 1;
    while ((n + 1) * (n + 1) * (n + 1) <= length) {
        n++;
    }
    return n;
}

int main() {
    string input;
    cin >> input;

    int k = input.length();
    int n = getRowCount(k);

    // Create n empty rows
    vector<string> rows(n);
    int currentRow = 0;
    bool goingDown = true; // Initially going downward

    for (char ch : input) {
        rows[currentRow] += ch;
        
        if (n > 1) { // Only if more than 1 row
            if (goingDown) {
                currentRow++;
                if (currentRow == n) { // If we reach last row
                    currentRow = n - 2;
                    goingDown = false;
                }
            } else {
                currentRow--;
                if (currentRow == -1) { // If we reach top
                    currentRow = 1;
                    goingDown = true;
                }
            }
        }
    }

    // Output all rows one after another
    for (const string& row : rows) {
        cout << row;
    }
    cout << endl;

    return 0;
}
