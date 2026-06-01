// class Solution {
//     public int[] corpFlightBookings(int[][] b, int n) {
//         int ans[]= new int[n];
//         for(int i=0; i<b.length; i++){
//             int start = b[i][0];
//             int last= b[i][1];
//             int seats= b[i][2];
//             for(int j=start-1;j<=last-1;j++){
//                 ans[j]+=seats;
//             }
//         }
//         return ans;
//     }
// }  ---> Bruteforce

class Solution {
    public int[] corpFlightBookings(int[][] b, int n) {
        int ans[]= new int[n];
        for(int i=0; i<b.length; i++){
            int start = b[i][0];
            int last= b[i][1];
            int seats= b[i][2];
            ans[start-1]+=seats;
            if(last<n)ans[last-1+1]-=seats;
        }
        for(int i=1;i<ans.length;i++){
            ans[i]+=ans[i-1];
        }
        return ans;
    }
} 
