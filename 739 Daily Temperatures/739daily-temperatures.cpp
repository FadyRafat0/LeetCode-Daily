class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && temperatures[st.top()] <= temperatures[i])
                st.pop();
            if (st.size()) {
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};