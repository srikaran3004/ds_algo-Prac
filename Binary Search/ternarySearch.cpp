#include <bits/stdc++.h>
using namespace std;

int TS(vector<int>& arr, int target){
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while(s <= e){ // = 
        int delta = (e - s) / 3;
        int i = s + (delta);
        int j = e - (delta);
        if(arr[i] == target){
            return i;
        }
        if(arr[j] == target){
            return j;
        }
        if(target < arr[i]){ // look in left prt
            e = i - 1;
        }
        else if(target > arr[j]){
            s = j + 1;
        }
        else{
            i = s + 1;
            j = e - 1;
        }
    }
    return -1;
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int &i: arr){
        cin >> i;
    }
    int target; cin >> target;
    int pos = TS(arr, target);
    cout << pos;
    return 0;
}