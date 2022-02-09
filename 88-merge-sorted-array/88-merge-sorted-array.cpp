class Solution {
public:
    void sort_first(vector<int> &nums,int n,int val){
        int i =1;
        for(i=1;i<n && nums[i] < val; ++i){
            nums[i-1] = nums[i];
        }
        nums[i-1] = val;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int start1 = 0;
        int start2 = 0;
        while(start1 < m && start2 < n){
            if(nums1[start1] <= nums2[start2]){
                start1++;
            }
            else{
                swap(nums1[start1],nums2[start2]);
                sort_first(nums2,n,nums2[0]);
                start1++;
            }
        }
        while(start2 < n){
            nums1[start1] = nums2[start2];
            start1++;
            start2++;
        }
    }
};