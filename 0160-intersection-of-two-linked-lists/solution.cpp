class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* ta = headA;
        ListNode* tb = headB;
        int ca = 0;
        while (ta != nullptr) {
            ta = ta->next;
            ca++;
        }
        int cb = 0;
        while (tb != nullptr) {
            tb = tb->next;
            cb++;
        }
        ta = headA;
        tb = headB;
        if (ca > cb) {
            int diff = ca - cb;
            for (int i = 0; i < diff; i++) {
                ta = ta->next;
            }
        } 
        else {
            int diff2 = cb - ca;
            for (int i = 0; i < diff2; i++) {
                tb = tb->next;
            }
        }
        while ( tb != nullptr) {
            if (ta == tb) {
                return ta;
            }
            ta = ta->next;
            tb = tb->next;
        }
        return NULL;
    }
};
