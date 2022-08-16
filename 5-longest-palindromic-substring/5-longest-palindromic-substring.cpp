class Solution {
public:
   string expandAroundCenter(string &s){
        int ans = 1;
        pair<int,int> res = {0,0};
        for(int i=0;i<s.length();++i){
            cout << ans <<"\n";
            if(i > 0){
                //Even
                int left = i-2;
                
                int right = i+1;
                
                if(s[i-1] == s[i]){
                    
                    if(ans < 2){
                        ans = 2;
                        res = {i-1,i};
                    }
                    
                    while(left >= 0 && right < s.length()){
                        if(s[left] == s[right]){
                            if(ans < (right-left+1)){
                                ans = right - left + 1;
                                res = {left,right};
                            }
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
                          
                             if(ans < (right-left+1)){
                                 
                                 ans = right - left + 1;
                                res = {left,right};
                            }
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
        return s.substr(res.first,res.second-res.first+1);
    }
    string longestPalindrome(string s) {
       return expandAroundCenter(s);
    }
};