class Solution {
    public boolean isSubsequence(String s, String t) {

        int prevIndex = -1;

        for(int i = 0; i < s.length(); i++) {

            int currIndex = t.indexOf(s.charAt(i), prevIndex + 1);

            if(currIndex == -1)
                return false;

            if(currIndex <= prevIndex)
                return false;

            prevIndex = currIndex;
        }

        return true;
    }
}
