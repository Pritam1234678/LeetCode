class Solution {
    public int findMiddleIndex(int[] nums) {
        for (int i = 1; i < nums.length; i++) {
            nums[i] += nums[i - 1];
        }
       for(int i=0;i<nums.length;i++){
         int ls = 0;
        if(i>0) ls=nums[i-1];
        int rs=nums[nums.length-1]-nums[i];
         if(ls==rs) return i;
       }
       return -1;
    }
}
