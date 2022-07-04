class MajorityChecker {
public:
    vector<int> arr;
    unordered_map<int,vector<int>> mp;
    MajorityChecker(vector<int>& a) {
        for(int i=0;i<a.size();++i){
            mp[a[i]].push_back(i);
        }
        arr = a;
    }
    
    int query(int left, int right, int threshold) {
        for(auto times=0;times<10;++times){
            auto val = arr[left + rand() % (right - left + 1)];
            
            if(mp[val].size() < threshold) continue;
            
            auto ll = lower_bound(mp[val].begin(),mp[val].end(),left);
            auto rr = lower_bound(mp[val].begin(),mp[val].end(),right);
            if(rr == mp[val].end()) rr--;
            if(*rr > right) rr--;
            auto freq = (rr - ll + 1);
            
            if(freq >= threshold) return val;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */