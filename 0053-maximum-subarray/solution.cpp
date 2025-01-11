class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0, maxg = INT_MIN;
        for(auto c : nums)
            curMax = max(c, curMax + c),
            maxg = max(maxg, curMax);
        return maxg;
    }
};
