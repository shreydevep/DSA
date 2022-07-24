class Solution {
public:
    int bs(vector<int> &nums){
        
        int i =0;
        int j = nums.size()-1;
        
        while(i < j){
            int mid = (i+j)/2;
           
            if(nums[mid] > nums[mid+1]){
                j = mid;
            }
            else{
                i = mid + 1;
            }
        }
        return i;
    }
    int findPeakElement(vector<int>& nums) {
        return bs(nums);
    }
};