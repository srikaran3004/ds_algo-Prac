// Matrix Path
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MinPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // Fill first row and column
    for (int j = 1; j < n; ++j)
        grid[0][j] += grid[0][j - 1];
    for (int i = 1; i < m; ++i)
        grid[i][0] += grid[i - 1][0];

    // Fill the rest of the matrix
    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);

    return grid[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    cout << MinPathSum(matrix) << endl; // Output: 7
    return 0;
}
