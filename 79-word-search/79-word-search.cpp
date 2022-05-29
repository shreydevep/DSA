class Solution {
public:
    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};
    bool check(int i,int j,int di,int dj,vector<vector<char>>& board,vector<vector<bool>> &vis){
         if(i + di >= board.size() || j + dj >= board[0].size() || i + di < 0 || j + dj < 0 || vis[i+di][j+dj]) return false;
         return true;
    }
    bool recurr(int i,int j,vector<vector<char>>& board,vector<vector<bool>> &vis,string curr,string &word){
        if(curr == word) return true;
        bool temp = false;
        for(int k=0;k<4;++k){
                int di = dx[k];
                int dj = dy[k];
                if(check(i,j,di,dj,board,vis) && board[i+di][j+dj] == word[curr.length()]){
                    vis[i+di][j+dj] = true;
                    curr += board[i+di][j+dj];
                    temp |= recurr(i+di,j+dj,board,vis,curr,word);
                    curr.pop_back();
                    vis[i+di][j+dj] = false;
                }
        }
        return temp;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),0));
        bool ans = false;
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j] == word[0]){
                    string curr;
                    curr += word[0];
                    vis[i][j] = 1;
                    ans |= recurr(i,j,board,vis,curr,word);
                    vis[i][j] = 0;
                }
            }
        }
        return ans;
    }
};