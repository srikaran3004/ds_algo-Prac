
// Problem Description
// George wants to help Lily finish her homework faster, but he's in over his head. Can you help George understand Lily's homework so she can hang out with him?

// You are given an array of n distinct integers, arr[0], arr[1], ..., arr[n-1]. George can swap any two elements of the array any number of times. The array is considered beautiful if the sum of the absolute differences between adjacent elements is minimal.

// Objective: Determine and return the minimum number of swaps required to make the array beautiful.

// An array is beautiful if the sum of the absolute differences between adjacent elements is minimized among all possible permutations of the array.

// Function Description
// Complete the function lilysHomework that takes the following parameter:

// arr (List[int]): an integer array of size n.
// The function must return an integer, which is the minimum number of swaps required to make the array beautiful.

// Input Format
// The first line contains a single integer n, the number of elements in the array arr.
// The second line contains n space-separated integers representing the array arr.
// Constraints:
// 1 <= n <= 10^5
// 1 <= arr[i] <= 10^9
// Sample Input:
// Copy
// Edit
// 5
// 3 4 2 5 1
// Sample Output:
// Copy
// Edit
// 2
// Explanation:
// One of the beautiful arrays is [1, 2, 3, 4, 5], where the sum of absolute differences between adjacent elements is minimized.
// To get there, George performed the following swaps:
// Swap 3 with 1 → [1, 4, 2, 5, 3]
// Swap 4 with 2 → [1, 2, 4, 5, 3]
// Swap 5 with 3 → [1, 2, 3, 4, 5]
// It took 2 swaps to make the array beautiful.

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int lilysHomework(vector<int> arr) {
    int n = arr.size();
    vector<int> sortedArr = arr;
    vector<int> reverseSortedArr = arr;
    
    sort(sortedArr.begin(), sortedArr.end());
    reverse(reverseSortedArr.begin(), reverseSortedArr.end());
    
    auto countSwaps = [&](vector<int>& arrToSort) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < n; i++) {
            indexMap[arrToSort[i]] = i;
        }

        vector<bool> visited(n, false);
        int swapCount = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arrToSort[i] == sortedArr[i]) {
                continue;
            }

            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = indexMap[sortedArr[j]];
                cycleSize++;
            }

            if (cycleSize > 1) {
                swapCount += cycleSize - 1;
            }
        }

        return swapCount;
    };

    int ascSwaps = countSwaps(arr);
    int descSwaps = countSwaps(reverseSortedArr);

    return min(ascSwaps, descSwaps);
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);
        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));

    return tokens;
}
