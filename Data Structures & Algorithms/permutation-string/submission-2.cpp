class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp1;
        for(auto &ele:s1){
            mp1[ele]++;
        } 
        int n = s2.length();
        int i = 0;
        int j = 0;
        while(j<n && i<n){
            if(mp1.find(s2[i])!=mp1.end()){
                j = i;
                unordered_map<char,int> temp = mp1;
                while(temp.size()!=0 && temp.find(s2[j])!=temp.end()){
                temp[s2[j]]--;
                if(temp[s2[j]]==0) temp.erase(s2[j]);
                j++;
                }
                if(temp.size()==0) return true;
            }
            i++;
        }
        return false;
    }
};
