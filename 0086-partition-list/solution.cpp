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
    ListNode* partition(ListNode* head, int x) {
        ListNode* hi = new ListNode(0);
        ListNode* lo = new ListNode(9);
        ListNode* tl = lo;
        ListNode* th = hi;
        ListNode*temp =head;
        while(temp!=nullptr){
            if(temp->val<x){
                tl->next=temp;
                tl=temp;
                temp=temp->next;
            }
            else{
                th->next=temp;
                th=temp;
                temp=temp->next;
            }
        }
        tl->next=hi->next;
        th->next=NULL;
        return lo->next;
    }
};
