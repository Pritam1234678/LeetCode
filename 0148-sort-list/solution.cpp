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
 ListNode *mergeSort(ListNode *a, ListNode *b)
{

    ListNode *c = new ListNode(0);
    ListNode *t = c;
    while (a != NULL && b != NULL)
    {
        if ((b->val) >= (a->val))
        {
            t->next = a;
            t = a;
            a = a->next;
        }
        else
        {

            t->next = b;
            t = b;
            b = b->next;
        }
    }
    if (a == nullptr)
    {
        t->next = b;
    }
    if (b == nullptr)
    {
        t->next = a;
    }
    return c->next;
}
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* a =head;
        ListNode* b=slow->next;
        slow->next=nullptr;
        a=sortList(a);
        b=sortList(b);
        ListNode* c =mergeSort(a,b);
        return c;
    }
};
