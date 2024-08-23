class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int maxr = n - 1;
        int maxc = n - 1;
        int minr = 0;
        int minc = 0;
        int c = 1;
        while (maxr >= minr && maxc >= minc) {
            for (int i = minc; i <= maxc; i++) {
                v[minr][i] = c;
                c++;
            }
            minr++;
            if (minr > maxr || minc > maxc)
                break;
            for (int i = minr; i <= maxr; i++) {
                v[i][maxc] = c;
                c++;
            }
            maxc--;
            if (minr > maxr || minc > maxc)
                break;
            for (int i = maxc; i >= minc; i--) {
                v[maxr][i] = c;
                c++;
            }
            maxr--;
            if (minr > maxr || minc > maxc)
                break;
            for (int i = maxr; i >= minr; i--) {
                v[i][minc] = c;
                c++;
            }
            minc++;
        }
        return v;
    }
};
