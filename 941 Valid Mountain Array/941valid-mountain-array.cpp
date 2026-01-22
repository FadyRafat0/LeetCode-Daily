class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 1;
        while (i < arr.size() && arr[i] > arr[i - 1])
            ++i;
        if (i == 1 || i == arr.size()) return 0;
        while (i < arr.size() && arr[i] < arr[i - 1])
            ++i;
        return (i == arr.size());
    }
};