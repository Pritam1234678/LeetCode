class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> s;
        unordered_map<int, int> m;
        for (int ele : arr) {
            m[ele]++;
        }
        for (auto& ele : m) {
            s.insert(ele.second);
        }
        if (m.size() == s.size())
            return true;
        else
            return false;
    }
};
