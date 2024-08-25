class Solution {
public:
    int size(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int n, m;
        n = size(list1);
        m = size(list2);
        ListNode* temp = list1;
        ListNode* tail2 = list2;

        for (int i = 0; i < a - 1; i++) {
            temp = temp->next;
        }
        ListNode* c = list1;
        for (int i = 0; i < b; i++) {
            c = c->next;
        }
        temp->next = list2;
        while (tail2->next != nullptr) {
            tail2 = tail2->next;
        }
        tail2->next = c->next;
        return list1;
    }
};
