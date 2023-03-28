#include <vector>
#include <unordered_set>
#include <string>
using std::vector;
using std::unordered_set;
using std::string;

// -----------------------------------------------------------------------------------------
vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    unordered_set<string> words_set;
    for (string word : words) words_set.insert(word);
    vector<string> res;

    for (string word : words) {
        int n {(int)word.size()};
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i {}; i < n; i++) {
            if (!dp[i]) continue;
            for (int j {i + 1}; j <= n; j++) {
                if (j - i < n && words_set.count(word.substr(i, j - i))) dp[j] = 1;
            }
            if (dp[n]) {
                res.push_back(word);
                break;
            }
        }
    }
    return res;
}
