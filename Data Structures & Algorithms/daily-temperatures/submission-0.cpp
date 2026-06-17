class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n,0);
    stack<int> st;
    st.push(n-1);
    result[n-1] = 0;
    for(int i=n-2;i>=0;i--){
        while(st.size()!=0 && arr[st.top()] <= arr[i])
        st.pop(); // this cannot be the answer jo ith index ka answer nahi hai wo i - 1 ka bhi nahi ho skta
        if(st.size()!=0)
        result[i] = st.top()-i;
        st.push(i);
    }
    return result;
    }
};