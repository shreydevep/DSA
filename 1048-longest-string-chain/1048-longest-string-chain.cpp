class Solution {
public:
    static bool comp(string& s1, string& s2){
        return s1.size()<s2.size();
    }
    bool check(string& a, string& b){
        if(a.size()+1!=b.size())return false;
        int cnt=0;
        for(int i=0,j=0;j<b.size();j++){
            if(a[i]==b[j])i++;
            else cnt++;
            if(cnt==2)return false;
        }
        return true;
    }
    
    int calc(vector<string>& words, int i, int prev,vector<vector<int>>& dp){
        if(i==words.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        
        int dont=calc(words,i+1,prev,dp);
        int take=0;
        if(prev==-1 || check(words[prev],words[i]))take=1+calc(words,i+1,i,dp);
        return dp[i][prev+1]= max(take,dont);
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return calc(words,0,-1,dp);
    }
};