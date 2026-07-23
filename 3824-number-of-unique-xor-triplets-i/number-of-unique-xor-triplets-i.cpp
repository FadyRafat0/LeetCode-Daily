class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int pw = 0;
        while ((1 << pw) <= n) ++pw;
        return (1 << pw);
    }
};