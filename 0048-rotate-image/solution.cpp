class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n =arr.size();
         for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {

      swap(arr[i][j], arr[j][i]);
    }
  }

  for (int i = 0; i < n; i++) {
    int q = n - 1;
    int p = 0;
    while (p <= q) {
      swap(arr[i][p], arr[i][q]);
      p++;
      q--;
    }
  }
    }
};
