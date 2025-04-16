#include <bits/stdc++.h>
using namespace std;

void doHeapify(vector<int>& arr, int n, int i) {
    int index = i;
    int lc = (2 * i) + 1;
    int rc = (2 * i) + 2;
    if (lc < n and arr[index] < arr[lc]) {
        index = lc;
    }
    if (rc < n and arr[index] < arr[rc]) {
        index = rc;
    }
    if (i == index) {
        return;
    }
    swap(arr[i], arr[index]);
    doHeapify(arr, n, index); //
}

void heapSort(vector<int>& arr, int n) {
    for (int i = ((n / 2) - 1); i >= 0; i--) { // plz verify why strictly ...-1
        // try to do heapify
        doHeapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        doHeapify(arr, i, 0); // shold know why and why not
    }
}

void print(vector<int> arr) {
    cout << "Array = " << endl;
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) {
        cin >> i;
    }
    heapSort(arr, n);
    print(arr);
    return 0;
}