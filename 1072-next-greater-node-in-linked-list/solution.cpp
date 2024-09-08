
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
    vector<int> nextLargerNodes(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            n++;
        }

        head = reverseList(head);
        temp = head;
        stack<int> s;
        vector<int> ans(n);
        ans[0] = 0;
        s.push(temp->val);
     for(int i=1;i<n&&temp!=nullptr;i++){
        temp=temp->next;
            // pop all the elements smaller than arr[i]
            while (s.size() > 0 && temp->val >= s.top()) {
                s.pop();
            } // marking the ans
            if (s.size() == 0) {
                ans.at(i) = 0;
            } else {
                ans.at(i) = s.top();
            }
            // pushing in stack
            s.push(temp->val);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
