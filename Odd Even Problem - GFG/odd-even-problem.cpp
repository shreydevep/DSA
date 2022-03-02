// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string oddEven(string S) {
        vector<int> freq(27,0);
        
        for(auto ch : S){
            freq[ch - 'a' + 1]++;
        }
        
        int X = 0;
        int Y = 0;
        for(int i=1;i<=26;++i){
            if((i % 2 == 0) && freq[i] > 0 && (freq[i] % 2 == 0)) X++;
            
            if((i % 2 != 0) && freq[i] > 0 && (freq[i] % 2 != 0)) Y++;
        }
        
        if(((X+Y) % 2) == 0) return "EVEN";
        else return "ODD";
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.oddEven(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends