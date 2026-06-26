class Solution {
    public int countSubstrings(String s) {

        int len = s.length();
        int ans = 0;

        for (int i = 0; i < len; i++) {

            int left = i - 1;
            int right = i;

            // Duplicate characters ko ek block bana do
            while (right < len - 1 && s.charAt(right) == s.charAt(right + 1)) {
                right++;
            }

            // Next iteration duplicate block ke baad se start hogi
            i = right;

            // Block ke andar jitne palindrome hain
            int block = right - left;
            ans += block * (block + 1) / 2;

            // Block ke bahar expand karo
            while (left >= 0 && right < len - 1 &&
                   s.charAt(left) == s.charAt(right + 1)) {

                ans++;
                left--;
                right++;
            }
        }

        return ans;
    }
}
