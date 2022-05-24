class Solution {
public:
    bool isSubsequence(unordered_map<char,vector<int>> &mp,string t){
        int req = 0;
        
        for(int i=0;i<t.length();++i){
            auto itr = lower_bound(mp[t[i]].begin(),mp[t[i]].end(),req);
            if(itr == mp[t[i]].end()) return false;
            
            req = *itr+1;
        }
        
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<s.length();++i){
            mp[s[i]].push_back(i);
        }
        int ans = 0;
        for(auto &t : words){
            ans += isSubsequence(mp,t);
        }
        return ans;   
    }
};