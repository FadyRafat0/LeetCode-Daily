class Solution {
public:
    int lengthOfLastWord(string s) {
        int counter = 0;
        bool check = false;
        for (int i = s.size() - 1;i>= 0; i--)
        {
            if (s[i] == ' ' && check)
                break;
            if (s[i] != ' ')
            {
                check = true;
                counter++;
            }
        }
        return counter;
    }
};