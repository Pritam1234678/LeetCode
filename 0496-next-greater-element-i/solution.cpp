class Solution {
public:
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> v;

        for(int i= nums2.size()-1;i>=0;i--){
            if(s.size()==0){
                 v.push_back(-1);
            }

            else if(s.size()>0 && s.top()>nums2[i]){
                v.push_back(s.top());
            }

            else if(s.size()>0 && s.top()<=nums2[i]){

                while(s.size()>0 && s.top()<=nums2[i]){
                    s.pop();
                }

                if(s.size()==0){
                    v.push_back(-1);
                }

                else{
                    v.push_back(s.top());
                }

        }

        s.push(nums2[i]);
        
    }

    reverse(v.begin(),v.end());

    vector<int> ans(nums1.size(),0);
    for(int i=0;i<nums1.size();i++){
        auto it = find(nums2.begin(),nums2.end(),nums1[i]);
        int index = it-nums2.begin();
        ans[i]=v[index];
    }


    return ans;
}
};
