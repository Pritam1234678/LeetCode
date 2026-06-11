class Solution {
    public int trap(int[] height) {
        int n =height.length;
        int pre[]= new int[n];
        pre[0]=-1;
        int max= height[0];
        for(int i=1; i<n;i++){
            pre[i]=max;
            max=Math.max(height[i],max);
        }
         max =height[n-1];
        pre[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            if(max<pre[i])
            pre[i]=max;
            max=Math.max(height[i],max);
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(height[i]<pre[i])ans+=pre[i]-height[i];
        }
        return ans;
    }
}
