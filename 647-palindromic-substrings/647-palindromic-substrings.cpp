class Solution {
public:
    int expandAroundCenter(string &s){
        int ans = 1;
        pair<int,int> res = {0,0};
        for(int i=1;i<s.length();++i){
            ans++;
            if(i > 0){
                //Even
                int left = i-2;
                
                int right = i+1;
                
                if(s[i-1] == s[i]){
                    
                    ans++;
                    
                    while(left >= 0 && right < s.length()){
                        if(s[left] == s[right]){
                            ans++;
                            left--;
                            right++;
                        }
                        else{
                            break;
                        }
                    }
                }
                
                
                left = i-1;
                right = i+1;
                
                while(left >= 0 && right < s.length()){
                        if(s[left] == s[right]){
                          
                            ans++;
                            left--;
                            right++;
                        }
                        else{
                            break;
                        }
                }
                
                
                //Odd
            }
            
        }
        return ans;
    }
    int countSubstrings(string s) {
        return expandAroundCenter(s);
    }
};