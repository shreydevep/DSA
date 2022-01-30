class Solution {
public:
    vector <int> dx = {1,0};
    vector <int> dy = {0,1};
    int dp[101][101];
    int ways(int i,int j,int m,int n,vector<vector<int>>& obstacleGrid){
        //cout << dp[i][j] <<" "<<i <<" "<< j <<"\n";
        if(i== m-1 && j == n-1 && obstacleGrid[i][j]) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int temp = 0;
        for(int mv=0;mv<2;++mv){
            if(i+dx[mv] < 0 || i+dx[mv] >= m || j+dy[mv] < 0 || j+dy[mv] >= n || obstacleGrid[i+dx[mv]][j+dy[mv]] == 1)
                continue;
            temp += ((ways(i+dx[mv],j+dy[mv],m,n,obstacleGrid)));
        }
        return dp[i][j] = temp;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for(int i=0;i<obstacleGrid.size();++i){
            for(int j=0;j<obstacleGrid[0].size();++j){
                dp[i][j] = -1;
            }
        }
        if(obstacleGrid[0][0]) return 0;
        return ways(0,0,obstacleGrid.size(),obstacleGrid[0].size(),obstacleGrid);
    }
};