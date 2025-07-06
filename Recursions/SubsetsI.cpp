#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findSubsets(int index, vector<int>& array, int N, vector<vector<int>>& sumSubset, vector<int>& ds) {
    if (index == N) {
        sumSubset.push_back(ds);
        return;
    }
    
    // Pick the element
    ds.push_back(array[index]);
    findSubsets(index + 1, array, N, sumSubset, ds);
    
    // Not pick the element (backtrack)
    ds.pop_back();
    findSubsets(index + 1, array, N, sumSubset, ds);
}

vector<vector<int>> subsets(vector<int>& array, int N) {
    vector<vector<int>> sumSubset;
    vector<int> ds;
    findSubsets(0, array, N, sumSubset, ds);
    return sumSubset;
}

int main() {
    // Example input
    vector<int> array = {2, 3, 5};
    int N = array.size();

    // Compute subsets
    vector<vector<int>> result = subsets(array, N);

    // Sort subsets based on size (optional)
    sort(result.begin(), result.end());

    // Print the subsets
    cout << "Subsets are:" << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
