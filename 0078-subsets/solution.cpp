#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        vector<int> current;
        backtrack(0, nums, current);
        return res;
    }

private:
    void backtrack(int index, vector<int>& nums, vector<int> current) {
        if (index == (int)nums.size()) {
            res.push_back(current);   // store this subset
            return;
        }

        // 1) Exclude nums[index]
        backtrack(index + 1, nums, current);

        // 2) Include nums[index] (works on a copy)
        current.push_back(nums[index]);
        backtrack(index + 1, nums, current);
    }
};


