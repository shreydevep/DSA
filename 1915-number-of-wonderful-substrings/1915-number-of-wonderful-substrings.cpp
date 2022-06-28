class Solution {
public:
    
    long long wonderfulSubstrings(string word) {
        vector<int> hash(1024,0);
        int prev = 0;
        long long ans = 0;
        hash[0] = 1;
        
        for(auto &w : word){
            int val = (w - 'a');
            prev ^= (1 << val);
            ans += hash[prev];
            for(int i=0;i<10;++i){
                ans += (hash[prev^(1 << i)]);
            }
            
            hash[prev]++;
            
        }
        return ans;
    }
};

    
    