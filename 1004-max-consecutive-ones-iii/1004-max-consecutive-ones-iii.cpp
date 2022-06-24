class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt_0 = 0;
        int i = 0;
        int ans = 0;
        for( int j = 0 ; j < nums.size() ; ++j ) {
            if(nums[j] == 0) ++cnt_0;
            while(cnt_0 > k) {
                if(nums[i] == 0) --cnt_0;
                ++i;
            }
            ans = max( ans, j - i + 1 );
        }
        return ans;
    }
};