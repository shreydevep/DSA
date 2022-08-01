class Solution {
public:
    int pivot(vector<int> &nums){
        int l = 0;
        int r = nums.size()-1;
        
        while(l < r){
            int mid = (l + r)/2;
            
            if(nums[mid] >= nums[r]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return r;
    }
    int binary_search(int l,int r,vector<int> &nums,int target){
        while(l<=r){
            int mid = (l+r)/2;
            
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pvt = pivot(nums);
        int itr1 = binary_search(0,max(0,pvt-1),nums,target);
        int itr2 = binary_search(min(pvt,(int)nums.size()-1),nums.size()-1,nums,target);
        if(itr1 != -1) return itr1;
        return itr2;
        
    }
};