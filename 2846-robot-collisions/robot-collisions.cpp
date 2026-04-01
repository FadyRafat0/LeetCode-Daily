class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) {
        int n = pos.size();
        
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return pos[i] < pos[j];
        });

        vector<int> L;
        for (int i = n - 1; i >= 0; --i) {
            int id = idx[i];
            if (dir[id] == 'L') L.push_back(id);
            else {
                while (L.size() && h[id]) {   
                    int cur = L.back();
                    if (h[id] == h[cur]) h[id] = h[cur] = 0;
                    else if (h[id] > h[cur]) h[cur] = 0, --h[id];
                    else h[id] = 0, --h[cur];

                    if (h[cur] == 0) L.pop_back();
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (h[i]) ans.push_back(h[i]);
        }

        return ans;
    }
};