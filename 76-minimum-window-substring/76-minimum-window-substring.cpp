class Solution {
public:
   string minWindow(string s, string t) {
       
    unordered_map<char,int> mp;
    for(int i=0;i<t.length();++i){
        mp[t[i]]++;
    }
    int count=mp.size();
    string ans;
    int mn=INT_MAX;
    int i=0;
    int j=0;
       
    while(j<s.length()){
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0){
                count--;
            }
        }
        while(count == 0){
            if(j-i+1 < mn){
                mn=j-i+1;
                ans=s.substr(i,j-i+1);
            }
            
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]++;
                if(mp[s[i]]==1){
                    //Elements become less hence stops satisfying while loop condition
                    count++;
                }
            }
            i++;
        }
        j++;
    }
    return ans;
}

};