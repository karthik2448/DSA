#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int value) {
        data = value;
        next = nullptr;
    }
};

class Solution {
public:
    // Function to remove nth node from back using two pointers.
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        
        // Create n-node gap between fast and slow.
        for (int count = 0; count < n; count++) {
            fast = fast->next;
        }
        
        // Move until fast reaches last node.
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Bypass deletion target.
        slow->next = slow->next->next;
        return dummy.next;
    }
};

// Function to create linked list from array.
ListNode* createList(vector<int>& arr) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int value : arr) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }
    return dummy.next;
}

// Function to print linked list values.
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " ";
        current = current->next;
    }
}

// Driver code.
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = 2;
    ListNode* head = createList(arr);
    Solution sol;
    head = sol.removeNthFromEnd(head, n);
    printList(head);
    return 0;
}