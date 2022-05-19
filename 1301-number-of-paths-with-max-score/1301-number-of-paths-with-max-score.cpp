const int mod = 1e9 + 7;
class Solution {
public:
    vector<int> recurr(int i,int j,vector<string> & board,vector<vector<vector<int>>> &dp){
        
        if(i < 0 || j < 0 || board[i][j] == 'X'){
            vector<int> temp = {0,0};
            return temp;
        } 
        
        if(board[i][j] == 'E'){
            
            vector<int> temp(2,0);
            temp[1] = 1;
            return temp;
        }
        if(dp[i][j][0] != -1 && dp[i][j][1] != -1){
            return dp[i][j];
        }
        auto up = recurr(i-1,j,board,dp);
        auto left = recurr(i,j-1,board,dp);
        auto upLeft = recurr(i-1,j-1,board,dp);
        
        
        
        int mxCurr = max(left[0],max(upLeft[0],up[0]));
        
        int paths = 0;
        if(left[0] == mxCurr) paths = (paths % mod + left[1] % mod)%mod;
        if(up[0] == mxCurr) paths = (paths % mod + up[1] % mod)%mod;
        if(upLeft[0] == mxCurr) paths = (paths % mod + upLeft[1] % mod)%mod;
        
        int val = ((board[i][j] != 'X') && (board[i][j] != 'S') && (board[i][j] != 'E'))?(board[i][j] - '0'):0;
        
        if(paths == 0) val = 0;
        return dp[i][j]={mxCurr + val,paths};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        vector<vector<vector<int>>> dp(board.size()+1,vector<vector<int>>(board[0].size()+1,vector<int>(2,-1)));
        int startX = board.size()-1;
        int startY = board[0].size()-1;
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j] == 'S'){
                    startX = i;
                    startY = j;
                    break;
                }
            }
        }
        return recurr(startX,startY,board,dp);
        
    }
};