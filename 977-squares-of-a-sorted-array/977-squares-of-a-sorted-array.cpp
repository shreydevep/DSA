class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector <int> res(nums.size());
        
        int i=0;
        int j= nums.size()-1;
        int end = nums.size()-1;
        while(i<=j){
            if(abs(nums[i]) >= abs(nums[j])){
                res[end] = nums[i]*nums[i];
                end--;
                i++;
            }
            else{
                res[end] = nums[j]*nums[j];
                end--;
                j--;
            }
        }
        return res;
    }
};