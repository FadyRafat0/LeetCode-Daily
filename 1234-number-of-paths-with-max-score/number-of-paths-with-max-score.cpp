class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, {-1e9, 0}));

        vector<int> dx = {0, -1, -1}, dy = {-1, -1, 0};

        auto apply = [&](pair<int, int> &x, pair<int, int> y) {
            if (x.first > y.first) return;
            if (x.first == y.first) x.second += y.second, x.second %= (int)1e9 + 7;
            else x = y;
        };

        dp[n - 1][m - 1] = {0, 1};
        for (int x = n - 1; x >= 0; --x) {
            for (int y = m - 1; y >= 0; --y) {
                for (int k = 0; k < 3; ++k) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx >= 0 && ny >= 0 && board[nx][ny] != 'X') {
                        auto cur = dp[x][y];
                        if (nx > 0 || ny > 0) cur.first += board[nx][ny] - '0';
                        apply(dp[nx][ny], cur);
                    }
                }
            }
        }

        // E23
        // 2X2
        // 12S
        return vector<int>{max(0, dp[0][0].first), dp[0][0].second};
    }
};