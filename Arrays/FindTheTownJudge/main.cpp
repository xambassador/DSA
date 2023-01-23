#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------------------

int findJudge(int n, vector<vector<int>>& trust) {
    // trustCount array stores the number of people who trust the person at index i
    vector<int> trustCount(n + 1, 0);
    for (auto& t : trust) {
        // t[0] trusts t[1] so t[1] gets a +1 and t[0] gets a -1
        trustCount[t[0]]--;
        // t[1] is trusted by t[0] so t[1] gets a +1
        trustCount[t[1]]++;
    }
    for (int i{1}; i <= n; i++) {
        // if ith person trusts is trusted by n - 1 people then he is the judge
        if (trustCount[i] == n - 1) return i;
    }
    return -1;
}

// -----------------------------------------------------------------------------------------
int main () {
    vector<vector<int>> trust {
        {1,3},
        {2,3}
    };
    cout << findJudge(3, trust) << endl;
}
