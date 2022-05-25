class Solution {
public:
    bool lis(vector<int> v){
        vector<int> pseudo_list;
        int len = 0;
        for(auto &x : v){
            auto itr = lower_bound(pseudo_list.begin(),pseudo_list.end(),x);
            if(itr == pseudo_list.end()){
                len++;
                pseudo_list.push_back(x);
            }
            else{
                *itr = x;
            }
        }
        return (len > 2) ?(true) : false;
    }
    bool increasingTriplet(vector<int>& nums) {
        int one = INT_MAX;
        int two = INT_MAX;
        for(auto &x : nums){
            if(x < one){
                one = x;
                continue;
            }
            if(x < two && x > one){
                two = x;
                continue;
            }
            if(one < two && two < x){
                return true;
            }
            
        }
        return false;
    }
};