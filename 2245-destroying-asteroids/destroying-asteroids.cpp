class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long cur = mass;
        sort(asteroids.begin(), asteroids.end());
        for (auto &i : asteroids) {
            if (i > cur) return 0;
            cur += i;
        }
        return 1;
    }
};