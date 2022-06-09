class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        while(i < j){
            if(i > 0 && nums[i-1] == nums[i]){
                i++;
                continue;
            }
            if(j < nums.size()-1 && nums[j] == nums[j+1]){
                j--;
                continue;
            }
            if(nums[i] + nums[j] == target){
               vector <int> temp = {i+1,j+1};
                return temp;
            }
            else if(nums[i] + nums[j] < target){
                i++;
            }
            else{
                j--;
            }
        }
        vector<int> temp;
        return temp;
    }
};