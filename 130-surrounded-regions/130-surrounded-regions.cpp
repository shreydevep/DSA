class Solution {
public:
    bool check(int i,int j,vector<vector<char>> &board){
        if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size()){
            return 0;
        }
        return 1;
    }
    vector<int> dx = {-1,0,0,1};
    vector<int> dy = {0,-1,1,0};
    
    void bfs(int i,int j,vector<vector<char>> &board,vector<vector<bool>> &vis){
        
        for(int delta = 0;delta<4;++delta){
            int new_i = i+dx[delta];
            int new_j = j+dy[delta];
            if(check(new_i,new_j,board) && board[new_i][new_j] == 'O' && !vis[new_i][new_j]){
                vis[new_i][new_j] = 1;
                board[new_i][new_j] = '.';
                bfs(new_i,new_j,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),0));
        for(int i=0;i<board.size();++i){
            if(board[i][0] == 'O'){
                vis[i][0] = 1;
                board[i][0] = '.';
                bfs(i,0,board,vis);
            }
            
            if(board[i][board[0].size()-1] == 'O'){
                vis[i][board[0].size()-1] = 1;
                board[i][board[0].size()-1] = '.';
                bfs(i,board[0].size()-1,board,vis);
            }
        }
        for(int j=0;j<board[0].size();++j){
            
            if(board[0][j] == 'O'){
                vis[0][j] = 1;
                board[0][j] = '.';
                bfs(0,j,board,vis);
            }
            if(board[board.size()-1][j] == 'O'){
               
                vis[board.size()-1][j] = 1;
                board[board.size()-1][j] = '.';
                bfs(board.size()-1,j,board,vis);
            }
        }
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j] != '.') board[i][j] = 'X';
                else board[i][j] = 'O';
            }
            
        }
        
        
        
    }
};