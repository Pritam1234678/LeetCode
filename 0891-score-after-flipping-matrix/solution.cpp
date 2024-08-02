class Solution {
public:
    int matrixScore(vector<vector<int>>& v) {
        
          int row = v.size();
    int col = v[0].size();

    
    for (int i = 0; i < row; i++) {
        if (v[i][0] == 0) {
            for (int j = 0; j < col; j++) {
               if (v[i][j] == 0) {
                    v[i][j] = 1; 
                } else {
                    v[i][j] = 0; 
                }
            }
        }
    }

    
    for (int j = 0; j < col; j++) {
        int noz = 0, noo = 0;
        for (int i = 0; i < row; i++) {
            if (v[i][j] == 0) {
                noz++;
            } else {
                noo++;
            }
        }

        if (noz > noo) {
            for (int i = 0; i < row; i++) {
               if (v[i][j] == 0) {
                    v[i][j] = 1; 
                } else {
                    v[i][j] = 0; 
                }
            }
        }
    }

    
    int sum = 0;
    for (int i = 0; i < row; i++) {
        int x = 1;
        for (int j = col - 1; j >= 0; j--) {
            sum += v[i][j] * x;
            x *= 2;
        }
    }
    return sum;
    }
};
