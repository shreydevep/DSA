class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(auto &x : s){
            if(x >= 'a' && x <= 'z' || x >= 'A' && x <='Z' || x >='0' && x <='9'){
                temp += tolower(x);
            }
        }
        
        int i=0;
        int j=temp.length()-1;
        
        while(i <= j){
            if(temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
};