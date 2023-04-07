#include <vector>
#include <algorithm>
using std::sort;
using std::vector;

// https://leetcode.com/problems/boats-to-save-people/
int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(),people.end());
    int i {};
    int j {(int)people.size() - 1};
    int ans {};
    while(i <= j) {
        if (!(people[i] + people[j] <= limit)) {
            j--;
            ans++;
            continue;
        }
        i++;
        j--;
        ans++;
    }

    return ans;
}
