// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int isPossible (string S)
{
    // your code here
    unordered_map<char,int> mp;
    
    for(auto x : S){
        mp[x]++;
    }
    int odd = 0;
    for(auto x : mp){
        if(x.second % 2 != 0) odd++;
    }
    
    if(odd <= 1) return 1;
    
    return 0;
}