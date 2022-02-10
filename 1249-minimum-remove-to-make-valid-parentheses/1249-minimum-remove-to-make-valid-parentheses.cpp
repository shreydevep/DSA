class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack <pair<char,int>> st;
        set <int> remove;
        for(int i=0;i<s.length();++i){
            if(st.empty() && s[i] ==')'){
                remove.insert(i);
                continue;
            }
            if(s[i] == ')'){
            auto ele = (st.top());
            while(!st.empty() && ele.first != '('){
                
                //cout << ele.first <<"\n";
                st.pop();
                if(!st.empty())
                    ele = st.top();
            }
            if(st.empty()){
                remove.insert(i);
                }
            else{
                    st.pop();
                }
            }
            else{
                
                st.push({s[i],i});
            }
        }
        while(!st.empty()){
            auto ele = (st.top());
            //cout << ele.first <<"\n";
            if(ele.first == '('){
                remove.insert(ele.second);
            }
            st.pop();
        }
        string res;
        for(int i=0;i<s.length();++i){
            if(remove.find(i) == remove.end()){
                res += s[i];
            }
        }
        return res;
        
    }
};