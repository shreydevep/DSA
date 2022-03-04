class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // i -> range reach
        long long dp[stations.size() + 1];
        for(int i=0;i<=stations.size();++i) dp[i] = startFuel;
        
       
        for(int i=0;i<stations.size();++i){
            for(int refuel=i;refuel>=0;--refuel){
                if(dp[refuel] < stations[i][0]) {
                    continue;
                }
                
                dp[refuel + 1] = max(dp[refuel] + stations[i][1],dp[refuel + 1]);
            }
        }
        
        for(int i=0;i<=stations.size();++i){
            if(dp[i] >= target) return i;
        }
        return -1;
        
        
    }
};