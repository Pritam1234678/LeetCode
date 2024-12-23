class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        for (auto& i : arr1) {
            mp[i]++;
        }
        vector<int> ans;
        for (auto& i : arr2) {
            while (mp[i]--)
                ans.push_back(i);
        }
        for (auto [i, j] : mp) {
            while (j-- > 0)
                ans.push_back(i);
        }
        return ans;
    }
};
