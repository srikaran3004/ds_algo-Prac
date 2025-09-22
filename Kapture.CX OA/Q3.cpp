// Matrix Path - This program finds the minimum path sum from top-left to bottom-right of a grid
#include <iostream>   // For input/output operations
#include <vector>     // For using the vector container
#include <algorithm>  // For using the min function
using namespace std;  // Using standard namespace to avoid std:: prefix

// Function to find minimum path sum from top-left to bottom-right
// The function modifies the input grid to store cumulative path sums
int MinPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();     // Get number of rows in the grid
    int n = grid[0].size();  // Get number of columns in the grid

    // Fill first row by adding previous cell value (only can move right)
    for (int j = 1; j < n; ++j)
        grid[0][j] += grid[0][j - 1];  // Current cell = current value + value to the left
    
    // Fill first column by adding previous cell value (only can move down)
    for (int i = 1; i < m; ++i)
        grid[i][0] += grid[i - 1][0];  // Current cell = current value + value above
    
    // Fill the rest of the matrix using dynamic programming approach
    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            // For each cell, we can either come from above or from the left
            // Choose the minimum of those two paths and add current cell's value
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);

    // Return the bottom-right cell which now contains the minimum path sum
    return grid[m - 1][n - 1];
}

int main()
{
    // Initialize a 3x3 test matrix
    vector<vector<int>> matrix = {
        {1, 3, 1},  // First row: values represent costs
        {1, 5, 1},  // Second row
        {4, 2, 1}   // Third row
    };

    // Call the MinPathSum function and output the result
    cout << MinPathSum(matrix) << endl;  // Output: 7 (path: 1→3→1→1→1)
    return 0;  // Indicate successful program completion
}
