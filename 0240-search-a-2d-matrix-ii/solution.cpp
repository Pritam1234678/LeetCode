class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int row = m.size();
        int col = m[0].size();
        int i = 0;
        int j = col - 1;
        while (i < row && j >= 0) {
            if (m[i][j] == target)
                return true;
            else if(m[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};
