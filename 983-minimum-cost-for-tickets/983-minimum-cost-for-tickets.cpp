class Solution {
public:
    bool check(int x,int validUpto){
        if(x < validUpto){
            return 0;
        }
        return 1;
    }
    int recurr(int i,int validUpto,vector<int> &days,vector<int> &costs,vector<vector<int>> &dp){
        if(i >= days.size()){
            return 0;
        }
        if(dp[i][validUpto] != -1) return dp[i][validUpto];
        int ans1 = INT_MAX;
        int ans2 = INT_MAX;
        int ans3 = INT_MAX;
        //cout << days[i] <<" "<< validUpto <<"\n";
        
        if(check(days[i],validUpto))
            ans1 = costs[0] + recurr(i+1,days[i] + 1,days,costs,dp);
        else
            ans1 = recurr(i+1,validUpto,days,costs,dp);
        
        if(check(days[i],validUpto))
            ans2 = costs[1] + recurr(i+1,days[i] + 7,days,costs,dp);
        else
            ans2 = recurr(i+1,validUpto,days,costs,dp);
        
        if(check(days[i],validUpto)){
             ans3 = costs[2] + recurr(i+1,days[i] + 30,days,costs,dp);   
        }
        else
            ans3 = recurr(i+1,validUpto,days,costs,dp);   
        
        
        return dp[i][validUpto] = min({ans1,ans2,ans3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(days.size()+1,vector<int>(400,-1));
           return recurr(0,0,days,costs,dp);
    }
};