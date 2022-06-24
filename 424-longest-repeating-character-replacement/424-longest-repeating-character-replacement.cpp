class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(char ch='A';ch<='Z';++ch){
            //Sliding Window
            int j = 0;
            int cnt = 0;
            for(int i=0;i<s.length();++i){
                while(j < s.length() && cnt <= k){
                    if(s[j] == ch){
                        j++;
                        continue;
                    }
                    else if(cnt < k){
                        cnt++;
                        j++;
                    }
                    else{
                        break;
                    }
                }
                ans = max(ans,(j - i));
                if(s[i] != ch){
                    cnt--;
                }
            }
        }
        return ans;
    }
};