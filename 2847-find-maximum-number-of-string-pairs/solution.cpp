class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        unordered_set<string> s;
int count =0;
        for (int i = 0; i < n; i++) {
            string str = words[i];
            reverse(str.begin(), str.end());
            if (s.find(str) != s.end())
                count++;
            else
                s.insert(words[i]);
        }

        return count;
    }
};
