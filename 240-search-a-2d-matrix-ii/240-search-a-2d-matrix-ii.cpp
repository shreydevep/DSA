class Solution {
public:
    bool bs(vector<int> &nums,int target){
        int i=0;
        int j= nums.size()-1;
        while(i <= j){
            int mid = i + (j-i)/2;
            
            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid] < target){
                i = mid + 1;
            }
            else{
                j = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();++i){
            if(bs(matrix[i],target)) return true;
        }
        return false;
    }
};