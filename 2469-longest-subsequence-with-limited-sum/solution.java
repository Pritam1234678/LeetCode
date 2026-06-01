class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        Arrays.sort(nums);
        for(int i=1;i<nums.length;i++){
            nums[i]+=nums[i-1];

        }
        int ans[]=new int[queries.length];
        for(int i=0;i<queries.length;i++){
            int lo=0,hi=nums.length-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(nums[mid]>queries[i]) hi=mid-1;
                else{
                    ans[i]=Math.max(ans[i],mid+1);
                    lo=mid+1;
                }

            }
        }
        return ans;
    }
}
