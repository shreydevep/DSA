class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,char> mp;
        
        int i=0;
        int j=0;
        int ans = 0;
        while(j < s.length() && i<=j){
            
            while(mp.size() > 0 && mp.find(s[j]) != mp.end() && i < j){
                mp[s[i]]--;
                if(mp[s[i]] <= 0){
                    mp.erase(mp.find(s[i]));
                }
                i++;
            }
            
            if(mp.find(s[j]) == mp.end()){
                mp[s[j]]++;
                ans = max(ans,(int)mp.size());
                j++;
                continue;
            }
        }
        ans = max(ans,(int)mp.size());
        return ans;
    }
};