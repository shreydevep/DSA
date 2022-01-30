class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long product = 1;
        if(k == 0 || product == k) return 0;
        int i = 0;
        int ans = 0;
        for(int j=0;j<nums.size();++j){
            product *= nums[j];
            while(product >= k) product /= nums[i++];
            ans += (j-i+1);
        }
        return ans;
    }
};