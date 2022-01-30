class Solution {
public:
    int bs_lower(vector <int> &nums,int key){
        int i=0;
        int j=nums.size()-1;
        
        while(i < j){
            int mid = i + (j-i)/2;
            if(nums[mid] >= key){
                j = mid;
            }
            else{
                i = mid + 1;
            }
        }
        while(i < nums.size() && nums[i] < key){
            i++;
        }
        
        return i;
    }
    int bs_upper(vector <int> &nums, int key){
        int i=0;
        int j= nums.size()-1;
        while(i < j){
            int mid = i + (j-i)/2;
            
            if(nums[mid] > key){
                j = mid;
            }
            else{
                i = mid + 1;
            }
        }
        while(i < nums.size() && nums[i] <= key){
            i++;
        }
        return i;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> bounds(2,0);
        bounds[0] = bs_lower(nums,target);
        bounds[1] = bs_upper(nums,target) - 1;
        if(bounds[0] >= nums.size() || bounds[0] < 0 || nums[bounds[0]] != target){
            bounds[0] = -1;
        }
        if(bounds[1] >= nums.size() || bounds[1] < 0 || nums[bounds[1]] != target){
            bounds[1] = -1;
        }
        return bounds;
    }
};