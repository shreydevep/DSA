class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack <int> left;
        vector <int> cleft((int)heights.size(),0);
        vector <int> cright((int)heights.size(),0);
        stack <int> right;
        cleft[0] = 0;
        for(int i=0;i<heights.size();++i){
            while(left.size() != 0 && heights[left.top()] >= heights[i]){
                cleft[i] += (cleft[left.top()] + 1);
                left.pop();
            }
            left.push(i);
        }
        cright[heights.size()-1] = 0;
         for(int i=heights.size()-1;i>= 0;--i){
            while(right.size() != 0 && heights[right.top()] > heights[i]){
                cright[i] += (cright[right.top()] + 1);
                right.pop();
            }
            right.push(i);
        }
        int ans = 0;
        for(int i=0;i<heights.size();++i){
            ans = max((cleft[i] + cright[i] + 1)*heights[i],ans);
        }
        return ans;
    }
};