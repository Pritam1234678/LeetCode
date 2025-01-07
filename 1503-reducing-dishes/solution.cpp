class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
        vector<int> suf(n, 1);
        sort(s.begin(), s.end());
        suf[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = s[i] + suf[i + 1];
        }
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (suf[i] >= 0) {
                idx = i;
                break;
            }
        }
        if (idx == -1)
            return 0;
        int x = 1;
        int y = 0;
        for (int i = idx; i < n; i++) {

            y += s[i] * x;
            x++;
        }
        return y;
    }
};
