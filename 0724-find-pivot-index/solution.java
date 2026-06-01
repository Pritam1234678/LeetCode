class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (nums[n - 1] - nums[i] == 0) {
                    return i;
                } else
                    continue;
            }
          else  if (i == n - 1) {
                if (nums[i - 1] == 0)
                    return i;
                else
                    return -1;
            }

         else  if (nums[i - 1] == nums[n - 1] - nums[i])
                return i;
        }
        return ans;
    }
}
