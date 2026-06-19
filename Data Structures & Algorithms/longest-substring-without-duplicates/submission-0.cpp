class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<char,int> mp;
        while(j<n){
            char ch = s[j];
            if(mp.find(ch)==mp.end()){
                mp[ch]++;
                j++;
            }
            else{
                ans = max(ans,(int)mp.size());
                while(mp.find(ch)!=mp.end()){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
        }
        ans = max(ans,(int)mp.size());
        return ans;
    }
};
