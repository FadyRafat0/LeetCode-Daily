class Solution {
public:
    vector<int> nxtGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] > arr[st.top()])
                res[st.top()] = i, st.pop();
            st.push(i);
        }
        return res;
    }   
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        auto sm = nxtGreater(nums2);
        for (int i = 0; i < nums2.size(); ++i) {
            mp[nums2[i]] = (sm[i] == -1 ? -1 : nums2[sm[i]]);
        }

        vector<int> ans;
        for (auto &i : nums1) ans.push_back(mp[i]);
        return ans;
    }
};