class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int min_j = -1;
        int max_i = n-1;
        for(int i=n-1;i>0;--i){
            for(int j=i-1;j>=0;--j){
                if(nums[i] > nums[j]){
                    if(min_j < j){
                        max_i = i;
                        min_j = j;
                    }
                }
            }
        }
        if(min_j != -1){
            swap(nums[min_j],nums[max_i]);
            sort(nums.begin() + min_j + 1,nums.end());
            return;
        }
        sort(nums.begin(),nums.end());
    }
};