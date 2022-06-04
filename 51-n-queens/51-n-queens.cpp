class Solution {
public:
    bool isAttacked(int x,int y,vector<string> &queensPos){
        int i=x;
        int j=y;
        while(i >= 0 && j>= 0){
            if(queensPos[i][j] == 'Q') return true;
            i--;
            j--;
        }
        i=x;
        j=y;
         while(j>= 0){
            if(queensPos[i][j] == 'Q') return true;
            j--;
        }
        i=x;
        j=y;
         while(i < queensPos.size() && j >=0){
            if(queensPos[i][j] == 'Q') return true;
            i++;
            j--;
        }
        
        return false;
        
    }
    vector<vector<string>> ans;
    void recurr(int col,vector<string> queensPos){
        
        if(col == queensPos[0].size()){
            
                ans.push_back(queensPos);
            
            return;
        }
        
        for(int row=0;row<queensPos.size();++row){
            if(isAttacked(row,col,queensPos)) continue;
            queensPos[row][col] = 'Q';
            recurr(col+1,queensPos);
            queensPos[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> queensPos(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                queensPos[i].push_back('.');
            }
        }
        recurr(0,queensPos);
        return ans;
    }
};