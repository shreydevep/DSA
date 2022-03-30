class Solution {
public:
    int binary_search_lb(vector<vector<int>> &matrix,int target){
        int l=0;
        int r = matrix.size();
        int mid = l + (r-l)/2;
        
        while(l < r){
            mid = l + (r-l)/2;
            
            if(matrix[mid][0] <= target){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        if(l < matrix.size() && matrix[l][0] <= target){
            l++;
        }
        return l;
    }
    
    bool binary_search_ele(vector<vector<int>> &matrix,int pos,int target){
        int l = 0;
        int r = matrix[pos].size()-1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            
            if(matrix[pos][mid] == target){
                return true;
            }
            else if(matrix[pos][mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return 0;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int pos = binary_search_lb(matrix,target);
        
        if(pos < matrix.size() && matrix[pos][0] == target)
            return binary_search_ele(matrix,pos,target);
        else{
            pos--;
            if(pos < 0) return 0;
            return binary_search_ele(matrix,pos,target);
        }
        
        
        
    }
};