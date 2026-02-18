class Solution {
    string s;
    int n;
public:
    int solve_one(char c) {
        int cnt = 0, ret = 0;
        for (auto &i : s) {
            if (i == c) ++cnt;
            else cnt = 0;
            ret = max(ret, cnt);
        }
        return ret;
    }
    int solve_two(char a, char b) {
        map<int, int> mp;
        mp[0] = -1;
        int sum = 0, ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != a && s[i] != b)
                mp.clear(), sum = 0, mp[0] = i;
            else {
                sum += (s[i] == a ? 1 : -1);
                if (mp.find(sum) == mp.end()) {
                    mp[sum] = i;
                }
                else {
                    ret = max(ret, i - mp[sum]);
                }
            }
        }

        return ret;
    }
    int solve_three() {
        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        vector<int> prf_a(n), prf_b(n), prf_c(n);
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            prf_a[i] = (i ? prf_a[i - 1] : 0) + (s[i] == 'a');
            prf_b[i] = (i ? prf_b[i - 1] : 0) + (s[i] == 'b');
            prf_c[i] = (i ? prf_c[i - 1] : 0) + (s[i] == 'c');
        
            int x = prf_a[i] - prf_b[i];
            int y = prf_a[i] - prf_c[i];
            if (mp.find({x, y}) != mp.end()) {
                ret = max(ret, i - mp[{x, y}]);
            }
            else {
                mp[{x, y}] = i;
            }
        }
        return ret;
    }
    int longestBalanced(string s) {
        // [a] [b] [c] [ab] [ba] [ca] [abc]

        // [i want a , b , c appear together]

        //    i want prf_a[r] - prf_a[l - 1] = prf_b[r] - prf_b[l - 1]
        //    prf_a[r] - prf_a[l - 1] = prf_c[r] - prf_c[l - 1]
        
        //    prf_a[r] - prf_b[r] (x) = prf_a[l - 1] - prf_b[l - 1]
        //    prf_a[r] - prf_c[r] (y) = prf_a[l - 1] - prf_c[l - 1]
        
        n = s.size();
        this->s = s;
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            ans = max(ans, solve_one(i + 'a'));
            for (int j = i + 1; j < 3; ++j) {
                ans = max(ans, solve_two(i + 'a', j + 'a'));
            }
        }

        ans = max(ans, solve_three());
        return ans;
    }
};