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
 ListNode* reverse(ListNode* head) {
        ListNode *pre=NULL, *curr=head,*after =head;
        while(curr){
            after=curr->next;
            curr->next=pre;
            pre=curr;
            curr= after;
        }
        return pre;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        ListNode* res = new ListNode(0);
        ListNode* temp = res;
        int maxx = INT_MIN;
        while(head) {
            if(head->val>=maxx) {
                maxx = max(maxx, head->val);
                ListNode* nextNode = new ListNode(maxx);
                temp->next = nextNode;
                temp=temp->next;
            }
            head=head->next;
        }
        res=res->next;
        return reverse(res);
    }

    
};
