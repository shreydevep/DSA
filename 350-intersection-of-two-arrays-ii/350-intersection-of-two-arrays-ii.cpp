class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset <int> st;
        for(auto x : nums1){
            st.insert(x);
        }
       vector <int> ans;
        for(auto x : nums2){
            if(st.find(x) != st.end()){
                ans.push_back(x);
                st.erase(st.find(x));
            }
        }
        return ans;
    }
};