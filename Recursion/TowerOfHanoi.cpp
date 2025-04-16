#include <iostream>
#include <stack>

using namespace std;

void print(stack<int> s1, stack<int> s2, stack<int> s3) {
    stack<int> temp;

    cout << "Stack 1: ";
    temp = s1;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    cout << "Stack 2: ";
    temp = s2;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    cout << "Stack 3: ";
    temp = s3;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    cout << "------------------\n";
}

void hanoi(int n, stack<int>& source, stack<int>& auxiliary, stack<int>& destination) {
    if (n <= 0) return;

    hanoi(n - 1, source, destination, auxiliary);

    destination.push(source.top());
    source.pop();
    print(source, auxiliary, destination);

    hanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    stack<int> s1, s2, s3;

    for (int i = n; i >= 1; i--) {
        s1.push(i);
    }

    cout << "Initial State: \n";
    print(s1, s2, s3);

    hanoi(n, s1, s2, s3);

    cout << "Final State: \n";
    print(s1, s2, s3);

    return 0;
}
