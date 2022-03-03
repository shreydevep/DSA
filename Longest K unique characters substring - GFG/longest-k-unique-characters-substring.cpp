// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        // your code here
        map<char,int> freq;
        int curr = 0;
        int len = 0;
        int ans = -1;
        for(int i=0;i<s.length();++i){
            
            freq[s[i]]++;
            if(freq.size() > k){
                ans = max(ans,i - curr);
            }
            while(curr <= i && freq.size() > k){
                freq[s[curr]]--;
                if(freq[s[curr]] == 0){
                    freq.erase(s[curr]);
                }
                curr++;
            }
            
        }
        if(freq.size() == k){
            ans = max(ans,(int)s.length()-curr);
        }
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends