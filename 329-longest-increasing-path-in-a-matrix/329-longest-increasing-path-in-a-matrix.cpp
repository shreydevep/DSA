class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int ans[201][201];
    
    int dfs(vector<vector<int>>& matrix,int i,int j){
        if(ans[i][j] != -1){
            return ans[i][j];
        }
        int temp =  0;
        for(int k=0;k<4;++k){
            if(ans[i][j] != -1){
                continue;
            }
            if(i + dx[k] >= matrix.size() || j + dy[k] >= matrix[0].size()){
                continue;
            }
            if(i + dx[k] < 0 || j + dy[k] < 0){
                continue;
            }
            if(matrix[i][j] < matrix[i+dx[k]][j+dy[k]]){
                temp = max(temp,dfs(matrix,i+dx[k],j+dy[k]) + 1);
            }
            
        }
        return ans[i][j] = temp;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        for(int i=0;i<201;++i){
            for(int j=0;j<201;++j){
                ans[i][j] = -1;
            }
        }
        int fin = 0;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[i].size();++j){
               fin = max(fin,dfs(matrix,i,j) + 1);
            }
        }
        
        return fin;
    }
};