#define pii pair<int,pair<int,int>>
class FreqStack {
public:
    int clk;
    
    class Compare{
        public:
        bool operator()(const pii &a, const pii &b){
            if((a.second).first == (b.second).first){  
                        return (a.second).second < (b.second).second;
            }
            else{
                return (a.second).first < (b.second).first;
            }
                        
        }
    };
    priority_queue<pii,vector<pii>,Compare> pq;
    unordered_map<int,int> mp;
    FreqStack() {
        
        clk = 0;
        
    }
    
    void push(int val) {
        clk++;
        mp[val]++;
        pq.push({val,{mp[val],clk}});
    }
    
    int pop() {
        int temp = (pq.top()).first;
        mp[(pq.top()).first]--;
        pq.pop();
        return temp;
    }
};


/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */