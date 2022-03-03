// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int distinct(vector<vector<int>> M, int N)
    {
        // code here
        set<int> st;
        for(int i=0;i<N;++i){
            st.insert(M[0][i]);
        }
        
        for(int i=1;i<N;++i){
            set<int> temp;
            for(int j=0;j<N;++j){
                if(st.find(M[i][j]) != st.end()) temp.insert(M[i][j]);
            }
            st.clear();
            for(auto x : temp){
                st.insert(x);
            }
        }
        
        return (int)st.size();
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> M(N, vector<int>(N, 0));
        for(int i = 0;i < N*N; i++)
            cin>>M[i/N][i%N];
        
        Solution ob;
        cout<<ob.distinct(M, N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends