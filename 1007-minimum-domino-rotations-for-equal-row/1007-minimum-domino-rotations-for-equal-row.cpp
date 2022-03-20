class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_set<int> st;
        for(int i=1;i<=6;++i){
            st.insert(i);
                for(int j=0;j<tops.size();++j){
                    if(tops[j] != i && bottoms[j] != i){
                            st.erase(i);
                    }
                }
        }
        if(st.size() == 0) return -1;
        int ans = tops.size();
        for(auto x : st){
            int ans1 = 0;
            int ans2 = 0;
            for(int i=0;i<tops.size();++i){
                if(tops[i] != x) ans1++;
                if(bottoms[i] != x) ans2++;
            }
            ans = min(ans1,ans2);
        }
        
        return ans;
        
        
        
        
    }
};