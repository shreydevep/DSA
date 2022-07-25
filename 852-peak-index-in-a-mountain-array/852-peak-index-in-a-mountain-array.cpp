class Solution {
public:
    int bs(vector<int> &nums){
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            int mid = (l+r)/2;
            if(nums[mid]  < nums[mid+1]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return r;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        return bs(arr);
    }
};