class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> left;
        vector <int> res;
        for(int i=0;i<asteroids.size();++i){
            if(asteroids[i] < 0){
                while(!left.empty()){
                    if(left.top() < 0) break;
                    else if(left.top() < abs(asteroids[i]))
                        left.pop(); 
                    else{
                        break;
                    }
                }
                if(!left.empty() && left.top() == abs(asteroids[i])){
                    left.pop();
                }
                else if(left.empty() || left.top() < 0){
                    left.push(asteroids[i]);
                }
            }
            else{
                left.push(asteroids[i]);
            }
        }
        //reverse(res.begin(),res.end());
        while(!left.empty()){
            res.push_back(left.top());
            left.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};