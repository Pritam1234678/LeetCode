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
    int getDecimalValue(ListNode* head) {

        int a = 0;
        ListNode* temp = reverseList(head);

        int i = 0;
        while (temp) {
            a += (temp->val) * pow(2, i);
            temp = temp->next;
            i++;
        }
        return a;
    }
};
