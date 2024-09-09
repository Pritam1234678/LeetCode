class Solution {
public:
    int solve(int val1, int val2, char ch) {
        if (ch == '+')
            return val1 + val2;
        else if (ch == '-')
            return val1 - val2;
        else if (ch == '*')
            return val1 * val2;
        else if (ch == '%')
            return val1 % val2;
        else if (ch == '^')
            return pow(val1, val2);
        else
            return val1 / val2;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> val;

        for (const string& token : tokens) {
            if (isdigit(token.back()) || (token.size() > 1 && token[0] == '-')) {
                val.push(stoi(token));
            } else {
                int val2 = val.top();
                val.pop();
                int val1 = val.top();
                val.pop();
                int result = solve(val1, val2, token[0]);
                val.push(result);
            }
        }
        return val.top();
    }
};

