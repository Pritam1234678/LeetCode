/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp=head;
        ListNode* slow =head;
        ListNode* fast= head; 
        bool flag  = false;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast =fast->next->next;
            if(slow==fast){
                flag=true;
                break;
            }
        }
        if(flag==false) return nullptr;
        else {
            while(temp!=slow){
                temp=temp->next;
                 slow=slow->next;
            }
            return slow;
        }

        return nullptr;
    }
};
