class Solution {
public:
    multiset<double> minSet;
    multiset<double> maxSet;
    void addNum(int num,int k){
            int sz = k;
            if(maxSet.size() > 0 && *maxSet.rbegin() > num){
                maxSet.insert(num);
            }
            else if(minSet.size() > 0 && *minSet.begin() <= num){
                minSet.insert(num);
            }
            else{
                maxSet.insert(num);
            }
            int maxSz = (sz+1)/2;
            int minSz = sz/2;
            
            while(maxSet.size() > maxSz){
                auto itr = maxSet.end();
                itr--;
                minSet.insert(*itr);
                maxSet.erase(itr);
            }
           while(minSet.size() > minSz){
               maxSet.insert(*minSet.begin());
               minSet.erase(minSet.begin());
           }
    }
    void delNum(int num){
        if(maxSet.find(num) != maxSet.end()){
            maxSet.erase(maxSet.find(num));
        }
        else{
            if(minSet.find(num) != minSet.end()){
                minSet.erase(minSet.find(num));
            } 
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        int j=k-2;
        for(int z=i;z<=j;++z){
            addNum(nums[z],z-i+1);
        }
        j++;
        vector<double> ans;
        while(j < nums.size() && (j-i)<k){
            addNum(nums[j],k);
            if((k % 2) != 0){
                
                ans.push_back(*maxSet.rbegin());
            }
            else{
                double md = (*maxSet.rbegin() + *minSet.begin());
                md /= 2.0;
                ans.push_back(md);
            }
            delNum(nums[i]);
            i++;
            j++;
        }
        return ans;
    }
};