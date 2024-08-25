class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
 ListNode* temp = head;
        if (temp->val == val) {
            return removeElements(temp->next, val);
        }

        
        while (temp->next != nullptr) {
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};
