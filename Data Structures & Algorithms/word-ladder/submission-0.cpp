class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        for(auto &ele:wordList){
            mp[ele]++;
        }
        unordered_set<string> st;
        queue<string> q;
        q.push(beginWord);
        st.insert(beginWord);
        int count = 1;
        while(q.size()!=0){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                string temp = q.front();
                q.pop();
                if(temp == endWord) return count;
                for(int i=0;i<temp.length();i++){
                    char c = temp[i];
                    for(char ch='a';ch<='z';ch++){
                        temp[i] = ch;
                        if(st.find(temp)==st.end() && mp.find(temp)!=mp.end()){
                            q.push(temp);
                            st.insert(temp);
                        }
                        temp[i] = c;

                    }
                }
            }
            count += 1;
        }
        return 0;
    }
};
