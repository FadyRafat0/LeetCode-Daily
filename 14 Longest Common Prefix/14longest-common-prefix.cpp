class Solution {
public:
    string longestCommonPrefix(vector<string> strs) {
        if (strs.size() == 1)
            return strs.at(0);
    
        string temp = "";
        int j = 0;
        while (true)
        {
            bool check = true;
            for (int i = 0; i < strs.size() - 1; i++)
            {
                if (j == strs.at(i).size() || strs.at(i)[j] != strs.at(i + 1)[j])
                {
                    check = false;
                    break;
                }
            }
            if (check)
                temp += strs[0][j];
            else
                break;
            j++;
        }
        return temp;
    }
};