class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);

        String a = strs[0];
        String b = strs[strs.length - 1];

        int idx = -1;

        for (int i = 0; i < Math.min(a.length(), b.length()); i++) {
            if (a.charAt(i) != b.charAt(i))
                break;

            idx = i;
        }

        return a.substring(0, idx + 1);
    }
}
