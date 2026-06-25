class Solution {
    public String mySubstring(String s, int left, int right) {
        StringBuilder sb = new StringBuilder();

        while (left <= right) {
            sb.append(s.charAt(left));
            left++;
        }

        return sb.toString();
    }

    public String longestPalindrome(String s) {
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            int left = i, right = i;
            while (left >= 0 && s.charAt(left) == ch)
                left--;
            while (right < s.length() && s.charAt(right) == ch)
                right++;
            while (left >= 0 && right < s.length()) {
                if (s.charAt(left) != s.charAt(right))
                    break;
                left--;
                right++;
            }
            left++;
            right--;
            while (end - start < right - left) {
                end = right;
                start = left;
            }
        }
        return mySubstring(s,start, end);
    }
}
