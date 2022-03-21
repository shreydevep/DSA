class Solution {
public:
    static bool compare(vector<int> &v1,vector<int> &v2){
      
        if(v1[1] < v2[1]) return 1;
        return 0;
    }
    int recurr(int i,int last,vector<vector<int>> &pairs,vector<int> &dp){
        if(i >= pairs.size()){
            return 0;
        }
        
        if(dp[i] != -1) return dp[i];
        
        int inclde = 0;
        if(pairs[i][0] > last){
            inclde = 1 + recurr(i+1,pairs[i][1],pairs,dp);
        }
        int skip =0;
        skip = recurr(i+1,last,pairs,dp);
        
        return dp[i] = max(inclde,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        
        vector<int> dp(pairs.size()+1,-1);
        
        return recurr(0,-1001,pairs,dp);
        
    }
};