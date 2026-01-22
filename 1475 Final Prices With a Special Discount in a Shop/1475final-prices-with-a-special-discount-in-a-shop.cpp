class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        int n = p.size();
        stack<int> st;
        vector<int> ans(p);
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && p[st.top()] > p[i])
                st.pop();
            if (st.size()) {
                ans[i] -= p[st.top()];
            }
            while (st.size() && p[st.top()] == p[i]) st.pop();
            st.push(i);
        }
        return ans;
    }
};