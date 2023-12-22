class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = s.size() -1; i >= 0; i--)
        {
            if (s[i] == 'I')
            {
                if (i == s.size() -1)
                {
                    ans += 1;
                    continue;
                }
                if (s[i + 1] == 'V' || s[i + 1] == 'X')
                    ans--;
                else
                    ans++;
            }
            else if (s[i] == 'V')
                ans += 5;
            else if (s[i] == 'X')
            {
                if (i == s.size() -1)
                {
                    ans += 10;
                    continue;
                }
                if (s[i + 1] == 'L' || s[i + 1] == 'C')
                    ans -= 10;
                else
                    ans += 10;
            }
            else if (s[i] == 'L')
                ans += 50;
            else if (s[i] == 'C')
            {
                if (i == s.size() -1)
                {
                    ans += 100;
                    continue;
                }
                if (s[i + 1] == 'D' || s[i + 1] == 'M')
                    ans -= 100;
                else 
                    ans += 100;
            }
            else if (s[i] == 'D')
                ans += 500;
            else if (s[i] == 'M')
                ans += 1000;
        }
        return ans;
    }
};