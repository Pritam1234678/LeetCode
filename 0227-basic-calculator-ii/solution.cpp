
class Solution {
public:
    int pr(char op) {
        if (op == '+' || op == '-') {
            return 1;
        } else if (op == '*' || op == '/') {
            return 2;
        }
        return 0;
    }

    int solve(int val1, int val2, char ch) {
        if (ch == '+')
            return val1 + val2;
        else if (ch == '-')
            return val1 - val2;
        else if (ch == '*')
            return val1 * val2;
        else
            return val1 / val2;
    }

    int calculate(string str) {
        stack<int> val;
        stack<char> op;
        int i = 0;

        while (i < str.size()) {
            if (isdigit(str[i])) {
                int num = 0;
                while (i < str.size() && isdigit(str[i])) {
                    num = num * 10 + (str[i] - '0');
                    i++;
                }
                val.push(num);
                i--; // Adjust for the outer loop increment
            } else if (str[i] == ' ') {
                // Ignore whitespace
            } else {
                if (op.empty() || pr(op.top()) < pr(str[i])) {
                    op.push(str[i]);
                } else {
                    while (!op.empty() && pr(op.top()) >= pr(str[i])) {
                        char ch = op.top();
                        op.pop();
                        int v2 = val.top();
                        val.pop();
                        int v1 = val.top();
                        val.pop();
                        val.push(solve(v1, v2, ch));
                    }
                    op.push(str[i]);
                }
            }
            i++;
        }

        while (!op.empty()) {
            char ch = op.top();
            op.pop();
            int v2 = val.top();
            val.pop();
            int v1 = val.top();
            val.pop();
            val.push(solve(v1, v2, ch));
        }

        return val.top();
    }
};

