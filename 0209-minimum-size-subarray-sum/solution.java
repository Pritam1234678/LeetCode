import java.util.Arrays;

class Solution {
    public int minSubArrayLen(int target, int[] sessions) {
        int n = sessions.length;
        int[] prefix = new int[n + 1];

        // Build prefix sum array
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + sessions[i];
        }

        int result = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int required = prefix[i] + target;

            int j = Arrays.binarySearch(prefix, required);

            if (j < 0) {
                j = -j - 1;
            }

            if (j <= n) {
                result = Math.min(result, j - i);
            }
        }

        return (result == Integer.MAX_VALUE) ? 0 : result;
    }
}

