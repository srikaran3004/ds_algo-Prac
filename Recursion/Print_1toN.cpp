#include<bits/stdc++.h>
using namespace std;

void solve(int i,int n){
    if(i>=n){
        return ;
    }
    cout<<i+1<<endl;
    solve(i+1,n);
}

int main(){
    int n;
    cin>>n;
    solve(0,n);
}