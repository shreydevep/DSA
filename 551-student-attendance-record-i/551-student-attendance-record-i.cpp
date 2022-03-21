class Solution {
public:
   
    bool checkRecord(string s) {
        if(s.length() == 1) return 1;
        
        
        
        int abs = 0;
        if(s[0] == 'A') abs++;
        if(s[1] == 'A') abs++;
        
        for(int i=2;i<s.length();++i){
            int j = i;
            int cnt = 3;
            string temp = s.substr(i-3+1,3);
            if(s[i] == 'A') abs++;
            
            if(temp == "LLL") return 0;
            if(abs >= 2) return 0;
            
        }
        if(abs >= 2) return 0;
        return 1;
        
    }
};