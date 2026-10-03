/*
## REVIEW
Problem - 203. Remove Linked List Elements

```
Pattern:
Linked List - Traversal & Deletion

The main idea was to traverse the list while checking the next node
and remove it whenever its value matched the given value.

Problems I faced:
- Handling deletion when the head itself matched the target.
- Handling multiple consecutive nodes with the same value.
- Managing temp and mover correctly after deletion.
- Accidentally causing control-flow issues due to missing braces.
- Making sure temp did not skip nodes after deleting one.

Time Complexity: O(n)
Space Complexity: O(1)
```

*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        if (!temp){
            return nullptr;
        }
        while(temp){
            ListNode* mover = temp -> next;
            if(head -> val == val){
                head = mover;
                temp = head;
                if (!mover)
                    continue;
                mover = mover -> next;
            }
            else{
                if (!mover){
                    temp = temp -> next;
                    continue;
                }
                if (mover -> val == val)
                    temp -> next = mover -> next;
                else
                    temp = temp -> next;
            }
        }
        return head;
    }
};