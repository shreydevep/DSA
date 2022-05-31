class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 ) return 0;
        int ans = kthGrammar(n-1,(k+1)/2);
        
        if(ans == 0) {
            return (k&1) ? 0 : 1;
        }
        return (k&1) ? 1 : 0;
        
    }
};
