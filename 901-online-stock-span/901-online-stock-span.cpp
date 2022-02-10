
class StockSpanner {
public:
    stack <pair<int,int>> left;
    int sz;
    StockSpanner() {
        sz = 0;
        left.push({10001,0});
    }
    
    int next(int price) {
        sz++;
        pair<int,int> ele;
        if(!left.empty()){
            ele = left.top();
        }
        while(!left.empty() && ele.first <= price){
            left.pop();
            if(!left.empty())
                ele = left.top();
        }
        int len = (sz - ele.second);
        left.push({price,sz});
        return len;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */