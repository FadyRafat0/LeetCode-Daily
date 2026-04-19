class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int ans = 0;
        while (i < nums1.size()) {
            while (j < nums2.size() && (j < i || nums2[j] >= nums1[i])) ++j;

            ans = max(ans, j - i - 1);
            ++i;
        }
        return ans;
    }
};