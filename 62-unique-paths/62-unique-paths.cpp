class Solution {
public:
    vector <int> dx = {1,0};
    vector <int> dy = {0,1};
    int dp[101][101];
    int ways(int i,int j,int m,int n){
        //cout << dp[i][j] <<" "<<i <<" "<< j <<"\n";
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int temp = 0;
        for(int mv=0;mv<2;++mv){
            if(i+dx[mv] < 0 || i+dx[mv] >= m || j+dy[mv] < 0 || j+dy[mv] >= n)
                continue;
            temp += ((ways(i+dx[mv],j+dy[mv],m,n)));
        }
        return dp[i][j] = temp;
    }
    int uniquePaths(int m, int n) {
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                dp[i][j] = -1;
            }
        }
        return ways(0,0,m,n);
    }
};