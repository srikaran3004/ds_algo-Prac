#include <bits/stdc++.h>
using namespace std;

// Function to print the current state of the board
void print(int **arr, int n) {
    cout << "way ------------------\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "-----------------------------------\n";
}

// Helper function to solve the Knight's Tour using backtracking
void knightHelper(int **arr, int r, int c, int move, int n) {
    // Check if the current position is out of bounds or already visited
    if (r < 0 || c < 0 || r >= n || c >= n || arr[r][c] > 0) {
        return;
    }
    
    // If all squares have been visited, print the board
    if (move == (n * n)) {
        arr[r][c] = move;
        print(arr, n);
        arr[r][c] = -1; // Backtrack
        return;
    }

    // Mark the current square with the move number
    arr[r][c] = move;

    // Recursively call for all 8 possible knight moves
    knightHelper(arr, r - 2, c + 1, move + 1, n);
    knightHelper(arr, r - 1, c + 2, move + 1, n);
    knightHelper(arr, r + 1, c + 2, move + 1, n);
    knightHelper(arr, r + 2, c + 1, move + 1, n);
    knightHelper(arr, r + 2, c - 1, move + 1, n);
    knightHelper(arr, r + 1, c - 2, move + 1, n);
    knightHelper(arr, r - 1, c - 2, move + 1, n);
    knightHelper(arr, r - 2, c - 1, move + 1, n);

    // Backtrack by resetting the current position
    arr[r][c] = -1;
}

int main() {
    int n;
    cin >> n;  // Size of the board
    int r, c;
    cin >> r >> c;  // Starting position of the knight (0-based index)
    
    // Create a 2D array to store the board
    int **arr = new int *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = -1;  // Initialize all squares as unvisited
        }
    }

    // Start the knight's tour from the given position
    knightHelper(arr, r, c, 1, n);  // Here 1 represents the first move (one-based indexing)
    
    // Clean up the dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}
