class Solution {
public:
    int reverse(int n) {
        int r = 0;
        while (n > 0) {
            r *= 10;
            r += (n % 10);
            n /= 10;
        }
        return r;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            int rev = reverse(nums.at(i));
            s.insert(nums[i]);
            s.insert(rev);
        }
        return s.size();
    }
};
