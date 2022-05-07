class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalk = 0;
        for(auto &x : chalk) totalChalk += x;
        
        k %= totalChalk;
        for(int i=0;i<chalk.size();++i){
            if(k < chalk[i]) return i;
            k -= chalk[i];
        }
        return 0;
        
    }
};