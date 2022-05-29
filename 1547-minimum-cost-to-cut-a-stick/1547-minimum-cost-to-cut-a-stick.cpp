class Solution {
public:
    //map<pair<pair<int,int>,pair<int,int>>,int> dp;
    
    int mcm(int i,int j,int cutMinInd,int cutMaxInd,vector<int> &cuts,vector<vector<int>> &dp){
        
        if(cutMinInd > cutMaxInd) return 0;
        if(i >= j) return 1e8;
        //if(dp.find({{i,j},{cutMinInd,cutMaxInd}}) != dp.end()) return dp[{{i,j},{cutMinInd,cutMaxInd}}];
        if(dp[cutMinInd][cutMaxInd] != -1) return dp[cutMinInd][cutMaxInd]; 
        
        int temp = 1e8;
        for(int k=cutMinInd;k<=cutMaxInd;++k){
            int val = mcm(i,cuts[k],cutMinInd,k-1,cuts,dp) + mcm(cuts[k],j,k+1,cutMaxInd,cuts,dp) + (j-i);
             temp = min(temp,val);
        }
        //return dp[{{i,j},{cutMinInd,cutMaxInd}}] = temp;
        return dp[cutMinInd][cutMaxInd] = temp;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        
        return mcm(0,n,0,cuts.size()-1,cuts,dp);
    }
};