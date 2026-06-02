class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int target) {
        if (target <= 1) return 0;
        int i = 0, j = 0, n = nums.length, prod = 1, count = 0;
        while (j <= n - 1) {
            prod *= nums[j];
            while (prod >= target) {  // ✅ >= target pe shrink
                prod /= nums[i];
                i++;
            }
            count += j - i + 1;  // ✅ valid subarrays ending at j
            j++;
        }
        return count;
    }
}
