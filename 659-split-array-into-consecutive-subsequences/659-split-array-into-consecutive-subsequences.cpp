class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> mp;
        multiset<int> st;
        for(auto &x : nums){
            mp[x]++;
        }
        for(auto &x : nums){
            
            if(mp[x] == 0) continue;
            
            if(st.find(x-1) != st.end()){
                st.erase(st.find(x-1));
                st.insert(x);
                mp[x]--;
                continue;
            }
            
            if(mp[x+1] == 0 or mp[x+2] == 0) return false;
            
            st.insert(x+2);
            mp[x+2]--;
            mp[x+1]--;
            mp[x]--;
        }
        
        return true;
    }
};