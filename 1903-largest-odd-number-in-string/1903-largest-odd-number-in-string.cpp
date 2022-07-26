class Solution {
public:
    string largestOddNumber(string num) {
        int pos = 0;
        for(int i=0;i<num.length();++i){
            if((num[i]-'0') % 2 != 0) pos = i+1;
        }
        return num.substr(0,pos);
    }
};