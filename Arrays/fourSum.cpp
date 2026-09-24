#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> answer;

        // Four different indices are required.
        if (n < 4) {
            return answer;
        }

        sort(nums.begin(), nums.end());

        for (int first = 0; first < n - 3; first++) {
            /*
             * Skip a repeated first value to avoid
             * generating duplicate quadruplets.
             */
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }

            for (int second = first + 1; second < n - 2; second++) {
                /*
                 * Skip repeated second values only
                 * within the current first value.
                 */
                if (second > first + 1 &&
                    nums[second] == nums[second - 1]) {
                    continue;
                }

                int left = second + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum =
                        (long long) nums[first] +
                        nums[second] +
                        nums[left] +
                        nums[right];

                    // A smaller sum needs a larger left value.
                    if (sum < target) {
                        left++;
                    }
                    // A larger sum needs a smaller right value.
                    else if (sum > target) {
                        right--;
                    }
                    else {
                        answer.push_back({
                            nums[first],
                            nums[second],
                            nums[left],
                            nums[right]
                        });

                        left++;
                        right--;

                        /*
                         * Skip repeated boundary values
                         * to avoid duplicate answers.
                         */
                        while (left < right &&
                               nums[left] == nums[left - 1]) {
                            left++;
                        }

                        while (left < right &&
                               nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution solution;
    vector<vector<int>> answer = solution.fourSum(nums, target);

    for (const auto& quadruplet : answer) {
        for (int value : quadruplet) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}