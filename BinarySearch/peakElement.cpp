#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Returns the index of
    any valid peak element.
    */
    int findPeakElement(vector<int>& nums) {
        // Left boundary of the current search range.
        int low = 0;

        // Right boundary of the current search range.
        int high = (int)nums.size() - 1;

        // Keep shrinking the search range until one peak position remains.
        while (low < high) {
            // Calculate the middle index safely.
            int mid = low + (high - low) / 2;

            // A rising slope means some peak must exist on the right side.
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else {
                // A falling slope means mid or the left side contains a peak.
                high = mid;
            }
        }

        return low;
    }
};

// Driver code starts
int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

    Solution obj;
    cout << obj.findPeakElement(nums) << endl;

    return 0;
}