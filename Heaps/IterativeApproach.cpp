#include <bits/stdc++.h>
using namespace std;

void iterativeHeapify(vector<int>& arr, int n, int i) {
    while (true) {
        int index = i;
        int lc = (2 * i) + 1;
        int rc = (2 * i) + 2;

        if (lc < n && arr[index] < arr[lc]) {
            index = lc;
        }
        if (rc < n && arr[index] < arr[rc]) {
            index = rc;
        }

        if (i == index) {
            break; // No swap needed, heap property satisfied at this level
        }

        swap(arr[i], arr[index]);
        i = index; // Move down to the swapped index and continue heapifying
    }
}

void heapSort(vector<int>& arr, int n) {
    for (int i = ((n / 2) - 1); i >= 0; i--) {
        iterativeHeapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        iterativeHeapify(arr, i, 0);
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