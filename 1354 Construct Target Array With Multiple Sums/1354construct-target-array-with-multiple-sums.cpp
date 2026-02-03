class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        for (int i = 0; i < target.size(); i++) {
            sum += target[i];
            pq.push(target[i]);
        }

        while (pq.size()) {
            auto mx = pq.top();
            pq.pop();
            long long rest = sum - mx;
            if (mx == 1 || rest == 1) return 1;

            if (rest == 0 || mx <= rest || mx % rest == 0) return 0;
            sum -= mx;
            pq.push(mx % rest);
            sum += mx % rest;
        }
        return true;
    }
};