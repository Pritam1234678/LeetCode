class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n = v.size();
        stack<int> s;
        vector<int> ans(n, -1); // Initialize ans with -1
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            while (!s.empty() && v[idx] >= s.top()) {
                s.pop();
            }
            if (!s.empty()) {
                ans[idx] = s.top();
            }
            s.push(v[idx]);
        }
        return ans;
    }
};

