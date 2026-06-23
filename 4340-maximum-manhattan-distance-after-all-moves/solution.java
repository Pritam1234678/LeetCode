class Solution {
    public int maxDistance(String moves) {
        int u = 0, d = 0, l = 0, r = 0, wild = 0;

        for (char c : moves.toCharArray()) {
            switch (c) {
                case 'U' -> u++;
                case 'D' -> d++;
                case 'L' -> l++;
                case 'R' -> r++;
                case '_' -> wild++;
            }
        }

        return Math.abs(r - l) + Math.abs(u - d) + wild;
    }
}
