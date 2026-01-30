class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();

        vector<vector<long long>> dis(26, vector<long long>(26, 1e9));
        for (int i = 0; i < original.size(); i++) {
            int a = original[i] - 'a', b = changed[i] - 'a';
            dis[a][b] = min(dis[a][b], 1ll * cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            dis[k][k] = 0;
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            int a = source[i] - 'a', b = target[i] - 'a';
            if (dis[a][b] == 1e9) return -1;
            ans += dis[a][b];
        }
        return ans;
    }
};