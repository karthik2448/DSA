#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Counts reverse pairs while sorting the selected range.
    int mergeSort(vector<int>& arr, int left, int right) {
        // A range with zero or one value cannot contain a pair.
        if (left >= right) {
            return 0;
        }

        int mid = left + (right - left) / 2;
        int pairs = 0;

        pairs += mergeSort(arr, left, mid);
        pairs += mergeSort(arr, mid + 1, right);
        pairs += countCrossPairs(arr, left, mid, right);
        mergeSortedHalves(arr, left, mid, right);

        return pairs;
    }

    // Returns cross pairs from the left half to the right half.
    int countCrossPairs(vector<int>& arr, int left, int mid, int right) {
        int pairs = 0;
        int rightPointer = mid + 1;

        // Count how many right-half values are valid for each left-half value.
        for (int leftPointer = left; leftPointer <= mid; leftPointer++) {
            long long leftValue = arr[leftPointer];

            // Move across right-half values that satisfy the reverse-pair condition.
            while (rightPointer <= right && leftValue > 2LL * arr[rightPointer]) {
                rightPointer++;
            }

            pairs += rightPointer - (mid + 1);
        }

        return pairs;
    }

    // Merges two sorted halves into one sorted range.
    void mergeSortedHalves(vector<int>& arr, int left, int mid, int right) {
        vector<int> merged;
        int first = left;
        int second = mid + 1;

        // Merge the smaller available value from the two halves.
        while (first <= mid && second <= right) {
            // The smaller value should be placed next in the merged range.
            if (arr[first] <= arr[second]) {
                merged.push_back(arr[first]);
                first++;
            } else {
                merged.push_back(arr[second]);
                second++;
            }
        }

        // Copy any remaining values from the left half.
        while (first <= mid) {
            merged.push_back(arr[first]);
            first++;
        }

        // Copy any remaining values from the right half.
        while (second <= right) {
            merged.push_back(arr[second]);
            second++;
        }

        // Write the merged values back into the selected range.
        for (int index = 0; index < merged.size(); index++) {
            arr[left + index] = merged[index];
        }
    }

public:
    // Returns the number of reverse pairs.
    int reversePairs(vector<int>& nums) {
        vector<int> arr = nums;
        int n = arr.size();

        // Arrays with fewer than two values cannot form a pair.
        if (n < 2) {
            return 0;
        }

        return mergeSort(arr, 0, n - 1);
    }
};

// Driver code
int main() {
    vector<int> nums = {10, 5, 2, 6, 1, 8, 3, -2};

    // instance for class Solution
    Solution sol;

    cout << sol.reversePairs(nums) << '\n';
    return 0;
}