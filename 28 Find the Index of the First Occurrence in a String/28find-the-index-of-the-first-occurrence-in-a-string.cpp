class Solution {
public:
    int strStr(string s, string n) {
        auto found = s.find(n);
        if (found > s.size())
            return -1;
        else    
            return found;
    }
};