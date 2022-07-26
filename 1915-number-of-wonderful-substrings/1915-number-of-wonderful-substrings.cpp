class Solution {
public:
    long long wonderfulSubstrings(string word) {
       unordered_map<int,int> hash_map;
        long long ans = 0;
        int hash  = 0;
        for(int i=0;i<word.length();++i){
            hash_map[hash]++;
            hash ^= (1 << (word[i]-'a'));
            ans += (hash_map[hash]);
            
            for(char j='a';j<='j';++j){
                ans += hash_map[hash^(1<<(j-'a'))];
            }
            
        }
        return ans;
        
    }
};