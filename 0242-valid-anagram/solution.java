class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;
        int freq[] = new int[26];
        for (int i = 0; i < s.length(); i++) {

            int a = s.charAt(i) - 'a';
            int b = t.charAt(i) - 'a';
            freq[a] += 1;
            freq[b] -= 1;

        }
        for (int x : freq) {
            if (x != 0)
                return false;
        }
        return true;

    }
}
