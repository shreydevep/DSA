class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &x : nums){
            st.insert(x);
        }
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            if(st.find(nums[i]) == st.end()) continue;
            
            int curr1 = nums[i];
            int len = 0;
            while(st.find(curr1) != st.end()){
                st.erase(curr1);
                curr1--;
                len++;
            }
            int curr2 = nums[i]+1;
            while(st.find(curr2) != st.end()){
                st.erase(curr2);
                curr2++;
                len++;
            }
            ans = max(ans,len);
            
            
        }
        return ans;
        
    }
};