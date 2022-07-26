class Solution {
public:
    int numericalValue(string &s){
        string num;
        for(auto &x : s){
            num += to_string(x - 'a');
        }
        return stoi(num);
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return ((numericalValue(firstWord) + numericalValue(secondWord)) == numericalValue(targetWord));
    }
};