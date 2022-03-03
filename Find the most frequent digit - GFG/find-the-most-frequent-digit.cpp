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
    vector<int> freq(10,0);
    for(auto ch : N){
        freq[ch-'0']++;
    }
    int curr = 0;
    
    for(int i=0;i<=9;++i){
        if(freq[curr] <= freq[i]) curr = i;
    }
    return curr;
    
    
}
