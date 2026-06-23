class Solution {

    private boolean check(int[] freq) {
        for (int i : freq) {
            if (i != 0)
                return false;
        }
        return true;
    }

    public List<Integer> findAnagrams(String s, String p) {

        List<Integer> list = new ArrayList<>();

        if (p.length() > s.length())
            return list;

        int k = p.length();

        int freq[] = new int[26];

        for (char ch : p.toCharArray())
            freq[ch - 'a']++;

        int i = 0;

        // first window
        for (; i < k; i++)
            freq[s.charAt(i) - 'a']--;

        if (check(freq))
            list.add(0);

        for (i = 1; i <= s.length() - k; i++) {

            int j = i + k - 1;

            freq[s.charAt(i - 1) - 'a']++; 
            // as humne piche ka -- kar dia so and i ko bada dia so ab pichle ka koi kaam nehi ha
            // but uska freq -1 hoke rakha ha so ise 0 karna padega as pura freq array
            // check hota ha agar 0 ha ya nehi so always false return karega isiliye.......

            freq[s.charAt(j) - 'a']--;

            if (check(freq))
                list.add(i);
        }

        return list;
    }
}
