class Solution {
public:
    int minOperations(string s) {
        int dp[2]{};

        for (int i = 0; i < s.size(); ++i) {
            if ((i & 1) && s[i] != '0')
                dp[0]++;
            else if (!(i & 1) && s[i] != '1')
                ++dp[0];
                
            if ((i & 1) && s[i] != '1')
                ++dp[1];
            else if (!(i & 1) && s[i] != '0')
                ++dp[1];
        }
        return min(dp[0], dp[1]);
    }
};