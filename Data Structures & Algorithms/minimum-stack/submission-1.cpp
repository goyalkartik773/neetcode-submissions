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
        stack<int> temp;
        temp.push(st.top());
        st.pop();
        while(st.size()!=0 && temp.top()>=st.top()){
            temp.push(st.top());
            st.pop();
        }
        int ans = temp.top();
        while(temp.size()!=0){
            st.push(temp.top());
            temp.pop();
        }
        return ans;
    }
};
