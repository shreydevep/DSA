class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) swap(nums1,nums2);
        
        int low = 0;
        int high = nums1.size();
        while(low <= high){
            int partitionX = (low + high)/2;
            int partitionY = (nums1.size() + nums2.size() + 1)/2 - partitionX;
            
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX-1];
            int minRightX = (partitionX == nums1.size()) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY-1];
            int minRightY = (partitionY == nums2.size()) ? INT_MAX : nums2[partitionY];
            
            if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                if((nums1.size() + nums2.size()) % 2 == 0){
                    return ((double)(max(maxLeftX,maxLeftY)) + min(minRightX,minRightY))/2.0;
                }
                else{
                    return ((double)max(maxLeftX,maxLeftY));
                }
            }
            else if(maxLeftX > minRightY){
                high = partitionX - 1;
            }
            else{
                low = partitionX + 1;
            }
        }
        return -1.0;
    }
};