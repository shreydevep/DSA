class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx = 0;
        for(auto x : accounts){
            int res = 0;
            for(auto y : x){
                res += y;
            }
            mx = max(mx,res);
        }
        return mx;
    }
};