class Solution {
    public long[] findPrefixScore(int[] nums) {
        int n = nums.length; 
        long[] longArray = new long[n];

        
        for (int i = 0; i < longArray.length; i++) {
            longArray[i] = nums[i]; 
        }

        long[] arr = new long[n];
        long m = longArray[0];
        
        
        for (int i = 0; i < longArray.length; i++) {
            if (i == 0) {
                arr[i] = 2 * longArray[0];
            } else {
               
                m = Math.max(m, longArray[i]); 
                arr[i] = longArray[i] + m;
            }
        }
        
       
        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
        }
        return arr;
    }
}

