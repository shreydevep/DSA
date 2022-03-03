// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        
        
        string UncommonChars(string A, string B)
        {
            // code here
            vector<pair<bool,bool>> freq(26);
            for(auto ch : A){
                freq[ch-'a'] = {1,0};
            }
            
            for(auto ch : B){
                if(freq[ch-'a'].second == 0){
                    freq[ch-'a'] = {!freq[ch-'a'].first, 1};
                }
            }
            string ans;
            for(int i=0;i<26;++i){
                if(freq[i].first)
                    ans += (i + 'a');
            }
            if(ans.length() == 0) ans = "-1";
            return ans;
            
        }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends