class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>> st;
        int mn = INT_MAX;
        
        for(int i=0;i<nums.size();++i){
            if(!st.empty()){
                mn = min(mn,st.top().first);
            }
            while(!st.empty() && nums[i] > st.top().first){
                st.pop();
            }
            if(!st.empty() && st.top().second < nums[i] && nums[i] < st.top().first){
                return true;
            }
            st.push({nums[i],mn});
        }
        return false;
    }
};