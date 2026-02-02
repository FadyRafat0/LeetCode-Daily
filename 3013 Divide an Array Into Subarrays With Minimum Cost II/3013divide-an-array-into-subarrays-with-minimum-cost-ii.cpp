class Solution {
public:
    long long minimumCost(vector<int> nums, int k, int dist) {
        int n = nums.size();
        
        k -= 2;

        multiset<int> ms, used, not_used;
        for (int i = 2; i <= dist + 1; i++)
            ms.insert(nums[i]);

        long long sum = 0, cnt = 0;
        for (auto &i : ms) {
            ++cnt;
            if (cnt <= k) {
                sum += i;
                used.insert(i);
            }
            else {
                not_used.insert(i);
            }
        }

        long long ans = 1e18;
        // [1, 2, 3]
        for (int i = 1; i + k < n; i++) {
            ans = min(ans, sum + nums[0] + nums[i]);

            if (not_used.find(nums[i + 1]) != not_used.end())
                not_used.extract(nums[i + 1]);
            else {
                sum -= nums[i + 1];
                used.extract(nums[i + 1]);
                if (not_used.size()) {
                    auto it = not_used.begin();
                    sum += *it;
                    used.insert(*it);
                    not_used.erase(it);
                }
            }

            int nx = i + dist + 1;
            if (nx >= n) continue;
            
            if (used.size() < k) {
                used.insert(nums[nx]);
                sum += nums[nx];
                continue;
            }
            
            if (*used.rbegin() > nums[nx]) {
                sum -= (*used.rbegin() - nums[nx]);
                not_used.insert(*used.rbegin());
                used.erase(--used.end());
                used.insert(nums[nx]);
            }
            else {
                not_used.insert(nums[nx]);
            }
        }
        // all possible starts
        // i + 1 , i + dist
        // summation of min k - 2 people
        return ans;
    }
};