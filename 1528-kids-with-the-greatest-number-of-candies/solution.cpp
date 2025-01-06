class Solution {
public:
    bool helper(int x, int max) {
        if (x >= max)
            return true;
        else
            return false;
    }
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
         int max = INT_MIN;
        for (int i = 0; i < candies.size(); i++) {
           
            if (candies[i] > max) {
                max = candies[i];
            }
        }
        for (int i = 0; i < candies.size(); i++) {
            ans.push_back(helper((candies[i] + extraCandies), max));
        }
        return ans;
    }
};
