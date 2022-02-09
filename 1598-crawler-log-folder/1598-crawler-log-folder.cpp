class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack <string> st;
        for(auto op : logs){
            if((st.empty() && op == "../") || op == "./") continue;
            
            if(op == "../"){
                st.pop();
            }
            else{
                st.push(op);
            }
        }
        return st.size();
    }
};