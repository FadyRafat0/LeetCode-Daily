class Solution {
public:
    int maxScore(string s) {
            int ones = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1')
            ones++;
    
    int zeros = 0;
    int ans = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '0')
            zeros++;
        else
            ones--;

        ans = max(ans, zeros + ones);
    }
    return ans;
    }
};