#include <iostream>
using namespace std;

void printSS(int tmp[], int c, int idx, int arr[], int N) {
    if (idx == N) {
        for (int j = 0; j < c; j++) {
            cout << tmp[j] << " ";
        }
        cout << endl;
        return;
    }

    // Include the current element
    tmp[c] = arr[idx];
    printSS(tmp, c + 1, idx + 1, arr, N);
  
    // Exclude the current element
    printSS(tmp, c, idx + 1, arr, N);
}

int main() {
    int arr[] = {1, 2, 3};  
    int N = sizeof(arr) / sizeof(arr[0]);
    int tmp[N];  

    printSS(tmp, 0, 0, arr, N); 

    return 0;
}

