class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i=0;i< s.length();++i){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(s[i] == ')'){
                queue <char> temp;
                while(!st.empty() && st.top() != '('){
                    temp.push(st.top());
                    //cout << st.top() <<"\n";
                    st.pop();
                }
                if(st.top() == '('){
                    st.pop();
                }
                while(!temp.empty()){
                    //cout << temp.front() <<"\n";
                    st.push(temp.front());
                    temp.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};