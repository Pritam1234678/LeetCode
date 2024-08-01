class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int p = x;
        int r = 0;

        while (x != 0) {
            int digit = x % 10;

            
            if (r > (INT_MAX - digit) / 10) {
                return false; 
            }

            r = r * 10 + digit;
            x /= 10;
        }

        if (r == p) {
            return true;
        } else {
            return false;
        }
    }
};

