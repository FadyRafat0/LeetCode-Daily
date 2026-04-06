class Solution {
public:
    int robotSim(vector<int>& a, vector<vector<int>>& b) {
        set<pair<int, int>> st;
        for (int i = 0; i < b.size(); ++i) {
            st.insert({b[i][0], b[i][1]});
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        int x = 0, y = 0, dir = 0, ans = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == -1) dir = (dir + 1) % 4;
            else if (a[i] == -2) dir = (dir - 1 + 4) % 4;
            else {
                while (a[i]-- && st.find({x + dx[dir], y + dy[dir]}) == st.end()) {
                    x += dx[dir];
                    y += dy[dir];
                }
                ans = max(ans, x * x + y * y);
            }
        }

        return ans;
    }
};