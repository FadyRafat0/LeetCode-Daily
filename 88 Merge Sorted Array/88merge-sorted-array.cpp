class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < m or j < n)
        {
            int a,b;
            a = b = 1e9 + 1;
            if (i < m) a = nums1[i];
            if (j < n) b = nums2[j];
            
            if (a < b) ++i;
            else ++j;
            res.push_back(min(a,b));
        }
        nums1 = res;
    }
};