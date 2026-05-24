class Solution {
public:
    vector<int> a, dp;
    int d;
    int rec(int i) {
        int &ret = dp[i];
        if (~ret) return ret;
        ret = 1;
        for (int j = i + 1; j < min(i + d + 1, (int)a.size()); ++j) {
            if (a[j] >= a[i]) break;
            ret = max(ret, rec(j) + 1);    
        }
        for (int j = i - 1; j >= max(0, i - d); --j) {
            if (a[j] >= a[i]) break;
            ret = max(ret, rec(j) + 1);
        }
        return ret;
    }
    int maxJumps(vector<int>& arr, int d) {
        a = arr;
        this->d = d;
        dp = vector<int>(a.size(), -1);
        int ans = 0;
        for (int i = 0; i < a.size(); ++i) {
            cout << rec(i) << ' ';
            ans = max(ans, rec(i));
        } 
        cout << '\n';
        return ans;
    }
};