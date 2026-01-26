class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mn = 1e9;
        for (int i = 0; i + 1 < n; i++) {
            mn = min(mn, arr[i + 1] - arr[i]);
        }
        vector<vector<int>> ans;
        for (int i = 0; i + 1 < n; i++) {
            if (arr[i + 1] - arr[i] == mn) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};