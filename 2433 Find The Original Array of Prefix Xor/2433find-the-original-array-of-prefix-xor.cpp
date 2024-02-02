class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> v;
        v.push_back(pref.front());
        for (int i = 1; i < pref.size(); i++)
            v.push_back(pref[i] ^ pref[i - 1]);
        return v;
    }
};