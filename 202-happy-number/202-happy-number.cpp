class Solution {
public:
    bool isHappy(int n) {
        set<int> appear;
        int curr = n;
        while(1){
            
            int temp = 0;
            while(curr > 0){
                temp += ((curr%10)*(curr%10));
                curr /= 10;
            }
            
            
            curr = temp;
            
            if(appear.find(1) != appear.end()){
                return 1;
            }
            else if(appear.find(curr) != appear.end()){
                return 0;
            }
            appear.insert(curr);
            
        }
        return 0;
    }
};