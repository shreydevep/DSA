// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int maxChars (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << maxChars (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int maxChars (string S)
{
    map<char,int> mp;
    int ans = 0;
    bool flag = 0;
    for(int i=0;i<S.length();++i){
        if(mp.find(S[i]) == mp.end()){
            mp[S[i]] = i;
        }
        else{
            flag = 1;
            ans = max(ans,i-mp[S[i]]-1);
            mp[S[i]] = min(mp[S[i]],i);
        }
    }
    if(!flag) return -1;
    return ans;
    // your code here
}