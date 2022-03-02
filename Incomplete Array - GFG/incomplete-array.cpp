// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int countElements(int N, int A[]) {
        // code here
        unordered_set <int> st;
        for(int i=0;i<N;++i){
            st.insert(A[i]);
        }
        
        int mn = 1e5 + 1;
        int mx = 0;
        for(auto x : st){
            mn = min(mn,x);
            mx = max(mx,x);
        }
        int count = mx-mn + 1;
        return (count - (int)st.size());
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        Solution ob;
        cout << ob.countElements(N, A) << "\n";
    }
}  // } Driver Code Ends