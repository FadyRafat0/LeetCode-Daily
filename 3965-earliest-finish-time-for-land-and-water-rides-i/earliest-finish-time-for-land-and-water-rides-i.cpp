class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = 1e9;
        for (int i = 0; i < landStartTime.size(); ++i) {
            for (int j = 0; j < waterStartTime.size(); ++j) {
                int L1 = landStartTime[i], d1 = landDuration[i];
                int L2 = waterStartTime[j], d2 = waterDuration[j];

                if (L2 < L1) swap(L1, L2), swap(d1, d2);

                L1 += d1;
                if (L1 >= L2) L1 += d2;
                else L1 = L2 + d2;

                ans = min(ans, L1);
            }
        }
        return ans;
    }
};