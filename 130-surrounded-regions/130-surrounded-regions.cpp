class Solution {
public:
    bool isBoundary(int x,int y,vector<vector<char>>&board){
        if((x == 0) or (y == 0) or x == (board.size()-1)  or (y == (board[0].size()-1))) return true;
        return false;
    }
    bool check(int x,int y,vector<vector<char>> &board){
        if(x < 0 or y < 0 or x >= board.size() or y >= board[0].size()){
            return false;
        }
        return true;
    }
    vector<int> dx = {0,-1,1,0};
    vector<int> dy = {-1,0,0,1};
    
    void dfs(pair<int,int> node,vector<vector<bool>> &vis,vector<vector<char>> &board,bool &isEnclosed,vector<pair<int,int>> &comp){
        auto [x,y] = node;
        vis[x][y] = 1;
        comp.push_back(node);
        if(isBoundary(x,y,board) && board[x][y] == 'O') isEnclosed = 1;
        for(int mv=0;mv<4;++mv){
            if(check(x+dx[mv],y+dy[mv],board) && !vis[x+dx[mv]][y+dy[mv]] && board[x+dx[mv]][y+dy[mv]] == 'O'){
                dfs({x+dx[mv],y+dy[mv]},vis,board,isEnclosed,comp);
            }
        }
    }
    
    
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),0));
        
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(!vis[i][j] && board[i][j] == 'O'){
                    bool isEnclosed = 0;
                    vector<pair<int,int>> comp;
                    
                    dfs({i,j},vis,board,isEnclosed,comp);
                    
                    if(!isEnclosed){
                        for(auto [x,y] : comp){
                            board[x][y] = 'X';
                        }
                    }
                    isEnclosed = 0;
                    
                }
            }
        }
    }
};