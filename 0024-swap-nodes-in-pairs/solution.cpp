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

    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
         dummy->next = head;
        ListNode *pre=dummy;
        while(pre->next&&pre->next->next){
           ListNode *curr =pre->next, *nextt=pre->next->next;
           curr->next=nextt->next;
           nextt->next=curr;
           pre->next =nextt;
           pre=curr;
        }
       return dummy ->next;
    }
};
