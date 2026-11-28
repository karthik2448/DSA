#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int data) { val = data; next = nullptr; }
};

class Solution {
public:
    // Function to reverse a linked list by changing links.
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        // Traverse nodes and reverse one link per step.
        while (current != nullptr) {
            ListNode* front = current->next;
            current->next = prev;
            prev = current;
            current = front;
        }
        return prev;
    }
};

// Function to create a linked list from an array.
ListNode* createList(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int index = 1; index < (int)arr.size(); index++) {
        current->next = new ListNode(arr[index]);
        current = current->next;
    }
    return head;
}

// Function to print linked list values.
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) cout << " ";
        current = current->next;
    }
}

// Driver code.
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createList(arr);
    Solution sol;
    head = sol.reverseList(head);
    printList(head);
    return 0;
}