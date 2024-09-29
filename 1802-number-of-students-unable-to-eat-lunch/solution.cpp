class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& s) {
        int n = students.size();
        queue<int>q;
        for (int i = 0; i < n; i++) {
            q.push(students[i]);
        }
        int i = 0, c = 0;
        while (q.size() > 0 && c != n) {
            if (q.front() == s[i]) {
                c = 0;
                i++;
                q.pop();
            } else {
                q.push(q.front());
                q.pop();
                c++;
            }
        }
        return q.size();
    }
};
