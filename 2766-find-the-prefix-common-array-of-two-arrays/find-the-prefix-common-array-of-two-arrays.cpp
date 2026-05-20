class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans, frq_a(A.size() + 1), frq_b(frq_a);
        int cur = 0;
        for (int i = 0; i < A.size(); ++i) {
            frq_a[A[i]]++;
            frq_b[B[i]]++;

            if (frq_b[A[i]] && frq_a[A[i]]) {
                frq_a[A[i]]--;
                frq_b[A[i]]--;
                ++cur;
            }

            if (frq_a[B[i]] && frq_b[B[i]]) {
                frq_a[B[i]]--;
                frq_b[B[i]]--;
                ++cur;
            }

            ans.emplace_back(cur);
        }
        return ans;
    }
};