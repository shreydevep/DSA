class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int mp[10001];
        for(int i=nums2.size()-1;i>=0;--i){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }
            
            if(!st.empty()){
                mp[nums2[i]] =st.top();
                
            }
            else{
                mp[nums2[i]] = -1;
            }
            st.push(nums2[i]);
        }
        for(auto &x : nums1){
            x = mp[x];
        }
        return nums1;
    }
};