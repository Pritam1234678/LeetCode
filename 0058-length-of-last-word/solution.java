class Solution {
    public int lengthOfLastWord(String s) {
        if(s==null) return 0;
        String[] str= s.trim().split("\\s+");
        return str[str.length-1].length();
        
    }
}
