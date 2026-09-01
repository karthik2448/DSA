#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi = LLONG_MIN;
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (sum > maxi) {
                maxi = sum;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
};

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution sol;

    int maxSum = sol.maxSubArray(arr);

    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}