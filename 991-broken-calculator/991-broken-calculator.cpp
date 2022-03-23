class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int op = 0;

        while(startValue < target){
       
           if(target % 2 != 0) target++;
           else target /= 2;
            op++;
        }
        int diff = (startValue - target);
        if(diff > 0){
            op += diff;
        }
        
        
        
        return op;
    }
};

