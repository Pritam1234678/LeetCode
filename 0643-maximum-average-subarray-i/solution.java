class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double maxSum = sum;
        int i = 0, j = k;
        while (j < nums.length) {
            sum = sum - nums[i] + nums[j];
            maxSum = Math.max(maxSum, sum);
            i++;
            j++;
        }
        return maxSum / (double) k;
    }
}
