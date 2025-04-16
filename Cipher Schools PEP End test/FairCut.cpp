//https://www.hackerrank.com/contests/hourrank-12/challenges/fair-cut/problem

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    int a[n];
    for(auto i = 0; cin >> a[i]; i++) {
    }
    sort(a, a + n);
    auto ans = 0ll;
    for(auto i = 0ll, j = n; i < n / 2; i++) {
        if(k > j - k) {
            ans += (a[n - i - 1] - a[i]) * (j - k);
            j -= 2;
            k -= 2;
        } else {
            ans += (a[n - i - 1] - a[i]) * k;
            j -= 2;
        }
    }
    cout << ans;
    return 0;
}   


//Actual Solution and Code given in the Cipher Schools PEP Program
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'fairCut' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int fairCut(int k, vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    long long ans = 0;
    for (long long i = 0, j = n; i < n / 2; i++) {
        if (k > j - k) {
            ans += (arr[n - i - 1] - arr[i]) * (j - k);
            j -= 2;
            k -= 2;
        } else {
            ans += (arr[n - i - 1] - arr[i]) * k;
            j -= 2;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = fairCut(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

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
