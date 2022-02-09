class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack <int> st;
        int push_ptr = 0;
        int pop_ptr = 0;
        for(int i=0;i<pushed.size();++i){
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[pop_ptr]){
                st.pop();
                pop_ptr++;
            }
        }
        if(st.empty() && pop_ptr == popped.size()) return 1;
        
        return 0;
    }
};