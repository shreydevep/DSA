class Solution {
public:
    
    vector<int> sortArrayByParity(vector<int>& nums) {
        int evenPtr_start  = 0;
        int oddPtr_end  = nums.size()-1;
        while(evenPtr_start < oddPtr_end){
            if(nums[evenPtr_start] % 2 == 0) {
                evenPtr_start++;
                continue;
            }
            if(nums[oddPtr_end] % 2 != 0){
                oddPtr_end--;
                continue;
            }
            swap(nums[evenPtr_start],nums[oddPtr_end]);
            evenPtr_start++;
            oddPtr_end--;
        }
        return nums;
    }
};