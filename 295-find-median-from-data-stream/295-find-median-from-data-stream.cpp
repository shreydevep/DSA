class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int sz;
    MedianFinder() {
        sz = 0;
        
    }
    
    void addNum(int num) {
        sz++;
        int maxSz = (sz+1)/2;
        int minSz = sz/2;
        if(!maxHeap.empty() && maxHeap.top() > num){
            maxHeap.push(num);
        }
        else if(!minHeap.empty() && minHeap.top() <= num){
            minHeap.push(num);
        }
        else{
            maxHeap.push(num);
        }
        if(maxHeap.size() > maxSz){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
        if(minHeap.size() > minSz){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(sz % 2 != 0){
            return (double)(maxHeap.top());
        }
        else{
            return (double)(maxHeap.top() + minHeap.top())/2.0;
        }
       
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */