#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findSubsets(int index, vector<int>& array, vector<vector<int>>& sumSubset, vector<int>& ds) {
    sumSubset.push_back(ds); // Store the current subset
    
    for (int i = index; i < array.size(); i++) {
        // Skip duplicate elements to avoid duplicate subsets
        if (i > index && array[i] == array[i - 1]) continue;
        
        // Pick the element
        ds.push_back(array[i]);
        findSubsets(i + 1, array, sumSubset, ds);
        
        // Backtrack (remove the last picked element)
        ds.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& array) {
    vector<vector<int>> sumSubset;
    vector<int> ds;
    
    // Sort the array to handle duplicates
    sort(array.begin(), array.end());
    
    findSubsets(0, array, sumSubset, ds);
    return sumSubset;
}

int main() {
    // Example input
    vector<int> array = {1, 2, 2};
    
    // Compute subsets
    vector<vector<int>> result = subsets(array);

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
