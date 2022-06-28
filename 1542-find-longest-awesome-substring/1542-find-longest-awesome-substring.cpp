class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int,int> hash;
        int prev = 0;
        int ans = 0;
        hash[0] = 0;
        for(int j=1;j<=s.length();++j){
            auto w = s[j-1];
            int val = (w - '0');
            prev ^= (1 << val);
            if(hash.find(prev) == hash.end()){
                hash[prev] = j;
            }
            
            ans = max((j - hash[prev]),ans);
            
            for(int i=0;i<10;++i){
                if(hash.find(prev^(1<<i)) == hash.end()) continue;
                ans = max(ans,(j-hash[prev^(1<<i)]));
            }
            
        }
        return ans;
    }
};