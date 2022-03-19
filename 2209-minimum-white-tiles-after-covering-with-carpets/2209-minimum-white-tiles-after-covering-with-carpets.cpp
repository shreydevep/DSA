class Solution {
public:
    int getVal(char ch){
        if(ch == '0') return 0;
        else return 1;
    }
    int n;
    vector<int> suffix_white;
    int recurr(int i,int rem,int numCarpets,int &carpetLen,string &floor,vector<vector<int>> &dp){
        
        if(i >= (floor.length()) || numCarpets == 0) return rem;
        if(dp[i][numCarpets] != -1) return dp[i][numCarpets];
        return dp[i][numCarpets] = min(recurr(min(i+carpetLen,n),rem - (suffix_white[i] - suffix_white[min(i+carpetLen,n)]),numCarpets-1,carpetLen,floor,dp),getVal(floor[i]) + recurr(i+1,rem-getVal(floor[i]),numCarpets,carpetLen,floor,dp));
        
    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        
        if((numCarpets*carpetLen) >= floor.length()) return 0;
        
        suffix_white.resize(floor.length() + 1);
        suffix_white[floor.length()] = 0;
        n = floor.length();
        for(int i=floor.length()-1;i>=0;--i){
            suffix_white[i] = (suffix_white[i+1] + getVal(floor[i]));
        }
        
        vector<vector<int>> dp(floor.length()+1,vector<int>(numCarpets+1,-1));
         return recurr(0,suffix_white[0],numCarpets,carpetLen,floor,dp);
            
        
    }
};