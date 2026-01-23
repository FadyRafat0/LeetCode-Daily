class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<long long> v(n);
        for (int i = 0; i < n; i++) v[i] = nums[i];
        
        set<int> st;
        set<pair<long long, int>> sums;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(i);
            if (i + 1 < v.size()) {
                sums.insert({v[i] + v[i + 1], i});
                cnt += (v[i + 1] >= v[i]);
            }
        } 

        // [2,2,-1,3,-2,2,1,1,1,0,-1]
        int op = 0;
        while (sums.size() && cnt < st.size() - 1) {
            auto [s, idx] = *sums.begin();
            sums.erase(sums.begin());

            auto it = st.lower_bound(idx);
            auto nx = next(it);            
            assert(nx != st.end());

            cnt += (v[*nx] >= v[*it] ? -1 : 0);

            if (it != st.begin()) {
                auto prv = prev(it);
                sums.erase({v[*prv] + v[*it], *prv});
                sums.insert({v[*prv] + v[*it] + v[*nx], *prv});

                cnt += (v[*it] >= v[*prv] ? -1 : 0);
                cnt += (v[*it] + v[*nx] >= v[*prv] ? 1 : 0);
            }

            v[*it] += v[*nx];

            auto nx2 = next(nx);
            if (nx2 != st.end()) {
                sums.erase({v[*nx] + v[*nx2], *nx});
                sums.insert({v[*it] + v[*nx2], *it});
                cnt += (v[*nx2] >= v[*nx] ? -1 : 0);
                cnt += (v[*nx2] >= v[*it] ? 1 : 0);
            }

            st.erase(nx);
            ++op;
        }
        return op;
    }
};