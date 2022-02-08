class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = -1;
        int cnt1 = 0;
        
        int ele2 = -1;
        int cnt2 = 0;
        
        for(int x : nums){
            if(ele1 == x) cnt1++;
            else if(ele2 == x) cnt2++;
            else if(cnt1 == 0) {
                ele1 = x;
                cnt1++;
            }
            else if(cnt2 == 0){
                ele2 = x;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        int cnt3 = 0;
        for(auto x : nums){
            if(ele1 == x) cnt1++;
            
            if(ele2 == x) cnt2++;
            if(-1 == x) cnt3++;
        }
        
    
        vector <int> res;
        if(ele1 != -1 && cnt1 > nums.size()/3) res.push_back(ele1);
        
        if(ele2 != -1 && cnt2 > nums.size()/3) res.push_back(ele2);
        
        if(cnt3 > nums.size()/3) res.push_back(-1);
        
        return res;
    
    }
};