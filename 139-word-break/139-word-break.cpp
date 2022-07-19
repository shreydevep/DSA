class Solution {
public:
    vector<vector<int>> dp;
    bool isCheck(string temp,vector<string> &wordDict){
        for(auto &str : wordDict){
            if(str == temp) return true;
        }
        return false;
    }
    int recurr(int i,int j,string &s,vector<string> &wordDict){
        if(i > j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        bool isPossible = isCheck(s.substr(i,j-i+1),wordDict);
        for(int k=i;k<j;++k){
            bool temp = recurr(i,k,s,wordDict) && recurr(k+1,j,s,wordDict);
            isPossible |= temp;
        }
        return dp[i][j] = isPossible;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.length(),vector<int>(s.length(),-1));
        return recurr(0,s.length()-1,s,wordDict);
    }
};