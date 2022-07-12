class Solution {
public:
    vector<int> convertToVector(string preorder){
        istringstream ss(preorder);
        string token;
        
        vector<int> res;
        while(std::getline(ss, token, ',')) {
            if(token == "#"){
                res.push_back(-1);
            }
            else{
                res.push_back(stoi(token));
            }
        } 
       
        return res;
    }
    bool isValidSerialization(string preorder) {
        vector<int> res = convertToVector(preorder);
       
        queue<int> st;
        if(res[0] != -1)
        st.push(res[0]);
        int i = 1;
        while(!st.empty()){
            auto par = st.front();
            st.pop();
            
            if(i < res.size() && res[i] != -1){ 
                st.push(res[i]);
                
            }
            //cout <<par<<" "<< i <<" ";
            i++;
            if(i < res.size() && res[i] != -1) {
                st.push(res[i]);
            }
            //cout << i <<"\n";
            i++;
        }
        
        return (i == res.size());
        
    }
};



