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
        // if there is no element in linked list, return NULL
        if(head==NULL) return head;
        //We have three pointers, previous, current, next
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* n = head->next;
        
        while(curr!=NULL){
            // update the next of current pointer to previous and current to next
            curr->next = prev;
            prev = curr;
            curr = n;
            if(n!=NULL) n = n->next;
        }
        return prev;
    }
};
