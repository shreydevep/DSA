class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int push_ptr = 0;
        int pop_ptr = 0;
        stack<int> st;
        while(push_ptr < pushed.size() && pop_ptr < popped.size()){
            if(st.empty()){
                st.push(pushed[push_ptr]);
                push_ptr++;
            }
            else{
                if(st.top() == popped[pop_ptr]){
                    st.pop();
                    pop_ptr++;
                    continue;
                }
                
                st.push(pushed[push_ptr]);
                push_ptr++;
            }
        }
        
        while(push_ptr < pushed.size()){
            st.push(pushed[push_ptr]);
            push_ptr++;
        }
        
        while(!st.empty() && pop_ptr< popped.size() && st.top() == popped[pop_ptr]){
            st.pop();
            pop_ptr++;
        }
        
        return (!st.size());
        
        
    }
};