class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            swap(s.at(i),s.at(j));
            i++;
            j--;
        }
        
    }
};
