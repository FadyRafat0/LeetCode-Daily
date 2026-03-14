class Solution {
public:
    vector<string> ALL;
    void rec(string &s, int i) {
        if (i == 0) {
            ALL.push_back(s); 
            return;
        } 
        for (char c = 'a'; c <= 'c'; ++c) {
            if (s.size() && s.back() == c) continue;
            s += c;
            rec(s, i - 1);
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string s;
        rec(s, n);
        if (ALL.size() < k) return "";

        return ALL[k - 1];
    }
};