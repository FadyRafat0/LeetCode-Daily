class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<>());
        int ans = 0, cnt = 0;
        for (int i = 0; i < cost.size(); ++i) {
            ++cnt;
            if (cnt == 3) {
                cnt = 0;
                continue;
            }
            ans += cost[i];
        }
        return ans;
    }
};