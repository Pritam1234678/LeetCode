class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> st = new HashMap<>();
        HashMap<Character, Character> ts = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char s1 = s.charAt(i);
            char t1 = t.charAt(i);
            if (!st.containsKey(s1))
                st.put(s1, t1);
            if (!ts.containsKey(t1))
                ts.put(t1, s1);
            if (st.get(s1) != t1 || ts.get(t1) != s1)
                return false;

        }
        return true;

    }
}
