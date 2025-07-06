#include<iostream>
#include<vector>
using namespace std;

void solve(int row, int col, vector<vector<int>> &maze, int n, vector<string> &ans, string move, vector<vector<int>> &visited) {
    if (row == n - 1 && col == n - 1) {
        ans.push_back(move);
        return;
    }
    
    // Mark the cell as visited
    visited[row][col] = 1;
    
    // Down
    if (row + 1 < n && !visited[row + 1][col] && maze[row + 1][col] == 1) {
        solve(row + 1, col, maze, n, ans, move + "D", visited);
    }
    
    // Right
    if (col + 1 < n && !visited[row][col + 1] && maze[row][col + 1] == 1) {
        solve(row, col + 1, maze, n, ans, move + "R", visited);
    }
    
    // Up
    if (row - 1 >= 0 && !visited[row - 1][col] && maze[row - 1][col] == 1) {
        solve(row - 1, col, maze, n, ans, move + "U", visited);
    }
    
    // Left
    if (col - 1 >= 0 && !visited[row][col - 1] && maze[row][col - 1] == 1) {
        solve(row, col - 1, maze, n, ans, move + "L", visited);
    }
    
    // Unmark the cell for backtracking
    visited[row][col] = 0;
}

vector<string> findPath(vector<vector<int>> &maze, int n) {
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    if (maze[0][0] == 1) solve(0, 0, maze, n, ans, "", visited);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    
    vector<string> result = findPath(maze, n);
    if (result.empty()) {
        cout << "No path found" << endl;
    } else {
        cout << "Paths: " << endl;
        for (const string &path : result) {
            cout << path << endl;
        }
    }
    
    return 0;
}