class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long curr = mass;
        sort(asteroids.begin(),asteroids.end());
        for(auto as : asteroids){
            if(curr >= as){
                curr += as;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
};