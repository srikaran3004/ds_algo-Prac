/*
Problem Statement
Given the ratings of N students, a teacher wants to select two students with the highest sum of ratings to participate in a coding championship. Your task is to write a function that returns the two highest ratings from the list, in decreasing order.

Function Signature
cpp
Copy
Edit
vector<int> solution(int N, vector<int> arr);
Input
An integer N — the number of students.

A vector arr of N integers — representing the rating of each student.

Output
Return a vector containing two integers — the highest and second-highest ratings in decreasing order.

Input Format for Custom Testing
The first line contains the integer N.

The second line contains N space-separated integers representing the array arr.

Output Format
Two integers separated by a space, representing the top two ratings in descending order.

Constraints
2 ≤ N ≤ 10⁶

−10⁹ ≤ arr[i] < 10⁹

Example
Input
Copy
Edit
5
4 10 6 3 8
Output
Copy
Edit
10 8
Explanation
The two highest ratings in the array are 10 and 8. They are returned in decreasing order as required.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    int h = arr[n - 1];
    int sh = arr[n - 2];
    if (h < sh)
        swap(h, sh);
    return {h, sh};
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> result = solve(arr, n);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}