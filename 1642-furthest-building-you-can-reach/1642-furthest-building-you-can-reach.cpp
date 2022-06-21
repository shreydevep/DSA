class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int ans = 0;
        multiset<int> usedBricks;
     
        for(int i=1;i<heights.size();++i){
           
            
            if(heights[i] > heights[i-1]){
                //Ladder or Brick
                int req = abs(heights[i]-heights[i-1]);
                if(ladders > 0){
                    usedBricks.insert(req);
                    ladders--;
                    ans = i;
                }
                else{
                    auto itr = usedBricks.begin();
                    
                   
                    if(usedBricks.size() > 0 && *itr <= bricks && *itr <= req){
                        bricks -= (*itr);
                        usedBricks.erase(usedBricks.find(*itr));
                        usedBricks.insert(req);
                        ans = i;
                    }
                    else if(req <= bricks){
                        bricks -= req;
                        ans = i;
                    }
                    else{
                        break;
                    }
                }
                    
            }
            else{
                ans = i;
            }
        }
        return ans;
    }
};