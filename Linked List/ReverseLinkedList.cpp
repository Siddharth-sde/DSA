/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if ( head  == NULL || head -> next== NULL){
            return head;
        }
        ListNode* temp  = head -> next;
        ListNode* store = temp -> next;
        ListNode* curr = head;
        int count = 0;
        while(temp != NULL){
            if (count == 0){
                curr -> next = nullptr;
                count++;
                continue;
            } 
            if (temp -> next == NULL){
                head = temp;
                temp -> next= curr;
                break;
            }
            temp -> next = curr;
            curr = temp;
            temp = store;
            store = store -> next;
        }
        return head;
    }
};