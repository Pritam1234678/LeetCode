
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0, read = 0;

        while (read < n) {
            char currentChar = chars[read];
            int count = 0;

            // Count occurrences of the current character
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }

            // Write the character
            chars[write++] = currentChar;

            // Write the count if greater than 1
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};
