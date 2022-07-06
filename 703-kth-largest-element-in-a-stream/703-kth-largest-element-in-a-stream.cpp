class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> maxHeap;
    int sz;
    KthLargest(int k, vector<int>& nums) {
        sz = k;
        for(auto &val : nums) {
            maxHeap.push(val);
            if(maxHeap.size() > sz) maxHeap.pop();
        }
    }
    
    int add(int val) {
        maxHeap.push(val);
        if(maxHeap.size() > sz) maxHeap.pop();
        return maxHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */