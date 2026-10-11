#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Returns the median value
    of the row-wise sorted matrix.
    */
    int median(vector<vector<int>>& mat) {
        int rows = (int)mat.size();
        int cols = (int)mat[0].size();

        // These store the smallest and largest possible median values.
        int low = mat[0][0];
        int high = mat[0][cols - 1];

        for (int i = 1; i < rows; i++) {
            // The first element of a sorted row can improve the global minimum.
            low = min(low, mat[i][0]);

            // The last element of a sorted row can improve the global maximum.
            high = max(high, mat[i][cols - 1]);
        }

        // This is how many elements may stay before the median.
        int required = (rows * cols) / 2;

        while (low < high) {
            // This is the current guessed median value.
            int mid = low + (high - low) / 2;
            int count = 0;

            for (int i = 0; i < rows; i++) {
                // Count how many values in this row are less than or equal to mid.
                count += (int)(upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin());
            }

            // Move right because too few elements are still less than or equal to mid.
            if (count <= required) {
                low = mid + 1;
            } else {
                // Keep mid in the answer range because it may already be the median.
                high = mid;
            }
        }

        return low;
    }
};

// Driver code starts
int main() {
    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    Solution obj;
    cout << obj.median(mat) << endl;

    return 0;
}