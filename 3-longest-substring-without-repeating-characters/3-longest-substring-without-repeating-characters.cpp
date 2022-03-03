class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int curr = 0;
        int ans = 0;
        set<int> st;
        
        for(int i=0;i<s.length();++i){
            if(st.find(s[i]) == st.end()){
                st.insert(s[i]);
                ans = max(ans,i - curr + 1);
            }
            else{
                while(curr < i && st.find(s[i]) != st.end()){
                    st.erase(s[curr]);
                    curr++;
                }
                st.insert(s[i]);
                ans = max(ans,i - curr + 1);
            }
        }
        return ans;
    }
};