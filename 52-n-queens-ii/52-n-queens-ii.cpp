class Solution {
public:
    vector<bool> row_hash;
    vector<bool> diagonal_forward_hash;
    vector<bool> diagonal_backward_hash;
    bool isAttacked(int x,int y,vector<string> &queensPos){
        if(row_hash[x]) return true;
        if(diagonal_forward_hash[x+y]) return true;
        if(diagonal_backward_hash[queensPos.size()-1 + (y-x)]) return true;
        
        
        return false;
        
    }
    int ans = 0;
    void recurr(int col,vector<string> queensPos){
        
        if(col == queensPos[0].size()){
            ans++;
            return;
        }
        
        for(int row=0;row<queensPos.size();++row){
            if(isAttacked(row,col,queensPos)) continue;
            queensPos[row][col] = 'Q';
            row_hash[row] = true;
            diagonal_forward_hash[row+col] = true;
            diagonal_backward_hash[queensPos.size()-1 + (col-row)] = true;
            recurr(col+1,queensPos);
            row_hash[row] = false;
            diagonal_forward_hash[row+col] = false;
            diagonal_backward_hash[queensPos.size()-1 + (col-row)] = false;
            
            queensPos[row][col] = '.';
        }
    }
        int totalNQueens(int n) {
        vector<string> queensPos(n);
        row_hash.resize(n,0);
        diagonal_forward_hash.resize(2*n,0);
        diagonal_backward_hash.resize(2*n,0);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                queensPos[i].push_back('.');
            }
        }
        recurr(0,queensPos);
        return ans;
    }
};