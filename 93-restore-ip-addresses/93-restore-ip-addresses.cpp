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
        //cout << temp <<"\n";
        int cnt = 0;
        for(auto &x : temp){
            if(x == '.') cnt++;
        }
        if(cnt != 3) return 0;
        
       return nowCheck(temp);
    }
    void recurr(string &s){
        int n = s.length();
        for(int i=0;i<n-3;i++){//i ke left me
            for(int j=i+1;j<n-2;j++){//j ke left me
                for(int k=i+2;k<n-1;k++){// k ke left me
                    
                    vector<int> pos;
                    pos.push_back(i);
                    pos.push_back(j);
                    pos.push_back(k);
                    check(pos,s);
                    pos.clear();
                }
            }
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        
        recurr(s);
        return ans;
    }
};