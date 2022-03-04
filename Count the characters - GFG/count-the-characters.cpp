// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
        int getCount (string S, int N)
        {
            //code here.
            map<char,int> mp;
            for(int i=1;i<S.length();++i){
                if(S[i-1] != S[i]){
                    mp[S[i-1]]++;
                }
            }
            mp[S[S.length()-1]]++;
            int ans = 0;
            for(auto x : mp){
                if(x.second == N) ans++;
            }
            return ans;
        }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n; cin >> n;
        
        Solution ob;
        cout <<ob.getCount (s, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends