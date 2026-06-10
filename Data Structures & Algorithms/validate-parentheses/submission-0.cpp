class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                if(st.size()==0) return false;
                if(st.top()!='(') return false;
                st.pop();
            }
            else if(s[i]=='}'){
               if(st.size()==0) return false;
               if(st.top()!='{') return false;
                st.pop();
            }
            else if(s[i]==']'){
                if(st.size()==0) return false;
                if(st.top()!='[') return false;
                st.pop();
            }
            else
            st.push(s[i]);
        }
        return true;
    }
};
