class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char> st;
        for(auto x : s){
            if(st.empty()){
                st.push(x);
                continue;
            }
            
            if(st.top() == '(' && x == ')'){
                st.pop();
            }
            else{
                st.push(x);
            }
        }
        return st.size();
    }
};