class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        deque<int> dq;
        dq.emplace_back(0);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '1') continue;
            while (dq.size() && i - dq.front() > maxJump) dq.pop_front();
            if (dq.size() && i - dq.front() >= minJump) dq.emplace_back(i);
        }
        return (dq.size() && dq.back() == s.size() - 1);
    }
};