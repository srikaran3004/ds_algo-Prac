//String Reduction
#include <iostream>
#include <string>
using namespace std;

int StringReduction(const string& str) {
    int freq[3] = {0}; // a, b, c

    for (char ch : str) {
        freq[ch - 'a']++;
    }

    // If all same letter → no reduction possible
    if ((freq[0] == 0 && freq[1] == 0) || (freq[0] == 0 && freq[2] == 0) || (freq[1] == 0 && freq[2] == 0)) {
        return str.length();
    }

    // If all counts are even or all are odd → reduce to 2
    if ((freq[0] % 2 == freq[1] % 2) && (freq[1] % 2 == freq[2] % 2))
        return 2;

    // Otherwise → reduce to 1
    return 1;
}

int main() {
    string input;
    cin >> input;
    cout << StringReduction(input) << endl;
    return 0;
}
