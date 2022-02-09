class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack <int> st;
        for(int i=nums.size()-1;i>=0;--i){
            st.push(nums[i]);
        }
        
        for(int i=nums.size()-1;i>=0;--i){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            int temp = nums[i];
            if(!st.empty()){
                nums[i] = st.top();
            }
            else{
                nums[i] = -1;
            }
            st.push(temp);
        }
        return nums;
    }
};