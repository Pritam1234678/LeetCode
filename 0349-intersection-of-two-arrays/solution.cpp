class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i =0,j=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>p;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]==nums2[j]){
                int f = nums1[i];
                p.push_back(nums2[j]);
                while (i < nums1.size() && nums1[i] == f) i++;
                while (j < nums2.size() && nums2[j] == f) j++;

            }else if(nums1[i]>nums2[j]) j++;
            else i++;
        }
        return p;
    }
};
