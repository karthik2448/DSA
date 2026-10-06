#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Checks if all cows can be placed while keeping
    at least distance gap between every pair.
    */
    bool canPlace(vector<int>& stalls, int k, int distance) {
        // The first cow is placed at the first stall
        // to leave maximum room for the remaining cows.
        int cowsPlaced = 1;

        // This stores the position of the most recently placed cow.
        int lastPosition = stalls[0];

        for (int i = 1; i < (int)stalls.size(); i++) {
            // Place a cow only when this stall is far enough
            // from the last chosen stall.
            if (stalls[i] - lastPosition >= distance) {
                cowsPlaced++;
                lastPosition = stalls[i];

                // Once all cows are placed, this distance is possible.
                if (cowsPlaced == k) {
                    return true;
                }
            }
        }

        return false;
    }

    /*
    Returns the largest minimum distance
    using binary search on possible distances.
    */
    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());

        // Distance smaller than 1 is not useful
        // when all stall positions are unique.
        int low = 1;

        // This is the largest distance two cows can ever have.
        int high = stalls.back() - stalls.front();

        // This stores the largest possible distance found so far.
        int answer = 0;

        while (low <= high) {
            // mid is the minimum distance currently being tested.
            int mid = low + (high - low) / 2;

            // If mid works, try a larger minimum distance.
            if (canPlace(stalls, k, mid)) {
                answer = mid;
                low = mid + 1;
            } else {
                // If mid fails, larger distances will also fail.
                high = mid - 1;
            }
        }

        return answer;
    }
};

// Driver code starts
int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;

    Solution obj;
    cout << obj.aggressiveCows(stalls, k) << endl;

    return 0;
}