class Solution {
public:
    string removeDuplicates(string s) {
 string str = "";
    int i = 0;
    while (i < s.size())
    {
        if (str.empty() || s[i] != str.back())
        {
            str.push_back(s[i]);
        }
        else
        {
            str.pop_back();
        }
        i++;
    }
    return str;
    }
};
