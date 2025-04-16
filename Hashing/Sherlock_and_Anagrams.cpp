// Problem Statement:

// Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string. For example, "listen" and "silent" are anagrams of each other.

// Given a string s, find the number of pairs of substrings of the string that are anagrams of each other.

// Function Description
// Complete the function sherlockAndAnagrams:

// cpp
// Copy
// Edit
// int sherlockAndAnagrams(string s);
// Input:

// The first line contains an integer q, the number of queries.
// Each of the next q lines contains a string s to analyze.
// Output:

// For each query, output a single integer: the number of unordered anagrammatic pairs of substrings in s.

// Constraints:
// 1 ≤ q ≤ 100
// 2 ≤ length of s ≤ 100
// s contains only lowercase letters in the range a-z.
// Example 1:
// Input:

// Copy
// Edit
// 2
// abba
// abcd
// Output:

// Copy
// Edit
// 4
// 0
// Explanation:

// For the first query, the list of anagrammatic pairs are:

// [a, a]
// [ab, ba]
// [b, b]
// [abb, bba]
// For the second query, there are no anagrammatic pairs.

// Example 2:
// Input:

// Copy
// Edit
// 2
// ifailuhkqq
// kkkk
// Output:

// Copy
// Edit
// 3
// 10
// Explanation:

// For the first query:
// The anagram pairs are [i, i], [q, q], and [ifa, fai].
// For the second query:
// There are 6 anagrams of the form [k, k] at positions [1, 2], [1, 3], [2, 3], and so on.
// There are 3 anagrams of the form [kk, kk].
// There is 1 anagram of the form [kkk, kkk].
// Example 3:
// Input:

// Copy
// Edit
// 1
// cdcd
// Output:

// Copy
// Edit
// 5
// Explanation:

// There are 2 anagrammatic pairs of length 1: [c, c] and [d, d].
// There are 3 anagrammatic pairs of length 2: [cd, dc], [cd, cd], [dc, cd].

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int sherlockAndAnagrams(string s) {
    int n = s.size();
    unordered_map<string, int> substringCount;
    int anagramPairs = 0;

    // Generate all substrings and sort each to count anagram pairs
    for (int i = 0; i < n; i++) {
        string currentSubstr = "";
        for (int j = i; j < n; j++) {
            currentSubstr += s[j];
            string sortedSubstr = currentSubstr;
            sort(sortedSubstr.begin(), sortedSubstr.end());

            // Count the frequency of sorted substrings
            anagramPairs += substringCount[sortedSubstr];
            substringCount[sortedSubstr]++;
        }
    }

    return anagramPairs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}
