class MinStack {
public:
    stack<long long> st;
    long long min;
    MinStack() { min = LLONG_MAX; }

    void push(long long val) {
        if (st.empty()) {
            st.push(val);
            min = val;
        } else if (val < min) {
            st.push(2 * val - min);
            min = val;
        } else {
            st.push(val);
        }
    }

    void pop() {
        if (st.top() < min) {
            min = 2 * min - st.top();
        }
        st.pop();
    }

    long long top() {
        if (st.top() < min) {
            return min;
        }
        return st.top();
    }

    long long getMin() {
        return min;
    }
};

