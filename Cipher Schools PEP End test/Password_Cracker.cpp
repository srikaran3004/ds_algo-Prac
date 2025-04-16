//https://www.hackerrank.com/challenges/password-cracker/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

void alterVector(vector<string> &a, unordered_set<string> &b) {
    int c = a.size();
    for (int d = 0; d != c; d++) {
        reverse(a[d].begin(), a[d].end());
        b.insert(a[d]);
    }
}

vector<string> processString(const string &a, vector<string> &b) {
    vector<string> c;
    int d = a.size();
    
    unordered_set<string> e;
    alterVector(b, e);
    
    vector<char> f(d + 1, 0);
    f[0] = 1;
    vector<int> g(d + 1);
    
    for (int h = 1; h <= d; h++) {
        int i = h - 1;
        string j;
        for (int k = i; k >= 0; k--) {
            j += a[k];
            if (f[k] && e.find(j) != e.end()) {
                f[h] = 1;
                g[h] = h - k;
                break;
            }
        }
    }
    
    if (f[d] == 0) { return c; }
    
    int h = d;
    while (h) {
        c.push_back(a.substr(h - g[h], g[h]));
        h -= g[h];
    }
    
    reverse(c.begin(), c.end());
    return c;
}

int main() {
    int a, b;
    string c, d;
    cin >> a;
    while (a--) {
        cin >> b;
        vector<string> e;
        while (b--) {
            cin >> c;
            e.push_back(c);
        }
        
        cin >> d;
        
        vector<string> f(processString(d, e));
        if (f.empty()) { cout << "WRONG PASSWORD"; }
        else {
            int g = f.size();
            cout << f[0];
            for (int h = 1; h != g; h++) {
                cout << " " << f[h];
            }
        }
        
        cout << endl;
    }
    
    return 0;
}