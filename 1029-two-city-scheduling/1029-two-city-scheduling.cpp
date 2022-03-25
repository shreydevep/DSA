class Solution {
public:
    int recurr(int i,int city1,int city2,vector<vector<int>> &costs,vector<vector<vector<int>>> &dp){
        if(i == costs.size() ||  (city1 + city2 == costs.size())){
            return 0;
        }
        if(dp[i][city1][city2] != -1) return dp[i][city1][city2];
        if(city1 < ((costs.size())/2) && city2 < ((costs.size())/2)){
            return dp[i][city1][city2] = min(recurr(i+1,city1+1,city2,costs,dp)+costs[i][0],recurr(i+1,city1,city2+1,costs,dp)+costs[i][1]);
        }
        else if(city1 < (costs.size())/2){
            return dp[i][city1][city2] = recurr(i+1,city1+1,city2,costs,dp) + costs[i][0];
        }
        else if(city2 < (costs.size())/2){
            return dp[i][city1][city2] = recurr(i+1,city1,city2+1,costs,dp) + costs[i][1];
        }
        else{
            return 0;
        }
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        vector<vector<vector<int>>> dp(costs.size()+1,vector<vector<int>>(costs.size(),vector<int>(costs.size(),-1)));
        
        return recurr(0,0,0,costs,dp);
        
    }
};