class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i = 0; i <= 11; ++i) {
            for (int j = 0; j <= 59; ++j) {
                if (__builtin_popcount(i) + __builtin_popcount(j) == turnedOn) {
                    string cur = to_string(i);
                    cur += ":";
                    if (j < 10) cur += "0";
                    cur += to_string(j);
                    ans.push_back(cur);
                }
            }
        }   
        return ans;
    }
};