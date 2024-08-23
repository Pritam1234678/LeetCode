
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *a=head;
        ListNode *b= head;
        while(b!=nullptr){
            while(b!=nullptr && a->val==b->val){
                b=b->next;
            }
            a->next=b;
            a=b;
            if(b!=NULL){
                b=b->next;
            }
        }
        return head;
    }
};
