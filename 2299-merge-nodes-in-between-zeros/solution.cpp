class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        ListNode* curr = head->next;
        
        while(curr) {
            int sum = 0;
            while(curr && curr->val != 0) {
                sum += curr->val;
                curr = curr->next;
            }
            if(curr) {
                prev->next = new ListNode(sum);
                prev = prev->next;
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
};
