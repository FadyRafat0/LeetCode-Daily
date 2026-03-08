class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<bool> vis(1<<n);
        for (auto &i : nums) {
            int x = 0;
            for (int j = 0; j < n; ++j) {
                if (i[j] == '1')
                    x |= (1 << (n - j - 1));
            }
            vis[x] = 1;
        }
        
        for (int i = 0; i < (1<<n); ++i) {
            if (vis[i]) continue;

            int x = i;
            string cur = "";
            for (int j = 0; j < n; ++j) {
                if (x % 2) cur += "1";
                else cur += "0";
                x /= 2; 
            }

            reverse(cur.begin(), cur.end());

            return cur;
        }

        return "";
    }
};