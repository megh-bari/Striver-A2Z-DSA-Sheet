class MinStack {
    private:
        std::stack<long long> st;
       long long mini;
    
    public:
        MinStack() {}
    
        void push(int val) {
            if (st.empty()) {
                mini = val;
                st.push(val);
            } else if (val > mini) {
                st.push(val);
            } else {
                st.push(2LL * val - mini);
                mini = val;
            }
        }
        long long x;
        void pop() {
            if (st.empty())
                return;
            x = st.top();
            st.pop();
            if (x < mini) {
                mini = 2 * mini - x;
            }
        }
    
        int top() {
            if (st.empty())
                return -1;
            else {
                x = st.top();
                if (mini < x)
                    return x;
                else
                    return mini;
            }
        }
    
        int getMin() { return mini; }
    };
    