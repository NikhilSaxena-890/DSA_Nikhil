#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
#include <algorithm> // For max_element()

using namespace std;

bool isPossible(vector<int>& books, int students, int maxPages) {
    int studentCount = 1;
    int pagesSum = 0;

    for (int pages : books) {
        if (pages > maxPages) return false; // If a single book has more pages than maxPages, not possible

        if (pagesSum + pages > maxPages) {
            studentCount++;
            pagesSum = pages;
            if (studentCount > students) return false;
        } else {
            pagesSum += pages;
        }
    }
    return true;
}

int allocatePages(vector<int>& books, int students) {
    if (students > books.size()) return -1; // More students than books, not possible

    int low = *max_element(books.begin(), books.end()); // Min pages should be at least the max book size
    int high = 0; // Sum of all book pages

    for (int pages : books) high += pages;

    int result = high; // Initialize result with the highest possible pages

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(books, students, mid)) {
            result = mid;
            high = mid - 1; // Try for a smaller max pages value
        } else {
            low = mid + 1; // Increase the max pages allowed
        }
    }
    return result;
}

int main() {
    vector<int> books = {12, 34, 67, 90}; // Example book pages
    int students = 2; // Number of students

    cout << "Minimum pages a student has to read: " << allocatePages(books, students) << endl;

    return 0;
}
