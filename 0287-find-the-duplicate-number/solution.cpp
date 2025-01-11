class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()){
            if (nums[i]==nums[i+1]){
                return nums[i];
            }
            else i++;
        }
        return -1;
    }
};
