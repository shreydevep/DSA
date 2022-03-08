
class CustomStack {
public:
    vector<int> st;
    int mxSize = 0;
    CustomStack(int maxSize) {
        mxSize = maxSize;
       
    }
    
    void push(int x) {
        if(mxSize == st.size()) return;
        st.push_back(x);
    }
    
    int pop() {
        if(st.size() == 0) return -1;
        int temp = st.back();
        st.pop_back();
        return temp;
       
    }
    
    void increment(int k, int val) {
        for(int i=0;i< min((int)st.size(),k);++i){
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */