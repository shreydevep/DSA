class Solution {
public:
    static bool compare(vector<int> a,vector<int> b){
        return (a[1] <= b[1]);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int ans = 0;
        while(truckSize > 0 && boxTypes.size() > 0){
            auto val = boxTypes.back();
            if(truckSize >= val[0]){
                truckSize -= val[0];
                ans += (val[0]*val[1]);
                boxTypes.pop_back();
            }
            else{
                ans += (truckSize*val[1]);
                truckSize = 0;
            }
        }
        return ans;
    }
};