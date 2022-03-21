class Solution {
public:
    static bool compare(const pair<int,int> &a,const pair<int,int> &b){
        if(a.first == b.first){
            if(a.second < b.second) return 1;
        }
        else if(a.first < b.first) return 1;
        return 0;
        
    }
    vector<int> partitionLabels(string s) {
        map<char,pair<int,int>> mp;
        
        for(int i=0;i<s.length();++i){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = {i,i};
            }
            else{
                mp[s[i]] = {mp[s[i]].first,i};
            }
        }
        vector<pair<int,int>> st;
        for(auto x : mp){
            st.push_back(x.second);
        }
        sort(st.begin(),st.end(),compare);
        vector<int> ans;
        int prev = -1;
        int ft = st[0].first;
        int last = st[0].second;
        
        for(auto x : st){
            if(last >= x.first || last >= x.second){
                ft = min(ft,x.first);
                last = max(last,x.second);
                continue;
            }
            else{
            
            //Print
                //cout << s.substr(ft,last - ft + 1) <<"\n";
                ans.push_back(last - ft + 1);
                ft = x.first;
                last = x.second;
            }
           
               
            
        }
         //cout << s.substr(ft,last - ft + 1) <<"\n";
         ans.push_back(last - ft + 1);
        return ans;
    }
};