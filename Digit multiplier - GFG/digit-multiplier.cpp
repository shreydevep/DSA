// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    map<int,int> mp;
    string getSmallest(long long N) {
        if(N == 1) return "1";
        for(int i=9;i>=2;--i){
            while(N % i == 0){
                mp[i]++;
                N /= i;
                
            }
        }
        if(N != 1) return "-1";
        
        string ans;
        for(auto x : mp){
            while(mp[x.first]--)
                ans += to_string(x.first);
        }
        return ans;
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
        cout << ob.getSmallest(N) << endl;
    }
    return 0;
}  // } Driver Code Ends