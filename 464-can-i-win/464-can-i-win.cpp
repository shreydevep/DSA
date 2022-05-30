class Solution {
public:
    vector<int> dp;
    bool flag = false;
    bool ans;
    bool dfs(int curr,int hash,int &desiredTotal,int &maxBit){
        //cout << curr <<" "<< chance <<"\n";
        
        if(dp[hash] != -1) return dp[hash];
        
        for(int i=0;i<maxBit;++i){
            
            if((hash & (1 << i)) == 0){
                if((curr+i+1 >= desiredTotal) or dfs(curr+i+1,(hash | (1 << i)),desiredTotal,maxBit) == false) return dp[hash] = true;
            }
        }
        return dp[hash] = false;
        
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal == 0){
            return true;
        }
        if((maxChoosableInteger*(maxChoosableInteger+1))/2 < desiredTotal) return false;
        
        dp.resize((1 << (maxChoosableInteger+1)),-1);
        return dfs(0,0,desiredTotal,maxChoosableInteger);
    }
};

