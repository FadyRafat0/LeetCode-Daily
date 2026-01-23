class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (auto &i : students) q.push(i);

        int ans = 0;
        for (auto &i : sandwiches) {
            queue<int> nxt;
            while (q.size() && q.front() != i) nxt.push(q.front()), q.pop();
            if (q.empty()) break;

            q.pop();

            ++ans;
            while (nxt.size()) q.push(nxt.front()), nxt.pop();
        }
        return students.size() - ans;
    }
};