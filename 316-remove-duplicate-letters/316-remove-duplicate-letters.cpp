class Solution {
public:
    string removeDuplicateLetters(string s) {
        int freq[26] = {0};
        bool present[26] = {0};
        
        for(auto ch : s){
            freq[ch-'a']++;
        }
        
        stack<char> st;
        
        for(auto ch : s){
            freq[ch-'a']--;
            if(present[ch-'a']) continue;
            
             while(st.size() > 0 && st.top() > ch && freq[st.top() - 'a'] > 0 ){
                    present[st.top() - 'a'] = 0;
                    st.pop();
                }
                
                st.push(ch);
                present[ch-'a'] = 1;
                
            }
        
        
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};