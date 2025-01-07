class Solution {
public:
    int bestClosingTime(string a) {
        vector<int> pre(a.size() + 1, 1);
        vector<int> suff(a.size() + 1, 1);
        pre[0] = 0;
        suff[0] = 0;
        for (int i = 0; i < a.size(); i++) {
            pre[i + 1] = pre[i] + ((a[i] == 'N') ? 1 : 0);
        }
        for (int i = a.size() - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] + ((a[i] == 'Y') ? 1 : 0);
        }
        for (int i = 0; i < suff.size(); i++) {
            pre[i] += suff[i];
        }
        int x = a.size();
        for (int i = 0; i < pre.size(); i++) {
            if (x > pre[i])
                x = pre[i];
        }
        for (int i = 0; i < pre.size() + 1; i++) {
            if (pre[i] == x)
                return i;
        }
        return a.size();
    }
};
