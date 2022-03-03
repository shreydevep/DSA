// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int isLuckyOrNot(long long N) {
        // code here
        vector<int> v;
        while(N > 0){
            v.push_back(N % 10);
            N /= 10;
        }
        
        reverse(v.begin(),v.end());
        unordered_set<long long> st;
        for(int i=0;i<v.size();++i){
            for(int j=i;j<v.size();++j){
                long long product = 1;
                for(int k=i;k<=j;++k){
                    product *= v[k];    
                }
                if(st.find(product) != st.end()) return 0;
                st.insert(product);
                
            }
            
           
        }
        
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isLuckyOrNot(N) << endl;
    }
    return 0;
}  // } Driver Code Ends