class Solution {
public:
    string compare_str(string num){
        set <char> st;
        long long mx = (1ll << 31);
        mx--;
        for(int i=num.size()-1;i>=0;--i){
            if(st.empty()){
                st.insert(num[i]);
                continue;
            }
            bool flag = 0;
            char curr;
            for(auto x : st){
                if(x > num[i]){
                    flag = 1;
                    curr = x;
                    break;
                }
            }
            //cout << curr <<"\n";
            if(flag){
                string temp = num;
                for(int j=i+1;j<num.size();++j){
                    if(temp[j] == curr){
                        swap(temp[j],temp[i]);
                        break;
                    }
                }
                
                sort(temp.begin()+i+1,temp.end());
                //cout << temp <<"\n";
                long long tmp = stoll(temp);
                if(tmp <= mx){
                    return temp;
                }
                
            }
            st.insert(num[i]);    
        }
        return "-1";
    }
    int nextGreaterElement(int n) {
        int ans = stoll(compare_str(to_string(n)));
        return ans;
    }
};