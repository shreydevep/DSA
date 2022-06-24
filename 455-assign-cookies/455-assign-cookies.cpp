class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        multiset<int> st;
        sort(g.begin(),g.end());
        for(auto &x : s){
            st.insert(x);
        }
        int ans = 0;
        for(auto &childGreed : g){
            auto itr = st.lower_bound(childGreed);
            if(itr == st.end()) continue;
            
            ans++;
            st.erase(itr);
        }
        return ans;
    }
};