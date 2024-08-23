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
   ListNode* mergeTwoLists(ListNode* a, ListNode* b) {

       
        ListNode* c= new ListNode(0);
        ListNode* t=c;
        while(a!=NULL&& b!=NULL){
            if((b->val)>=(a->val)){
                t->next=a;
                t=a;
                a=a->next;
            }
              else{
               
                t->next=b;
                t=b;
                b=b->next;
            }
        }
        if(a==nullptr){
            t->next=b;
        }
        if(b==nullptr){
            t->next=a;
        }
        return c->next;
   }
};
