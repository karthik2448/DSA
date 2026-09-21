#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns the first numRows rows of Pascal's Triangle.
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        // Build each row from top to bottom.
        for (int row = 0; row < numRows; row++) {
            vector<int> current(row + 1, 1);

            // Fill only the interior positions from the previous row.
            for (int col = 1; col < row; col++) {
                current[col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
            }

            triangle.push_back(current);
        }

        return triangle;
    }
};

// Prints a triangle in list form.
void printTriangle(const vector<vector<int>>& triangle) {
    cout << "[";

    int rowCount = triangle.size();

    // Print each row in order.
    for (int row = 0; row < rowCount; row++) {
        cout << "[";

        int colCount = triangle[row].size();

        // Print every value in the current row.
        for (int col = 0; col < colCount; col++) {
            cout << triangle[row][col];

            // Add a separator between values in the same row.
            if (col + 1 < colCount) {
                cout << ", ";
            }
        }

        cout << "]";

        // Add a separator between completed rows.
        if (row + 1 < rowCount) {
            cout << ", ";
        }
    }

    cout << "]\n";
}

// Driver code
int main() {
    int numRows = 6;

    // instance for class Solution
    Solution sol;

    vector<vector<int>> answer = sol.generate(numRows);
    printTriangle(answer);

    return 0;
}