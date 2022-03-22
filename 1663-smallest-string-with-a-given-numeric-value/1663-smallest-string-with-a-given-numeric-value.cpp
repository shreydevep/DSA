class Solution {
public:
    string getSmallestString(int n, int k) {
        priority_queue<char,vector<char>,greater<char>> pq;
        int curr = 0;
        while(k > 0){
            for(char ch='z';ch >= 'a';ch--){
                int val = ch-'a' + 1;
                if(k >= val){
                    k -= val;
                    pq.push(ch);
                    break;
                }
                
            }
        }
        string ans;
         while(pq.size() < n){
            auto ch = pq.top();
             pq.pop();
            if(ch == 'a'){
                ans += ch;
                n -= 1;
                continue;
            }
            ch--;
            pq.push(ch);
            pq.push('a');
        }
        while(pq.size() > n){
            auto ch1 = pq.top();
            pq.pop();
            
            auto ch2 = pq.top();
            pq.pop();
            
            
            int diff1 = ch1 - 'a';
            int diff2 = 'z' - ch2;
            
            int diff = min(diff1,diff2);
            
            ch1 -= diff;
            ch2 += diff;
            if(diff1 == 0){
                ans += ch1;
                
            }
            pq.push(ch1);
            pq.push(ch2);
        }
       
        
        while(pq.size() > 1){
            auto ch1 = pq.top();
            pq.pop();
            
            if(ch1 == 'a'){
                ans += ch1;
                continue;
            }
            
            auto ch2 = pq.top();
            pq.pop();
            if(ch2 == 'z'){
                ans += ch1;
                ans += ch2;
                
                break;
            }
            
            int diff1 = ch1-'a';
            int diff2 = 'z' - ch2;
            
            int diff = min(diff1,diff2);
            
            ch1 -= diff;
            ch2 += diff;
            if(diff1 > diff || diff2 == 0){
                pq.push(ch1);
            }
            
            pq.push(ch2);
        }
        
        
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
            
        
            
    }
};