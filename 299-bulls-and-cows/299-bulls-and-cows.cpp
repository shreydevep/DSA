class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        multiset<int> st;
        for(int i=0;i<guess.size();++i){
            if(secret[i] == guess[i]){
                bulls++;
               continue;
            }
            st.insert(guess[i]);
        }
        int cows = 0;
        for(int i=0;i<secret.length();++i){
            if(secret[i] == guess[i]) continue;
            if(st.find(secret[i]) != st.end()){
                cows++;
                st.erase(st.find(secret[i]));
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
        
    }
};