class Solution {
public:
  vector<vector<string>> res;
  bool check(string &s){
      int i = 0;
      int j = s.length()-1;
      while(i < j){
          if(s[i] != s[j]) return false;
          i++;
          j--;
      }
      return true;
  }
    
   void recurr(int i,vector<string> &pos,string &s){
       if(i >= s.length()){
           res.push_back(pos);
           return;
       }
       for(int j=i;j<s.length();++j){
           string posPan = s.substr(i,j-i+1);
           if(check(posPan)){
               pos.push_back(posPan);
               recurr(j+1,pos,s);
               pos.pop_back();
           }
       }
       
   }
    vector<vector<string>> partition(string s) {
        vector<string> pos;
        
        recurr(0,pos,s);
        return res;
    }
};
