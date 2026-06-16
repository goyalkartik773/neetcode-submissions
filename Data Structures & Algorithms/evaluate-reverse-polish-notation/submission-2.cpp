class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &ele:tokens){
            if(ele=="*"){
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();
                st.push(v1*v2);
            }
            else if(ele=="+"){
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();
                st.push(v1+v2);
            }
            else if(ele=="-"){
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();
                st.push(v2-v1);
            }
            else if(ele=="/"){
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();
                st.push(v2/v1);
            }
            else{
                int val = stoi(ele);
                st.push(val);
            }
        }
        return st.top();
    }
};
