class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        bool check = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '{')
                st.push('{');
            else if (s[i] == '(')
                st.push('(');
            else if (s[i] == '[')
                st.push('[');
            else if (s[i] == '}')
            {
                if (st.empty())
                {
                    check = false;
                    break;
                }
                if (st.top() == '{')
                    st.pop();
                else
                {
                    check = false;
                    break;
                }
            }
            else if (s[i] == ')')
            {
                if (st.empty())
                {
                    check = false;
                    break;
                }
                if (st.top() == '(')
                    st.pop();
                else
                {
                    check = false;
                    break;
                }
            }
            else if (s[i] == ']')
            {
                if (st.empty())
                {
                    check = false;
                    break;
                }
                if (st.top() == '[')
                    st.pop();
                else
                {
                    check = false;
                    break;
                }
            }
        }
        if (!st.empty())
            check = false;

        return check;
    }
};