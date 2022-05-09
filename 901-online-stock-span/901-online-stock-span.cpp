
/**
    Basic idea is go back upto the day when price at ith day is greater than price at current day.
    
    Because for upcoming prices current day will store the consecutive required days
    
    day 0 {100001,0} -> {Boundary Price, Consecutive days before current day and including current day}
    day 1 |{100,1},{100001,0}|
    day 2 |{80,1},{100,1},{100001,0}|
    day 3 |{60,1},{80,1},{100,1},{100001,0}|
    day 4 |{70,2},{80,1},{100,1},{100001,0}| Popped till price at stack top is less than current price(on day 4)
    day 5 |{60,1},{70,2},{80,1},{100,1},{100001,0}|
    day 6 |{75,4},{80,1},{100,1},{100001,0}|
    day 7 |{85,6},{100,1},{100001,0}|
    
    
    
    
**/
class StockSpanner {
public:
    stack <pair<int,int>> left;
    int sz;
    StockSpanner() {
        sz = 0;
        left.push({10001,0}); //Max Boundary for intial day 0
    }
    
    int next(int price) {
        sz++;//sz represent current day
        pair<int,int> ele; //last boundary point where price is greater than current day price
        if(!left.empty()){
            ele = left.top(); 
            
        }
        while(!left.empty() && ele.first <= price){
            left.pop();
            if(!left.empty())
                ele = left.top();
        }
        int len = (sz - ele.second); // current day - last boundary point day 
        left.push({price,sz});
        return len;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */