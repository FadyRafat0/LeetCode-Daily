class Solution {
public:
    bool judgeCircle(string moves) {
        int sum_a = 0, sum_b = 0;
        for (auto &c : moves) {
            if (c == 'R') ++sum_a;
            else if (c == 'L') --sum_a;
            else if (c == 'U') ++sum_b;
            else --sum_b;
        }
        return (!sum_a && !sum_b);
    }
};