
class CustomStack {
public:
    vector<int> st;
    stack<int> s;
    int mxSize = 0;
    CustomStack(int maxSize) {
        mxSize = maxSize;
        st.resize(maxSize+1);
        st[0] = 0;
       
    }
    
    void push(int x) {
        if(mxSize == s.size()) return;
        s.push(x);
    }
    
    int pop() {
        if(s.size() == 0) return -1;
            
        int val = s.top() + st[s.size()];
        
        st[s.size()-1] += st[s.size()];
        st[s.size()] = 0;
        s.pop();
        return (val);
       
    }
    
    void increment(int k, int val) {
        st[min((int)s.size(),k)] += val;    
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */