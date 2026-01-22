class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        
        stack<int> st;
        st.push(0);

        int lst = 0;

        for (auto &t : logs) {
            string cur;
            vector<string> spl;
            for (auto &c : t) {
                if (c == ':') spl.push_back(cur), cur.clear();
                else {
                    cur += c;
                }
            }
            spl.push_back(cur);

            int id = stoi(spl[0]);
            int timer = stoi(spl[2]);
            

            if (spl[1] == "end") {
                assert(id == st.top());
                ans[st.top()] += timer - lst + 1;
                st.pop();
                
                lst = timer + 1;
            }
            else {
                ans[st.top()] += timer - lst;
                st.push(id);

                lst = timer;
            }
        }
        return ans;
    }
};