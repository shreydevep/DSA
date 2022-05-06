class Solution {
public:
    string removeDuplicates(string s, int k) {
       stack<pair<char,int>> st;
        for(int i=0;i<s.length();++i){
            if(!st.empty() && st.top().first == s[i]){
                auto temp = st.top();
                st.pop();
                st.push({s[i],temp.second + 1});
            }
            else{
                st.push({s[i],1});
            }
            if(st.top().second == k){
                st.pop();
            }
        }
        string ans;
        while(!st.empty()){
            auto temp = st.top();
            st.pop();
            for(int i =0;i<temp.second;++i)
                ans.push_back(temp.first);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};