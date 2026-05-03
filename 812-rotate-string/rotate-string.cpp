class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return 0;
        s += s;
        for (int i = 0; i < s.size(); ++i) {
            if (s.substr(i, goal.size()) == goal)
                return 1;
        }
        return 0;
    }
};