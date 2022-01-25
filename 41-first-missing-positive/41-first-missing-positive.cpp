class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int curr_neg = 0;
        while(curr_neg < nums.size() && nums[curr_neg] > 0){
            curr_neg++;
        }
        int curr = nums.size() - 1;
        while(curr > curr_neg){
            if(nums[curr] <= 0){
                curr--;
                continue;
            }
            swap(nums[curr],nums[curr_neg]);
            while(curr_neg < nums.size() && nums[curr_neg] > 0){
                curr_neg++;
            }
            curr--;   
        }
        int cntPos = 0;
        int sz = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i] > 0){
                cntPos++;
                sz = i+1;
            }
        }
        for(int i=0;i<sz;++i){
            if(abs(nums[i]) <= cntPos && nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }
        int res = cntPos+1;
        for(int i=0;i<sz;++i){
            if(nums[i] > 0){
                res = min(res,i+1);
            }
        }
        return res;
    }
};