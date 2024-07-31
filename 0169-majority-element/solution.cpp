class Solution {
public:
    int majorityElement(vector<int>& b) {
       
        sort(b.begin(),b.end());
        int a=b.size();
        return b.at(a/2);
       

    }
};
