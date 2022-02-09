class Solution {
public:
    string removeOuterParentheses(string s) {
        stack <char> st;
        int curr = 0;
        string ans;
        for(int i=0;i<s.length();++i){
            if(st.empty() && i == curr){
                st.push(s[i]);
                continue;
            }
            if(st.top() == '(' && s[i] == ')'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            
            if(st.empty() && i != curr){
                ans += s.substr(curr+1,i-curr-1);
                //cout << curr <<" "<< i <<" "<<s.substr(curr+1,i-curr-1) <<"\n";
                curr = i+1;
                continue;
            }
            
            
        }
        return ans;
    }
};