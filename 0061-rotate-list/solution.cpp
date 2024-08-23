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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr|| head->next==nullptr){
            return head;
        }
       ListNode*temp=head;
         ListNode*tail=NULL;
        int count=0;
        while (temp!=nullptr){
            if(temp->next==nullptr) tail=temp;
            temp=temp->next;
            count++;
        }
      
        k=k%count;
        if(k==0)return head;
        temp=head;
        for (int i=1; i<=count-k-1; i++){
            temp=temp->next;
        }
        tail->next=head;
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};
