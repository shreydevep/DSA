class Solution {
public:
    int candy(vector<int>& ratings) {
       int candies = 0;
    int size = ratings.size();
    vector<int> lefttoright(size, 1);
    vector<int> righttoleft(size, 1);
    
    for (auto l = 1; l<size; ++l)
        if (ratings[l] > ratings[l-1])
            lefttoright[l] = lefttoright[l-1] + 1;
    
    for (auto r = size-2; r>=0; --r)
        if (ratings[r] > ratings[r+1])
            righttoleft[r] = righttoleft[r+1] + 1;
            
    for (auto i = 0; i<size; ++i)
        candies += max(lefttoright[i], righttoleft[i]);
        
    return candies;
    }
};