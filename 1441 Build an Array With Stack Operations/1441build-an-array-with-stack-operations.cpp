class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> st;
        int j = 0;
        for (int i = 1; i <= n && j < target.size(); i++) {
            st.push(i);
            ans.push_back("Push");
            if (target[j] == i) ++j;
            else {
                st.pop();
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};