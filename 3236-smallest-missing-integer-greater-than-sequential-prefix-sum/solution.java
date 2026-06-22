class Solution {
    public int missingInteger(int[] nums) {
        int preSum = nums[0];

        int i = 1;
        while (i < nums.length && nums[i] == nums[i - 1] + 1) {
            preSum += nums[i];
            i++;
        }

        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }

        int ans = preSum;
        while (set.contains(ans)) {
            ans++;
        }

        return ans;
    }
}
