#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findSubsets(int index, int sum, vector<int>& array, int N, vector<int>& sumSubset) {
    if (index == N) {
        sumSubset.push_back(sum);
        return;
    }

    findSubsets(index + 1, sum + array[index], array, N, sumSubset); // Pick
    findSubsets(index + 1, sum, array, N, sumSubset); // Not Pick
}

vector<int> subsets(vector<int>& array, int N) {
    vector<int> sumSubset;
    findSubsets(0, 0, array, N, sumSubset);
    return sumSubset;
}

int main() {
    // Example input
    vector<int> array = {2, 3, 5};
    int N = array.size();

    // Compute subset sums
    vector<int> result = subsets(array, N);

    // Sort the result for better readability
    sort(result.begin(), result.end());

    // Print the subset sums
    cout << "Subset sums are: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
