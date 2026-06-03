class Solution {
    public int longestSubarray(int[] arr) {
        int z=0,n=arr.length,mlen=0,zero=0;
        for(int ele: arr){
            if(ele==0) z++;
           
        }
        int i=0;
        int j=0;
        if(z==0)return n-1;
        while(i<n &&arr[i]==0) i++;
        if(i==n)return 0;
        j=i;
        while(j<n){
            if(arr[j]==1)j++;
            else{
                if(zero==0){
                    zero++;
                    j++;
                }
                else{
                    mlen=Math.max(mlen,j-i-1);
                    j++;
                    while(i<n &&arr[i]==1) i++; //i--> will reach to 0
                    i++; // i->after 0 is 1
                }
            }
        }
        if(zero==0)return j-i;
         return Math.max(mlen,j-i-1);
    }
}
