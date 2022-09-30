## [Merge In Between Linked Lists ](https://leetcode.com/problems/merge-in-between-linked-lists/) 

```cpp
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * temp = list1;
        ListNode * athNode; //prev node of athNode
        ListNode * bthNode; //bth node
        
        int count = 0; //because of 0 indexing
        
        //jab tak bth node na mile tab tak aage badhate jao
        while(count < b)
        {
            //ath node ke just prev node ko save karte hue, hum aage jake iss prev node ke next me list2 ke head ko join kar denge
            if(count == (a-1))
                athNode = temp;
            
            temp = temp -> next;
            count++;
        }
        
        //ab temp hi bth node h, condition dekho loop ki
        bthNode = temp;
        //ath node ko remove karte hue, aur waha list2 ko join karte hue
        athNode -> next = list2;
        
        temp = list2;
        //jab tak list2 ka lastnode na mile tab tak loop chalao
        while(temp -> next != NULL)
            temp = temp -> next;
        
        //ab bth node ko remove karke uske aage ke part ko list2 ke end me join karte hue.
        temp->next = bthNode->next;
        
        return list1;
    }
};

```