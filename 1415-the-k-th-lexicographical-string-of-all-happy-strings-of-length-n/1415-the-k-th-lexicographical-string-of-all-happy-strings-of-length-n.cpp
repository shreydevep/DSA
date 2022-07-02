class Solution {
public:
    vector<string> ans;
    void recurr(int i,string res,int n,int k){
       if(i == n){
           ans.push_back(res);
           return;
       }
       for(char ch = 'a';ch <= 'c';++ch){
           if(res.back() == ch) continue;
           res.push_back(ch);
           recurr(i+1,res,n,k);
           res.pop_back();
       } 
    }
    string getHappyString(int n, int k) {
        recurr(0,"",n,k);
        sort(ans.begin(),ans.end());
        if(ans.size() < k) return "";
        return ans[k-1];
    }
};
// a b c ab ac ba bc ca cb aba
//a b c
//a b ba c ca
//a ab b bab c cb cab
//a ab ab abc 