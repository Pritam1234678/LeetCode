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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 0;
        while (temp) {
            temp = temp->next;
            n++;
        }
        int p = n / k;
        int rem = n % k;
        vector<ListNode*> v;
        temp = head;

        while (temp) {
            int q = p;
            ListNode* c = new ListNode(0);
            ListNode* t = c;
            if (rem > 0) {
                q++;
                rem--;
            }

            for (int i = 1; i <= q; i++) {
                t->next = temp;
                temp = temp->next;
                t = t->next;
            }
            t->next = nullptr;
            v.push_back(c->next);
        }
        
        while (v.size() < k) {
            v.push_back(nullptr);
        }
        return v;
    }
};
