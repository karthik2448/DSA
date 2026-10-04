#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Checks if all packages can be shipped
    within days using the given capacity.
    */
    bool canShip(vector<int>& weights, int days, int capacity) {
        // At least one day is needed when packages exist.
        int usedDays = 1;

        // This stores the total weight loaded on the current day.
        int currentLoad = 0;

        for (int weight : weights) {
            // Start a new day when the next package
            // would cross the ship capacity.
            if (currentLoad + weight > capacity) {
                usedDays++;

                // The current package begins the next day
                // because package order cannot be changed.
                currentLoad = weight;
            } else {
                // The package fits today, so keep it
                // in the current day's load.
                currentLoad += weight;
            }
        }

        // This capacity works if shipping finishes
        // within the allowed number of days.
        return usedDays <= days;
    }

    /*
    Returns the minimum ship capacity needed
    using binary search on possible capacities.
    */
    int shipWithinDays(vector<int>& weights, int days) {
        // The ship must at least carry the heaviest package.
        int low = *max_element(weights.begin(), weights.end());

        // Carrying all packages in one day is always enough.
        int high = accumulate(weights.begin(), weights.end(), 0);

        // This stores the smallest valid capacity found so far.
        int answer = high;

        while (low <= high) {
            // mid is the capacity currently being tested.
            int mid = low + (high - low) / 2;

            // If mid works, try to find an even smaller valid capacity.
            if (canShip(weights, days, mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                // If mid does not work, more capacity is required.
                low = mid + 1;
            }
        }

        return answer;
    }
};

// Driver code starts
int main() {
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    Solution obj;
    cout << obj.shipWithinDays(weights, days) << endl;

    return 0;
}