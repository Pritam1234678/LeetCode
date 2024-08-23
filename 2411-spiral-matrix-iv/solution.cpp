class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> v(m, vector<int>(n, -1));
        int maxr = m - 1;
        int maxc = n - 1;
        int minr = 0;
        int minc = 0;
        ListNode *temp = head;
        while (maxr >= minr && maxc >= minc) {
            for (int i = minc; i <= maxc; i++) {
                if (temp == nullptr) {
                    return v;
                }
                v[minr][i] = temp->val;
                temp = temp->next;
            }
            minr++;
            if (minr > maxr || minc > maxc)
                break;
            for (int i = minr; i <= maxr; i++) {
                if (temp == nullptr) {
                    return v;
                }
                v[i][maxc] = temp->val;
                temp = temp->next;
            }
            maxc--;
            if (minr > maxr || minc > maxc)
                break;
            for (int i = maxc; i >= minc; i--) {
                if (temp == nullptr) {
                    return v;
                }
                v[maxr][i] = temp->val;
                temp = temp->next;
            }
            maxr--;
            if (minr > maxr || minc > maxc)
                break;
            for (int i = maxr; i >= minr; i--) {
                if (temp == nullptr) {
                    return v;
                }
                v[i][minc] = temp->val;
                temp = temp->next;
            }
            minc++;
        }
        return v;
    }
};
