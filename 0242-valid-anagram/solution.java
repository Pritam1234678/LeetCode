class Solution {
       public static String sortString(String str) {
        char[] charArray = str.toCharArray();
        Arrays.sort(charArray);
        return new String(charArray);
    }
    public boolean isAnagram(String s, String t) {
         if (s.length()!=t.length()) return false;
           String a=sortString(s);
           String b=sortString(t);
           if (a.equals(b)) return true;
           return false;
           
    }
}
