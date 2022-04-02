class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        bool flag = 1;
        while(i<=j){
            if(s[i] != s[j]){
                flag = 0;
                break;
            }
            i++;
            j--;
        }
        if(flag) return true;
        int temp_i = i;
        int temp_j = j;
        i++;
        bool ans1 = true;
        while(i<=j){
            if(s[i] != s[j]){
                ans1 = false;
                break;
            }
            i++;
            j--;
        }
        i = temp_i;
        j = temp_j;
        j--;
        bool ans2 = true;
        while(i<=j){
            if(s[i] != s[j]){
                ans2 = false;
                break;
            }
            i++;
            j--;
        }
        return (ans1 || ans2);
        
        
    }
};