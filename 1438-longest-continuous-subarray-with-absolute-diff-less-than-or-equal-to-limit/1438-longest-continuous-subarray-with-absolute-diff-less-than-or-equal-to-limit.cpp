class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        int ans = 0;
        int i = 0;
        for(int j=0;j<nums.size();++j){
            st.insert(nums[j]);
           
            while(i <= j && st.size() > 0 && (*st.rbegin() - *st.begin()) > limit){
                st.erase(st.find(nums[i]));
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};