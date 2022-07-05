class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if(num % 3 != 0) return ans;
        long long num1 = (num - 3)/3;
        ans.push_back(num1);
        ans.push_back(num1 + 1);
        ans.push_back(num1 + 2);
        return ans;
        
    }
};
