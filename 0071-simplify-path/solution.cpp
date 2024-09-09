class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;      // Stack to store the directory names
        stringstream ss(path); // String stream to split the path by '/'
        string temp;

        // Split the path by '/'
        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".")
                continue; // Ignore empty parts and current directory symbol
            if (temp == "..") {
                if (!st.empty())
                    st.pop(); // Go up one directory if possible
            } else {
                st.push(temp); // Push the directory name onto the stack
            }
        }

        string res;
        // Construct the result path from the stack
        while (!st.empty()) {
            res = "/" + st.top() + res; // Prepend each directory to the result
            st.pop();
        }

        return res.empty() ? "/" : res; // Return root if result is empty
    }
};

