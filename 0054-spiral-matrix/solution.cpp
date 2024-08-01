class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {

        int m = arr.size();
        int n = arr[0].size();
        int maxr = m - 1;
        int maxc = n - 1;
        int minr = 0;
        int minc = 0;
        vector<int> v;
        while (maxr >= minr && maxc >= minc) {
            for (int i = minc; i <= maxc; i++) {
                v.push_back(arr[minr][i]);
            }
            minr++;
            if (minr > maxr || minc > maxc)
                break;
            for (int i = minr; i <= maxr; i++) {

                v.push_back(arr[i][maxc]);
            }
            maxc--;
            if (minr > maxr || minc > maxc)
                break;
            for (int i = maxc; i >= minc; i--) {

                v.push_back(arr[maxr][i]);
            }
            maxr--;
            if (minr > maxr || minc > maxc)
                break;
            for (int i = maxr; i >= minr; i--) {

                v.push_back(arr[i][minc]);
            }
            minc++;
        }
        return v;
    }
};
