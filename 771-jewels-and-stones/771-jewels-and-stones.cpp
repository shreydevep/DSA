class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> mp;
        for(auto x : jewels){
            mp.insert(x);
        }
         int ans = 0;
        for(auto x : stones){
            if(mp.find(x) != mp.end()) ans++;
        }
        
       
        return ans;
        
    }
};