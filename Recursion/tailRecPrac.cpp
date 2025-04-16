#include <iostream>
using namespace std;

int countDigits(int n, int count = 0) {
    if (n == 0) {
        return count == 0 ? 1 : count;
    }
    return countDigits(n / 10, count + 1);
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Number of digits: " << countDigits(number) << endl;
    return 0;
}


/** 
int countEvenNumbers(int arr[], int size) {
    if (size == 0) {
        return 0;
    }
    int count = (arr[size - 1] % 2 == 0) ? 1 : 0;
    return count + countEvenNumbers(arr, size - 1);
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Number of digits: " << countDigits(number) << endl;

    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Number of even numbers: " << countEvenNumbers(arr, size) << endl;

    return 0;
}
*/

