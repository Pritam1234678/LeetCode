// class Solution {
//     public int bestClosingTime(String customers) {
//         int n = customers.length();
//         char[] arr = customers.toCharArray();
//         int[] ans = new int[n + 1];

//         int Ycc = 0;
//         for (int k = 0; k < n; k++) {
//             if (arr[k] == 'Y')
//                 Ycc++;
//         }

//         ans[0] = Ycc;

//         for (int i = 1; i <= n; i++) {
//             int Yc = 0, Nc = 0;

//             for (int j = i; j < n; j++) {
//                 if (arr[j] == 'Y')
//                     Yc++;
//             }

//             for (int k = 0; k < i; k++) {
//                 if (arr[k] == 'N')
//                     Nc++;
//             }

//             ans[i] = Yc + Nc;
//         }

//         int min = ans[0];
//         int idx = 0;

//         for (int i = 1; i < ans.length; i++) {
//             if (ans[i] < min) {
//                 min = ans[i];
//                 idx = i;
//             }
//         }

//         return idx;
//     }
// }
class Solution {
    public int bestClosingTime(String customers) {

        int n = customers.length();

        int[] prefixN = new int[n + 1];
        int[] suffixY = new int[n + 1];

        
        for (int i = 1; i <= n; i++) {

            if (customers.charAt(i - 1) == 'N') {
                prefixN[i] = prefixN[i - 1] + 1;
            } else {
                prefixN[i] = prefixN[i - 1];
            }

        }

     
        for (int i = n - 1; i >= 0; i--) {

            if (customers.charAt(i) == 'Y') {
                suffixY[i] = suffixY[i + 1] + 1;
            } else {
                suffixY[i] = suffixY[i + 1];
            }

        }

        int minPenalty = Integer.MAX_VALUE;
        int answer = 0;

       
        for (int i = 0; i <= n; i++) {

            int penalty = prefixN[i] + suffixY[i];

            if (penalty < minPenalty) {
                minPenalty = penalty;
                answer = i;
            }

        }

        return answer;
    }
}
