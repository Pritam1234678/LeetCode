bool IsDigit(char a)
{
    string digits = {"1234567890"};
    for(int i = 0; i < digits.length(); i++)
        if(a == digits[i]) return true;
    return false;
}

class Solution {
public:
    string clearDigits(string s) 
    {
        int l = s.length();
        for(int i = 0; i < l; i++)
        {
            if(IsDigit(s[i]))
            {
                if(i != 0) {s.erase(i-1,2); l -=2; i-=2;}
                else {s.erase(i,2); l--; i--;}
            }
        }
        return s;
    }
};
