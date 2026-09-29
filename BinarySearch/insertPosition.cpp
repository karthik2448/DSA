#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Returns the index of x if it exists,
    otherwise returns the correct insert position.
    */
    int searchInsertPosition(vector<int>& arr, int x) {
        // Left boundary of the current search range.
        int low = 0;

        // Right boundary of the current search range.
        int high = (int)arr.size() - 1;

        // Starts as arr.size() so it remains correct when x belongs at the end.
        int answer = (int)arr.size();

        // Keep searching while a valid range still exists.
        while (low <= high) {
            // Calculate the middle index safely.
            int mid = low + (high - low) / 2;

            // This position can hold x, so store it and try to find an earlier one.
            if (arr[mid] >= x) {
                answer = mid;
                high = mid - 1;
            } else {
                // Values up to mid are too small, so move to the right half.
                low = mid + 1;
            }
        }

        return answer;
    }
};

// Driver code starts
int main() {
    vector<int> arr = {1, 3, 5, 6};
    int x = 2;

    Solution obj;
    cout << obj.searchInsertPosition(arr, x) << endl;

    return 0;
}