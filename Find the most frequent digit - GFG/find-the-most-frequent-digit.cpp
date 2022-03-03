// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int solve(string s);
int main()
{
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
        
    }
}// } Driver Code Ends



int solve(string N)
{
   unordered_map<int,int> mp;
   for(int i=0;i<N.size();i++){
        mp[N[i]-'0']++;
    }
    int element=-1;
    int max=-10;
    for(int i=9;i>=0;i--){
        if(mp[i]>max && mp[i]>=1){
            max=mp[i];
            element=i;
        }
    }
    return element;
    
    
}
