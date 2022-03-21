const int mod = 1e9 + 7;
class Solution {
public:
   
    int dp[100001][2][3];
    long long recurr(int day,int &n,int Abs,int late){
        if(Abs == 2 || late == 3) return 0;
        if(day == 0){
            return 1;
        }
        
        if(dp[day][Abs][late] != -1) return dp[day][Abs][late];
        
        int ans = 0;
        ans = recurr(day-1,n,Abs,0) % mod;
        ans = (ans % mod + recurr(day-1,n,Abs+1,0)) % mod;
        ans = (ans % mod + recurr(day-1,n,Abs,late+1)) % mod;
        
        return dp[day][Abs][late] = ans;
         
       
        
        
    }
    int checkRecord(int n) {
        
        for(int i=0;i<100001;++i){
            for(int j=0;j<2;++j){
                for(int k=0;k<3;++k){
                    dp[i][j][k] = -1;
                }
            }
        }
        return recurr(n,n,0,0);
    }
    
};

