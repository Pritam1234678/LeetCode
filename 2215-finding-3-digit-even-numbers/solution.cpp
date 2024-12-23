class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        int n = arr.size();
        vector<int> v;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        for (int i = 100; i < 999; i += 2) {
            int x = i;
            int a = x % 10;
            x /= 10;
            int b = x % 10;
            x /= 10;
            int c = x;

            if (mp.find(a) != mp.end()) {
                mp[a]--;
                if (mp[a] == 0)
                    mp.erase(a);
                if (mp.find(b) != mp.end()) {
                    mp[b]--;
                    if (mp[b] == 0)
                        mp.erase(b);
                    if (mp.find(c) != mp.end())
                        v.push_back(i);
                    mp[b]++;
                }
                mp[a]++;
            }
        }
        return v;
    }
    
};
