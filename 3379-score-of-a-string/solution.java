class Solution {
    public int scoreOfString(String s) {
        
        if (s == null || s.length() < 2) {
            return 0;
        }

        char[] arr = s.toCharArray();
        int ans = 0;

       
        for (int i = 0; i < arr.length - 1; i++) {
            ans += Math.abs(arr[i] - arr[i + 1]);
        }

        return ans;
    }
}

