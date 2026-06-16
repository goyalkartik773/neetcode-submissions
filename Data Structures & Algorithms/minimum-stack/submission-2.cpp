class MinStack {
public:
    stack<int> st;
    MinStack() {   
    }
    void push(int val) {
        st.push(val);
    }
    void pop() {
        st.pop();
    }
    int top() {
        return st.top();
    }
    int getMin() {
        stack<int> temp = st;
        int ans = INT_MAX;
        while(temp.size()!=0){
            ans = min(ans,temp.top());
            temp.pop();
        }
        return ans;
    }
};
