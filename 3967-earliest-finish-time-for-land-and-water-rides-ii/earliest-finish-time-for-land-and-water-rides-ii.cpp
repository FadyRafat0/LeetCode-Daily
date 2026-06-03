class Solution {
public:
    int solve(vector<int> &start1, vector<int> &d1, vector<int> &start2, vector<int> d2) {
        int min_finish = 1e9;
        for (int i = 0; i < start1.size(); ++i) 
            min_finish = min(min_finish, start1[i] + d1[i]);

        int ans = 1e9;
        for (int i = 0; i < start2.size(); ++i) {
            ans = min(ans, max(min_finish, start2[i]) + d2[i]);
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& start_a, vector<int>& d_a, vector<int>& start_b, vector<int>& d_b) {
        int a = solve(start_a, d_a, start_b, d_b);
        int b = solve(start_b, d_b, start_a, d_a);
        return min(a, b);
    }
};