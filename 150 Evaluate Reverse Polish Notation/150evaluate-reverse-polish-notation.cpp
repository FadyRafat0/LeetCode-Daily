class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto &t : tokens) {
            if (t == "*" || t == "/" || t == "+" || t == "-") {
                int A = st.top();
                st.pop();
                int B = st.top();
                st.pop();

                if (t == "*") st.push(B * A);
                else if (t == "+") st.push(B + A);
                else if (t == "-") st.push(B - A);
                else st.push(B / A);
            }
            else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};