class Solution {
public:
    char getChar(int i,int j,int &k,vector<vector<int>> &uniqueChars){
        for(int z=0;z<26;++z){
            if((uniqueChars[j][z] - uniqueChars[i-1][z]) > 0 && uniqueChars[j][z] - uniqueChars[i-1][z] < k){
                return (z + 'a');
            }
        }
        return '.';
    }
    bool check(int i,int j,int &k,vector<vector<int>> &uniqueChars){
        
        for(int z=0;z<26;++z){
            if((uniqueChars[j][z] - uniqueChars[i-1][z]) > 0 && (uniqueChars[j][z] - uniqueChars[i-1][z]) < k){
                return 0;
            }
        }
        return 1;
    }
    
    int divide(int i,int j,int &k,string &s,vector<vector<int>> &uniqueChars){
        //cout << i<<" "<< j <<"\n";
        if(i > j) return 0;
        if((j - i + 1) < k) return 0;
        if(check(i,j,k,uniqueChars)){
            return (j - i + 1);
        }
        int temp = 0;
        char ch = getChar(i,j,k,uniqueChars);
        //cout << ch <<"\n";
        int st = i;
        for(int z=i;z<=j;++z){
            if(s[z-1] == ch){
                temp = max(temp,divide(st,z-1,k,s,uniqueChars));
                st = z+1;
            }
        }
        temp = max(temp,divide(st,j,k,s,uniqueChars));
        return temp;
    }
    int longestSubstring(string s, int k) {
        vector<vector<int>> uniqueChars(s.length()+2,vector<int>(26,0));
        for(int i=1;i<=s.length();++i){
            for(int j=0;j<26;++j){
                uniqueChars[i][j] = uniqueChars[i-1][j];
            }
            uniqueChars[i][s[i-1]-'a']++;
        }
        return divide(1,s.length(),k,s,uniqueChars);
       
    }
};