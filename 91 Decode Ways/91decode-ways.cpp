class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> arr(n + 1);
        arr[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != '0')
            {
                arr[i] = arr[i +1];
                if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
                    arr[i] += arr[i + 2];
            }
        }
        return arr[0];
    }
};