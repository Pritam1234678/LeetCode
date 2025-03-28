class Solution {
    public boolean canPlaceFlowers(int[] arr, int n) {
        int x = arr.length;
        int count = 0; 
        
        for (int i = 0; i < x; i++) {
            if (arr[i] == 0) {
                
                boolean leftEmpty = (i == 0) || (arr[i - 1] == 0);
                boolean rightEmpty = (i == x - 1) || (arr[i + 1] == 0);

                if (leftEmpty && rightEmpty) {
                    arr[i] = 1; 
                    count++;
                    if (count >= n) return true; 
                }
            }
        }
        
        return count >= n;
    }
}

