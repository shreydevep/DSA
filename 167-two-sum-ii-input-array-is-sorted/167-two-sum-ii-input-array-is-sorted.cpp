class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> temp(2,0);
        int i=0;
        int j=numbers.size() - 1;
        
        while(i < j){
            int sum = numbers[i] + numbers[j];
            
            if(sum == target){
                temp[0] = i+1;
                temp[1] = j+1;
                return temp;
            }
            else if(sum < target){
                i++;
            }
            else{
                j--;
            }
        }
        return temp;
    }
};