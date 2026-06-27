class Solution {
    List<List<String>> ans = new ArrayList<>();
    int n;

    public List<List<String>> partition(String s) {
        n = s.length();
        rec(s, 0, new ArrayList<>());
        return ans;
    }

    public boolean isPalindrome(String s, int l, int r) {
        while (l <= r) {
            if (s.charAt(l) != s.charAt(r))
                return false;
            l++;
            r--;
        }
        return true;
    }

    public void rec(String s, int pi, List<String> arr) {
        if (pi == n) {
            ans.add(new ArrayList<>(arr));
            return;
        }

        for (int i = pi; i < n; i++) {
            if (isPalindrome(s, pi, i)) {
                arr.add(s.substring(pi, i + 1));
                rec(s, i + 1, arr);
                arr.remove(arr.size() - 1);
            }
        }
    }
}
