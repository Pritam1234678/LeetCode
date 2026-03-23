class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int count = 0;

        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                // flip 3 elements
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                count++;
            }
        }

        // check last elements
        for (int i = n - 2; i < n; i++) {
            if (nums[i] == 0) return -1;
        }

        return count;
    }
}
