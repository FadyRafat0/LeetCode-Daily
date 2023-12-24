class Solution {
public:
    int minOperations(string s) {
        int counter = 0;
        int counter2 = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] == '0')
                    counter++;
            }
            else
            {
                if (s[i] == '1')
                    counter++;
            }

            if (i % 2 == 0)
            {
                if (s[i] == '1')
                    counter2++;
            }
            else
            {
                if (s[i] == '0')
                    counter2++;
            }
        }
        int ans = min(counter, counter2);
        return ans;
    }
};