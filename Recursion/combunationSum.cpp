#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void backtrack(int index, int target, vector<int>& candidates,
                   vector<int>& current, vector<vector<int>>& answer) {

        // If target becomes 0, the current combination is valid.
        if (target == 0) {
            answer.push_back(current);
            return;
        }

        // If all candidates are checked, no further combination is possible.
        if (index == candidates.size()) {
            return;
        }

        // If the current candidate can fit into the remaining target, pick it.
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);

            // Stay at the same index because the same candidate can be reused.
            backtrack(index, target - candidates[index], candidates, current, answer);

            // Remove the last picked element before trying another possibility.
            current.pop_back();
        } else {
            // If the candidate is greater than target, it cannot be picked.
        }

        // Skip the current candidate and move to the next index.
        backtrack(index + 1, target, candidates, current, answer);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> current;

        // Start exploring combinations from index 0.
        backtrack(0, target, candidates, current, answer);

        return answer;
    }
};

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution solution;
    vector<vector<int>> answer = solution.combinationSum(candidates, target);

    for (auto combination : answer) {
        cout << "[";

        for (int index = 0; index < combination.size(); index++) {
            // Add comma before every element except the first one.
            if (index > 0) {
                cout << ", ";
            }

            cout << combination[index];
        }

        cout << "] ";
    }

    return 0;
}