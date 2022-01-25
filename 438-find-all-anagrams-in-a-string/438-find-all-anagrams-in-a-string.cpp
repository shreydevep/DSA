class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()){
            return vector<int>();
        }
        
        vector<int>freq_s(26,0);
        vector<int> freq_p(26,0);
        for(int i=0;i<p.size();++i){
            freq_s[s[i]-'a']++;
            freq_p[p[i]-'a']++;
        }
        int i=0;
        int j=p.size()-1;
        vector <int> res;
        if(j < s.size()){
            int cnt = 0;
            for(int k=0;k<26;++k){
                if(freq_s[k] == freq_p[k]){
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
            freq_s[s[prev]-'a']--;
            freq_s[s[j]-'a']++;
            for(int k=0;k<26;++k){
                //cout << k <<" "<< freq_s[k] <<"\n";
                if(freq_s[k] == freq_p[k]){
                    cnt++;
                }
            }
            //cout << cnt <<"\n";
            if(cnt == 26){
                //cout << i <<"\n";
                res.push_back(i);
            }
            i++;
            j++;
        }
        return res;
    }
};