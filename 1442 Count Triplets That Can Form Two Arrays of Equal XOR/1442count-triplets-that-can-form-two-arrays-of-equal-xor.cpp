class Solution {
public:
    int countTriplets(vector<int>& v) {
        int count = 0;
        for(int i = 0; i < v.size() - 1; i++) {
            int val = v[i];
            for(int k = i + 1; k < v.size(); k++) {
                val ^= v[k];
                if(val == 0) count += (k - i);
            }
        }
        return count;
    }
};