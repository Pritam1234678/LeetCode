class FindSumPairs {
public:
    unordered_map<int,int> mpp1, mpp2;
    vector<int> v2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto& it: nums1)mpp1[it]++;
        for(auto& it: nums2)mpp2[it]++;
        v2 = nums2;
    }
    
    void add(int index, int val) {
        int old = v2[index];
        mpp2[old]--;
        if(mpp2[old] == 0)mpp2.erase(old);

        int newval = old+val;
        mpp2[newval]++;
        v2[index] = newval;
    }
    
    int count(int tot) {
        int result = 0;

        for(auto& [num, freq] : mpp1){
            int com = tot-num;
            if(mpp2.find(com) != mpp2.end()){
                result += freq*mpp2[com];
            }
        }

        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
