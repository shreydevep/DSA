class Solution {
public:
    //map<pair<pair<int,int>,pair<int,int>>,int> dp;
    map<pair<int,int>,int> dp;
    int mcm(int i,int j,int cutMinInd,int cutMaxInd,vector<int> &cuts){
        
        if(cutMinInd > cutMaxInd) return 0;
        if(i >= j) return 1e8;
        //if(dp.find({{i,j},{cutMinInd,cutMaxInd}}) != dp.end()) return dp[{{i,j},{cutMinInd,cutMaxInd}}];
        if(dp.find({cutMinInd,cutMaxInd}) != dp.end()) return dp[{cutMinInd,cutMaxInd}]; 
        int temp = 1e8;
        for(int k=cutMinInd;k<=cutMaxInd;++k){
            int val = mcm(i,cuts[k],cutMinInd,k-1,cuts) + mcm(cuts[k],j,k+1,cutMaxInd,cuts) + (j-i);
             temp = min(temp,val);
        }
        //return dp[{{i,j},{cutMinInd,cutMaxInd}}] = temp;
        return dp[{cutMinInd,cutMaxInd}] = temp;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        
        
        return mcm(0,n,0,cuts.size()-1,cuts);
    }
};