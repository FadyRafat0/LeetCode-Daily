class Solution {
public:
    vector<int> prv_smaller(vector<int> &h) {
        int n = h.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            while (st.size() && h[st.top()] >= h[i])
                st.pop();
            if (st.size())
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nxt_smaller(vector<int> &h) {
        int n = h.size();
        stack<int> st;
        vector<int> ans(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && h[st.top()] >= h[i])
                st.pop();
            if (st.size())
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        auto prv = prv_smaller(heights);
        auto nxt = nxt_smaller(heights);
    
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (nxt[i] - prv[i] - 1));
        }
        return ans;
    }
};