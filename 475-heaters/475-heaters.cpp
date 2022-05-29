class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ans = 0;
        for(int i=0;i<houses.size();++i){
            auto itrLeft = lower_bound(heaters.begin(),heaters.end(),houses[i]+1);
            
            if(itrLeft != heaters.begin())
                itrLeft--;
            
            auto itrRight = lower_bound(heaters.begin(),heaters.end(),houses[i]);
            
            if(itrRight != heaters.end()){
                int val = min(abs(*itrLeft-houses[i]),abs(*itrRight-houses[i]));
                ans = max(ans,val);
            }
            else{
                ans = max(ans,abs(*itrLeft-houses[i]));
            }
        }
        return ans;
    }
};