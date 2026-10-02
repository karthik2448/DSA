class Solution {
public:
    // Returns floor(sqrt(x)) for a non-negative integer x.
    // Time: O(log x), Space: O(1).
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int answer = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long square = 1LL * mid * mid;

            if (square <= x) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return answer;
    }
};