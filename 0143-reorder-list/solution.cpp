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
        ListNode *pre = NULL, *curr = head, *after = head;
        while (curr) {
            after = curr->next;
            curr->next = pre;
            pre = curr;
            curr = after;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* b = reverseList(slow->next);
        ListNode* a = head;

        slow->next = NULL;
        ListNode* c = new ListNode(69);
        ListNode* tc = c;
        ListNode* ta = a;
        ListNode* tb = b;
        while (ta && tb) {
            tc->next = ta;
            ta = ta->next;
            tc = tc->next;
            tc->next = tb;
            tb = tb->next;
            tc = tc->next;
        }
        tc->next = ta;
        head = c->next;
    }
};
