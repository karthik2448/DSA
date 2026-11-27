#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = nullptr;
    }
};

class Solution {
public:
    // Function to add two numbers.
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node simplifies answer-list construction.
        ListNode* dummy = new ListNode(0);

        // Tail always marks the last answer node.
        ListNode* tail = dummy;

        // Carry stores overflow from the previous digit sum.
        int carry = 0;

        // Continue until both lists end and carry becomes zero.
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            // Start current sum with the carry value.
            int sum = carry;

            // Add the current digit from the first list when available.
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add the current digit from the second list when available.
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Current node stores the unit digit.
            int digit = sum % 10;

            // Carry moves to the next position.
            carry = sum / 10;

            // Attach a new node with the current digit.
            tail->next = new ListNode(digit);

            // Move tail to the newly created node.
            tail = tail->next;
        }

        // Return the real head after skipping the dummy node.
        return dummy->next;
    }
};

// Build a linked list from a digit array.
ListNode* buildList(const vector<int>& values) {
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;

    for (int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }

    return dummy->next;
}

// Print the linked list in a readable format.
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr) {
            cout << " ";
        }

        head = head->next;
    }

    cout << "\n";
}

// Run the optimal solution on a hard-coded sample.
int main() {
    vector<int> first = {9, 9, 9};
    vector<int> second = {1};

    ListNode* l1 = buildList(first);
    ListNode* l2 = buildList(second);

    Solution solution;
    ListNode* answer = solution.addTwoNumbers(l1, l2);

    printList(answer);
    return 0;
}
