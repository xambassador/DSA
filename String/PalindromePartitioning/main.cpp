#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------------------

void partitions(string s, int start, vector<string> &substr, vector<vector<string>> &result) {
    // base case
    // if start is equal to the size of the string, then we have reached the end of the string
    if (start == s.size()) {
        result.push_back(substr);
        return;
    }

    // recursive case
    // we will iterate through the string and check if the substring is a palindrome
    for (int i{start}; i < s.size(); i++) {
        // We first create a substring from the start index to the i - start + 1 index.
        // Here we do i - start + 1 because we want to include the current index as well.
        // We then check if the substring is a palindrome by comparing it to its reverse.
        string sub {s.substr(start, i - start + 1)};

        // Checking if the substring is a palindrome by comparing it to its reverse.
        if (sub == string(sub.rbegin(), sub.rend())) {
            // If the substring is a palindrome, then we push it to the substr vector.
            substr.push_back(sub);
            // We then call the recursion to check for remaining substrings.
            partitions(s, i + 1, substr, result);
            // We then pop the last element from the substr vector to check for other substrings.
            substr.pop_back();
        }
    }
}

// -----------------------------------------------------------------------------------------
vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> substr;
    partitions(s, 0, substr, result);
    return result;
}

// -----------------------------------------------------------------------------------------
int main () {
    string s;
    cin >> s;
    vector<vector<string>> result {partition(s)};
    for (auto i : result) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}
