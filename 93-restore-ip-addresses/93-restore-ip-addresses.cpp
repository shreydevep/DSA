class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;
    bool nowCheck(string &ip){
        stringstream ss(ip);
        vector<string> v;
        while (ss.good()) {
            string substr;
            getline(ss, substr, '.');
            v.push_back(substr);
        }
        string newIp;
        for(auto &x : v){
            
            if(x.length() > 3)  return 0;
            
            int val = stoi(x);
            if(val < 0 or val > 255){
                return 0;
            }
            string y = to_string(val);
            if(y.length() != x.length()) return 0;
            
        }
        newIp.pop_back();
        if(st.find(ip) == st.end()){
            st.insert(ip);
            ans.push_back(ip);
        }
        
        return 1;
    }
    bool check(vector<int> pos,string &s){
        if(pos.size() != 3) return 0;
        reverse(pos.begin(),pos.end());
        string temp;
        for(int i=0;i<s.length();++i){
            temp += s[i];
            if(pos.size() > 0 && i == pos.back()){
                temp += ".";
                pos.pop_back();
            }
        }
        int cnt = 0;
        for(auto &x : temp){
            if(x == '.') cnt++;
        }
        if(cnt != 3) return 0;
        
        return nowCheck(temp);
    }
    void recurr(int i,int remNum,vector<int> &pos,string &s){
        if(remNum == 0){
            //Check;
            check(pos,s);
            return;
        }
        for(int j=i;j<s.length()-1;++j){
            pos.push_back(j);
            recurr(j,remNum-1,pos,s);
            pos.pop_back();
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<int> pos;
        recurr(0,3,pos,s);
        return ans;
    }
};