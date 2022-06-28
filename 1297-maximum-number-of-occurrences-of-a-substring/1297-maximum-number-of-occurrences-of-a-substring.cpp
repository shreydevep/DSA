class Solution {
public:
    unordered_map<string,int> hash;
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans = 0;
        for(int i=0;i<s.length();++i){
            string res;
            set<char> st;
            for(int j=i;j<min(i+minSize,(int)s.length());++j){
                st.insert(s[j]);
                res += s[j];
            }
            //cout << res <<"\n";
            if((st.size() > maxLetters) or (res.size() < minSize)) continue;
             hash[res]++;
            
            for(int j=(minSize);j<min(i+maxSize,(int)s.length());++j){
                st.insert(s[j]);
                if(st.size() > maxLetters){
                    break;
                }
                res += s[j];
                hash[res]++;
            }
            
        }
        for(auto &x : hash){
            //cout << x.first <<" "<< x.second <<"\n";
            ans = max(ans,x.second);
        }
        return ans;
    }
};