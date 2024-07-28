class Solution {
public:
    void sortColors(vector<int>& v) {
        
  int n = v.size();
  int lo = 0;
  int mid = 0;
  int hi = n - 1;
  while (mid <= hi) {
    if (v[mid] == 2) {
      swap(v[mid], v[hi]);
      hi--;
    } else if (v[mid] == 0) {
      swap(v[mid], v[lo]);
      mid++;
      lo++;
    } else {
      mid++;
    }
  }
}
        
    
};
