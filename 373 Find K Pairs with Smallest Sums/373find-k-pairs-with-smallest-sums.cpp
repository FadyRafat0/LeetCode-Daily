class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        for (int i = 0; i < a.size(); i++) {
            pq.push({a[i] + b[0], i, 0});
        }

        vector<vector<int>> ans;
        while (k--) {
            auto x = pq.top();
            pq.pop();
            ans.push_back({a[x[1]], b[x[2]]});
            if (x[2] != b.size() - 1) {
                pq.push({a[x[1]] + b[x[2] + 1], x[1], x[2] + 1});
            }
        }    
        return ans;
    }
};