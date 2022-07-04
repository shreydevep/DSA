class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> cleft;
        cleft.push(0);
        vector<int> left(heights.size()+1);
        for(int i=1;i<=heights.size();++i){
           
            while(cleft.size() > 1 && heights[cleft.top()-1] >= heights[i-1]){
                cleft.pop();
            }
            left[i] = (i-cleft.top());
            cleft.push(i);
        }
        stack<int> cright;
        cright.push(heights.size()+1);
        vector<int> right(heights.size()+1);
        for(int i=heights.size();i>=1;--i){
            while(cright.size() > 1 && heights[cright.top()-1] >= heights[i-1]){
                cright.pop();
            }
            right[i] = (cright.top()-i);
            cright.push(i);
        }
        int ans = 0;
        for(int i=1;i<=heights.size();++i){
            ans = max(ans,(right[i]+left[i]-1)*heights[i-1]);
        }
        return ans;
        
    }
};