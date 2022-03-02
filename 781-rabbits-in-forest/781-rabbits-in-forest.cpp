class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        int ans = 0;
        for(auto rabbit : answers){
            mp[rabbit]++;
            if(rabbit + 1 == mp[rabbit]) {
                ans += (mp[rabbit]);
                mp[rabbit] = 0;
            }
            
            
        }
        
        for(auto rabbit : mp){
            if(rabbit.second)
                ans += (rabbit.first + 1);
        }
        return ans;
    }
};