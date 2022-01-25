class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<vector<int>> freq(s.size(),vector<int>(26,0));
        freq[0][s[0]-'a']++;
        for(int i=1;i<s.size();++i){
            for(int j=0;j<26;++j){
                freq[i][j] += freq[i-1][j];
            }
            freq[i][s[i]-'a']++;
        }
        vector<int> freq_p(26,0);
        for(auto x : p){
            freq_p[x-'a']++;
        }
        int i=0;
        int j=p.size()-1;
        vector <int> res;
        if(j < s.size()){
            int cnt = 0;
            for(int k=0;k<26;++k){
                if(freq[j][k] == freq_p[k]){
                    cnt++;
                }
            }
            if(cnt == 26){
                res.push_back(i);
            }
        }
        i = 1;
        j = p.size();
        while(j<s.size()){
            int prev = i-1;
            int cnt = 0;
            for(int k=0;k<26;++k){
                if((freq[j][k] - freq[prev][k]) == freq_p[k]){
                    cnt++;
                }
            }
            if(cnt == 26){
                res.push_back(i);
            }
            i++;
            j++;
        }
        return res;
    }
};