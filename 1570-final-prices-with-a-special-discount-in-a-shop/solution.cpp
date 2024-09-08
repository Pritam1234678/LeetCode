class Solution {
public:
    vector<int> finalPrices(vector<int>& v) {
        int n = v.size();
        stack<int> s;
     
        
        for (int i = 0; i <n; i++) {
            while (!s.empty() && v[i] <= v[s.top()]) {
                v[s.top()] -= v[i];
                s.pop();
            } 
            s.push(i);
        }
        
        return v;
    }
};

