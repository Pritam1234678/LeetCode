
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=NULL, *curr=head,*after =head;
        while(curr){
            after=curr->next;
            curr->next=pre;
            pre=curr;
            curr= after;
        }
        return pre;
    }
};
