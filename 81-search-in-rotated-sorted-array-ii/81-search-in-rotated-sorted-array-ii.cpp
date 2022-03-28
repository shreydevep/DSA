class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = l + (r-l)/2;        
        while(l <= r){
            while (l < r && nums[l] == nums[l + 1]) {
                l++;
            }
            while (l < r && nums[r] == nums[r - 1]) {
                r--;
            }
            mid = l + (r-l)/2;
            if(nums[mid] >= nums[r]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
            
        }
        int pivot = max(0,r-1);
       
        int itr1 = -1;
        int itr2 = -1;
        if(binary_search(nums.begin(),nums.begin()+pivot+1,target)){
             itr1 = lower_bound(nums.begin(),nums.begin()+pivot+1,target) - nums.begin();
        }
        if(binary_search(nums.begin()+pivot+1,nums.end(),target)){
             itr2 = lower_bound(nums.begin()+pivot+1,nums.end(),target) - nums.begin();
        }
       
       
        
        if(itr1 != -1){
            return true;
        }
        if(itr2 != -1){
            return true;
        }
        return false;
        
    }
};


        