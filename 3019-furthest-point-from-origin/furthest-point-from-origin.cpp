class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0;
        int n = moves.size();
        for (auto &c : moves) {
            if (c == 'L') ++L;
            else if (c == 'R') ++R;
        }
        int rem = n - L - R;
        return abs(R - L) + rem;
    }
};