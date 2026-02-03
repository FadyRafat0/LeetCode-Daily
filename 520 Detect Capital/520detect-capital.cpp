class Solution {
public:
    bool detectCapitalUse(string word) {
        bool all_capital{1}, all_small{1}, is_capital{0};
        for (int i = 0; i < word.size(); i++) {
            if (word[i] != toupper(word[i])) {
                all_capital = 0;
            }
            else {
                all_small = 0;
                if (i > 0)
                    is_capital = 1;
            }
        }

        bool first_capital = (word[0] == toupper(word[0]));
        cout << first_capital << ' ' << is_capital << "\n";
        return (all_capital || all_small || (!is_capital && first_capital));
    }
};