class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> srt;
        for (int i = 0; i < nums.size(); ++i) srt.emplace_back(nums[i], i);
        sort(srt.begin(), srt.end());

        int n = nums.size();
        int l = 0, r = 0;
        while (r <= n) {
            if (r && (r == n || srt[r].first - srt[r - 1].first > limit)) {

                vector<int> sorted_indices;
                for (int i = l; i < r; ++i) sorted_indices.emplace_back(srt[i].second);

                sort(sorted_indices.begin(), sorted_indices.end());

                for (auto &idx : sorted_indices) {
                    nums[idx] = srt[l].first;
                    ++l;
                }
            }

            if (r == n) break;
            ++r;
        }

        return nums;
    }
};