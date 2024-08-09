class Solution {
public:
    int search(vector<int>& v, int t) {

        int i = 0;
        int j = v.size() - 1;
        while (i <= j) {
            int k = i+(j-i)/2;
            if (v.at(k) == t)
                return k;
            else if (v.at(k) > t)
                j = k - 1;
            else
                i = k + 1;
        }
         return -1;
    }
   
};
