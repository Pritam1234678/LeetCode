class Solution {
public:
    int maxOperations(vector<int>& nums, int target) {
        unordered_map<int, int> m; // Map to track frequencies
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];

            // Check if the complement exists in the map
            if (m.find(rem) != m.end() && m[rem] > 0) {
                count++;
                m[rem]--; // Decrement frequency of the complement
            } else {
                m[nums[i]]++; // Increment frequency of the current number
            }
        }

        return count;
    }
};

