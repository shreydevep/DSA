class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res, cur, cur2;
        for (int i: A) {
            cur2 = {i};
            for (int j: cur) cur2.insert(i|j);
            for (int j: cur2) res.insert(j);
            cur = cur2;
            cur2.clear();
        }
        return res.size();
    }
};