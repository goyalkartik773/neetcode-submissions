class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(auto &ele:s1){
            mp1[ele]++;
        } 
        int n = s2.length();
        int i = 0;
        int j = 0;
        auto f = [&]()->bool{
            for(auto &ele:mp1){
                if(mp2[ele.first]!=ele.second) return false;
            }
            return true;
        };
        while(j<n){
            while(mp1.find(s2[j])!=mp1.end() && mp1[s2[j]] < mp2[s2[j]]){
                mp2[s2[j]]--;
                if(mp2[s2[j]]==0) mp2.erase(s2[j]);
                i++;
            }
            if(f()) return true;
            mp2[s2[j]]++;
            j++;
        }
        return false;
    }
};
