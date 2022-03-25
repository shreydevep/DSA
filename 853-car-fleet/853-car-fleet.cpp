class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<long long,long long>> v;
        for(int i=0;i<position.size();++i){
            v.push_back({position[i],speed[i]});
        }
        
        sort(v.begin(),v.end());
        int fleets = 1;
        int slowCar = v.size()-1;
        
        for(int i=v.size()-2;i>=0;--i){
            if(v[i].second < v[slowCar].second){
                fleets++;
                slowCar = i;
                continue;
            }
            else{
                //int timeSlowCar = (target-v[slowCar].first)/(v[slowCar].second);
                //int timeCurrCar = (target-v[i].first)/v[i].second;
                    // timeSlowCar < timeCurrCar
                if(((long long)target-v[slowCar].first)*(v[i].second) < ((long long)target-v[i].first)*(v[slowCar].second)){
                    //Can't Catup Up
                    fleets++;
                    slowCar = i;
                }
            }
        }
        return fleets;
    }
};