class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int start1 = 0;
        int start2 = 0;
        while(start1 < m && start2 < n){
            if(nums1[start1] <= nums2[start2]){
                start1++;
            }
            else{
                swap(nums1[start1],nums2[start2]);
                sort(nums2.begin(),nums2.end());
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