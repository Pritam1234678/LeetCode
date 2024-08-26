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
        ListNode *pre=NULL, *curr=head,*after =head;
        while(curr){
            after=curr->next;
            curr->next=pre;
            pre=curr;
            curr= after;
        }
        return pre;
    }
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if (r == l)
            return head;
        ListNode* temp = head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        ListNode* e;

        int n = 1;
        while (temp != nullptr) {
            if (n == l - 1)
                a = temp;
            if (n == l )
                b= temp;
            if (n == r)
                c = temp;
            if (n == r + 1)
                d = temp;
                temp=temp->next;
                n++;
        }
        if(a)a->next=NULL;
        c->next=NULL;
       e= reverseList(b);
       if(a)a->next=e;
       b->next=d;
       if(a)return head;
       return e;
    }
};
