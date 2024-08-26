
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *curr = head, *after = head;
        while (curr) {
            after = curr->next;
            curr->next = pre;
            pre = curr;
            curr = after;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* x = reverseList(slow->next);
        temp = x;
        ListNode* a = head;
        while (temp) {
            if (a->val != temp->val)
                return false;
            else {
                a = a->next;
                temp = temp->next;
            }
        }
        return true;
    }
};
