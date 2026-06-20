class Solution {
public:
    int characterReplacement(string s, int k) {
        // want substring jisme ek hi character repeat hoo
        // i can replace k characters
        // key concept used no of replacements = maxfreq of char in window - windows size
        int n = s.length();
        int i = 0;
        int j = 0;
        unordered_map<char,int> mp;
        int freq = 0;
        int repl = 0;
        int ans = 0;
        auto f = [&]()->int{
            int x = 0;
            for(auto &ele:mp){
                x = max(x,ele.second);
            }
            return x;
        };
        while(j<n){
            mp[s[j]]++;
            freq = max(freq,mp[s[j]]);
            repl = (j-i+1) - freq;
            while(repl>k){
                // window collapse
                mp[s[i]]--;
                if(mp[s[i]]==0)
                mp.erase(s[i]);
                i++;
                freq = f();
                repl = (j-i+1) - freq;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
