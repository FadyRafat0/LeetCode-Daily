class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int n = tickets.size();
        for (int i = 0; i < n; ++i) q.push(i);

        int done = 0;
        while (q.size()) {
            auto u = q.front();
            q.pop();
            ++done;
            --tickets[u];
            if (tickets[u]) {
                q.push(u);
            }
            else if (k == u) {
                return done;
            }
        }
        return done;
    }
};