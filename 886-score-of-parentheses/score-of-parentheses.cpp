class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> score(s.size());
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {            
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                if (s[i - 1] == '(') score[i] = 1;
                else {
                    score[i] = score[i - 1] * 2;
                }

                int lst = st.top();
                st.pop();
                --lst;
                if (lst >= 0)
                    score[i] += score[lst];
            }
        }

        return score[s.size() - 1];
    }
};