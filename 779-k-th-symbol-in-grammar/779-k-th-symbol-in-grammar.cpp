class Solution {
public:
    int kthGrammar(int n, int k) {
       if(n == 1 && k  == 1) return 0;
        int total = (1 << (n-1));
        if(k <= total/2){
            return kthGrammar(n-1,k);
        }
        else{
            return !kthGrammar(n-1,k - (total/2));
        }
        
    }
};
