/*
## REVIEW
Problem - 83. Remove Duplicates from Sorted List

Pattern:
Linked List - Traversal

The main idea was to compare the current node with the next node.
If they were equal, skip the duplicate node. Otherwise, move forward.

*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        if (!temp){
            return nullptr;
        }
        while(temp){
            ListNode* mover = temp -> next;
            if (!mover)
                return head;
            if (temp -> val == mover -> val){
                temp -> next = temp -> next -> next;
            }
            else
                temp = temp -> next;
        }
        return head;
    }
};