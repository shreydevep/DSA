class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<string,vector<int>> freq;
        for(auto &x : words){
            freq[x].resize(26);
            fill(freq[x].begin(),freq[x].end(),0);
            for(auto &ch : x){
                freq[x][ch-'a']++;
            }
        }
        int ans = 0;
        for(int i=0;i<words.size();++i){
            auto cnti = freq[words[i]];
            for(int j=i+1;j<words.size();++j){
                int tempi = 0;
                int tempj = 0;
                auto cntj = freq[words[j]];
                for(int k=0;k<26;++k){
                    if(cnti[k] != 0 && cntj[k] != 0){
                        tempi = 0;
                        tempj = 0;
                        break;
                    }
                    else{
                        tempi += cnti[k];
                        tempj += cntj[k];
                    }
                }
                
                ans = max(ans,tempi*tempj);
            }
        }
        return ans;
    }
};