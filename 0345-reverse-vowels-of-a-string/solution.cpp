class Solution {
public:
    string reverseVowels(string str) {

        int n = str.size();
        int i = 0, j = n - 1;
        while (i < n && j >= i) {
            char ch = str[i];
            char bh = str[j];
            if ((ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                 ch == 'u') ||
                (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' ||
                 ch == 'U')) {
                if ((bh == 'a' || bh == 'e' || bh == 'i' || bh == 'o' ||
                     bh == 'u') ||
                    (bh == 'A' || bh == 'E' || bh == 'I' || bh == 'O' ||
                     bh == 'U')) {
                    swap(str[i], str[j]);
                    i++;
                    j--;
                } else {
                    j--;
                }
            } else {
                if ((bh == 'a' || bh == 'e' || bh == 'i' || bh == 'o' ||
                     bh == 'u') ||
                    (bh == 'A' || bh == 'E' || bh == 'I' || bh == 'O' ||
                     bh == 'U')) {

                    i++;

                } else {
                    j--;
                    i++;
                }
            }
        }
        return str;
    }
};
