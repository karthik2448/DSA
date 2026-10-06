#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    /*
    Checks whether books can be allocated
    without crossing the given page limit.
    */
    bool canAllocate(vector<int>& pages, int students, long long limit) {
        // At least one student is needed when books exist.
        int studentsUsed = 1;

        // This stores pages assigned to the current student.
        long long currentPages = 0;

        for (int bookPages : pages) {
            // Add the book to the current student
            // if the page limit is still safe.
            if (currentPages + bookPages <= limit) {
                currentPages += bookPages;
            } else {
                // Otherwise, start allocation for a new student
                // because the current student would cross the limit.
                studentsUsed++;
                currentPages = bookPages;
            }

            // If too many students are needed,
            // this page limit cannot work.
            if (studentsUsed > students) {
                return false;
            }
        }

        return true;
    }

public:
    /*
    Finds the minimum possible maximum pages
    using binary search on the answer range.
    */
    int findPages(vector<int>& pages, int students) {
        int n = pages.size();

        // Each student must get at least one book.
        if (students > n) {
            return -1;
        }

        // The answer cannot be smaller than the largest book.
        long long low = *max_element(pages.begin(), pages.end());

        // The answer cannot be larger than all pages together.
        long long high = accumulate(pages.begin(), pages.end(), 0LL);

        while (low < high) {
            // mid is the maximum page limit being tested.
            long long mid = low + (high - low) / 2;

            // If mid works, try to find a smaller valid limit.
            if (canAllocate(pages, students, mid)) {
                high = mid;
            } else {
                // If mid fails, every smaller limit also fails.
                low = mid + 1;
            }
        }

        return (int)low;
    }
};

// Driver code starts
int main() {
    vector<int> pages = {12, 34, 67, 90};
    int students = 2;

    Solution obj;
    cout << obj.findPages(pages, students) << endl;

    return 0;
}