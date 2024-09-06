class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        stack<int> st;
        int n = v.size();
        vector<int> nsi(n, n);
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && v[i] <= v[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                nsi[i] = n;
            } else {
                nsi[i] = st.top();
            }
            st.push(i);
        }

        stack<int> gt;
        vector<int> psi(n, -1);
        gt.push(0);

        for (int i = 1; i < n; i++) {
            while (!gt.empty() && v[i] <= v[gt.top()]) {
                gt.pop();
            }
            if (gt.empty()) {
                psi[i] = -1;
            } else {
                psi[i] = gt.top();
            }
            gt.push(i);
        }

        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            int h = v[i];
            int b = nsi[i] - psi[i] - 1;
            int area = h * b;
            maxarea = max(area, maxarea);
        }

        return maxarea;
    }
};

