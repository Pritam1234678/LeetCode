class Solution {
    private boolean allZero(int[] freq) {
        for (int x : freq) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }

    public boolean checkInclusion(String s1, String s2) {

        if (s1.length() > s2.length()) {
            return false;
        }

        int freq[] = new int[26];

        for (char c : s1.toCharArray()) {
            freq[c - 'a']++;
        }

        int i = 0, j = s1.length() - 1;

        for (; i <= j; i++) {
            freq[s2.charAt(i) - 'a']--;
        }

        if (allZero(freq))
            return true;

        i = 1;
        j = s1.length();

        while (j < s2.length()) {

            freq[s2.charAt(i - 1) - 'a']++;
            freq[s2.charAt(j) - 'a']--;

            if (allZero(freq))
                return true;

            i++;
            j++;
        }

        return false;
    }
}
