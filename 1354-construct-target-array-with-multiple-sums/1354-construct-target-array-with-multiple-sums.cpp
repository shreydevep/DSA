class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long total = 0;
        for(auto &x : target){
            total += x;
            pq.push(x);
        }
        while(pq.top() != 1){
            auto val = pq.top();
            pq.pop();
            if((total - val) == 1) return true;
            if(total - val <= 0) return false;
            int rem = val % (total - val);
            total = total - val + rem;
            if(rem == 0 || rem == val) return false;
            pq.push(rem);
        }
        return true;
    }
};