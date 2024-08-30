
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        int fidx = -1;
        int sdix = -1;
        ListNode *a = head, *b = head->next, *c = head->next->next;
        int f = -1;
        int s = -1;
        int mind = INT_MAX;
        if (c == nullptr)
            return {-1, -1};
        while (c) {
            if ((b->val > a->val && b->val > c->val) ||
                (b->val < a->val && b->val < c->val)) {
                if (fidx == -1)
                    fidx = idx;
                else
                    sdix = idx;

                f = s;
                s = idx;
                if (f != -1)
                    mind = min(mind, (s - f));
            }
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        if (sdix == -1)
            return {-1, -1};
        int maxd = (sdix - fidx);

        return {mind, maxd};
    }
};
