#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int UpperBound(vector<int>& arr, int target, int n) {
    int low = 0, high = n - 1, ans = n, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>>& matrix, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += UpperBound(matrix[i], x, n);
    }
    return cnt;
}

int median(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int low = INT_MAX, high = INT_MIN;

    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (m * n) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter matrix elements (row-wise sorted):" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    cout << "Median of the matrix: " << median(matrix) << endl;

    return 0;
}