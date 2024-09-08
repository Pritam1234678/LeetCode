class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& v) {
        int n=v.size();
        stack<int>st;
        vector<int> ans(n,0);
        st.push(v.at(n-1));
        ans[n-1]=0;
        for(int i=n-2; i>=0;i--){
            int count=0;
            while(!st.empty()&& v.at(i)>st.top()){
                st.pop();
                count++;
            }
            if(!st.empty())count++;
            ans[i]=count;
            st.push(v[i]);
        }
        return ans;
    }
};
