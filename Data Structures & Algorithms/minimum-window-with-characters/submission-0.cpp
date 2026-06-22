class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (auto& ch : t) {
            mp[ch]++;
        }
        int i = 0;
        int j = 0;
        int n = s.length();
        int count = t.length();
        int start = 0;
        int wSize = INT_MAX;
        while (j < n) {
            if (mp[s[j]] > 0)
            count -= 1;
            mp[s[j]]--;
            while (count == 0) {
                if (j - i + 1 < wSize) {
                    wSize = j - i + 1;
                    start = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                count += 1;
                i++;
            }
             j++;
        }
        if(wSize==INT_MAX) return "";
        return s.substr(start, wSize);
    }
};