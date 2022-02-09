class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        multiset<int> st;
        set <pair<int,int>> res;
        
        for(auto x : nums){
            st.insert(x);
        }
        
        for(int i=0;i<nums.size();++i){
            if(st.find(nums[i]) == st.end()) continue;
            int val1 = nums[i] - k;
            int val2 = nums[i] + k;
            st.erase(st.find(nums[i]));
            if(val1 == val2){
                if(st.find(val1) != st.end()){
                    res.insert({min(nums[i],val1),max(nums[i],val1)});
                }
                
            }
            else{
                if(st.find(val1) != st.end())
                    res.insert({min(nums[i],val1),max(nums[i],val1)});
                if(st.find(val2) != st.end())
                    res.insert({min(nums[i],val2),max(nums[i],val2)});
            }
            
        }
       
        return res.size();
    }
};