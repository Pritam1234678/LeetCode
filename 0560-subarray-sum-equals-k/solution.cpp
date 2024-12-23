class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector <int> v(nums.size(),0);
        int count =0;
        int sum =0;
        v[0]=nums[0];
        for(int i=1; i<v.size();i++){
            v.at(i)= nums[i]+v.at(i-1);
        }
        unordered_map<int,int> mp;
        for(int i=0; i<v.size();i++){
            if(v[i]==k){
                count++;
            }
            int rem =v[i]-k;
            if(mp.find(rem)!=mp.end()) count+= mp[rem];
            mp[v[i]]++;
        }
        return count;
    }
};
