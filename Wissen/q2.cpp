/*
Problem Statement

You are given:

An integer amount representing the target change you want to make.

A set of coins, where each coin type has:

a denomination (value)

a limited quantity (how many such coins are available).

Write a program in C++ to determine whether it is possible to make the exact amount using the given coins.
If possible, print one valid combination of coins (denomination → count).
If no solution exists, print "No solution".
*/

#include <bits/stdc++.h>
using namespace std;

bool solve(int idx, int amount, vector<pair<int, int>> &coins, map<int, int> &res)
{
    if (amount == 0)
        return true; // exact match
    if (idx == coins.size())
        return false; // no more coins

    int coin = coins[idx].first;
    int count = coins[idx].second;

    // Try using from 0 up to count coins of this denomination
    for (int use = min(amount / coin, count); use >= 0; --use)
    {
        if (use > 0)
            res[coin] = use;
        if (solve(idx + 1, amount - use * coin, coins, res))
            return true;
        if (use > 0)
            res.erase(coin); // backtrack
    }
    return false;
}

int main()
{
    // Example input: {10:2, 5:1}
    map<int, int> inputCoins = {{10, 2}, {5, 1}};
    int amount = 15;

    // Convert map -> vector for easier indexing
    vector<pair<int, int>> coins(inputCoins.begin(), inputCoins.end());
    sort(coins.rbegin(), coins.rend()); // sort descending for efficiency

    map<int, int> result;
    if (solve(0, amount, coins, result))
    {
        for (auto &p : result)
            cout << p.first << ":" << p.second << " ";
        cout << endl;
    }
    else
    {
        cout << "No solution\n";
    }
}
