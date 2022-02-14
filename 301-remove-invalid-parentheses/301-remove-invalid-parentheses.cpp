class Solution {
public:
    bool check(string s){
        stack <char> st;
        for(int i=0;i<s.length();++i){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            while(!st.empty() && s[i] == ')' && st.top() != '('){
                st.pop();
            }
            
            if(!st.empty() && st.top() == '(' && s[i] == ')'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        
        while(!st.empty() && st.top() != '(' && st.top() != ')'){
            st.pop();
        }
        
        
        return !(st.size());
        
    }
    vector<string> removeInvalidParentheses(string s) {
        //Backtracking using BFS

        queue <string> q;
        q.push(s);
        int mn = 0;
        int prev = q.size();
        int curr = 0;
        set<string> res;
        bool flag = 0;
        curr = q.size();
        while(q.size() > 0){
            
            
            set <string> tmp;
            for(int i=0;i<curr;++i){
                
                auto node = q.front();
                q.pop();
                //cout << node <<"\n";
                if(check(node)){
                    //cout << node <<"**\n";
                    res.insert(node);
                    flag = 1;
                }
                if(flag){
                    continue;
                }
                else{
                    
                    for(int j=0;j<node.length();++j){
                        if(node[j] != '(' && node[j] != ')') continue;
                        string temp;
                        for(int k=0;k<node.length();++k){
                            if(j != k)
                                temp += node[k];
                        }
                        //cout << temp <<"#\n";
                        tmp.insert(temp);
                    }                
                }
                
            }
            for(auto x : tmp){
                q.push(x);
            }
            tmp.clear();
            //cout <<"\n";
            curr = q.size();
            
        }
        vector<string> ans;
        for(auto &x : res){
                ans.push_back(x);
        }
        res.clear();
        return ans;
    }
};