class Solution {
public:
bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX, second = INT_MAX;

    for (int num : nums) {
        if (num <= first) {
            first = num;  // Update the smallest number
        } else if (num <= second) {
            second = num;  // Update the second smallest number
        } else {
            return true;  // We found a triplet: first < second < num
        }
    }

    return false;  // No triplet found
}
};
