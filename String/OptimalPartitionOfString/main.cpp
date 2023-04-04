#include <vector>
#include <string>
using std::string;
using std::vector;

// https://leetcode.com/problems/optimal-partition-of-string/

int partitionString(string s) {
    vector<int> lastSeen(26, -1);
    int count {1}, substringStart {};
    for (int i{}; i < s.length(); i++) {
        if (lastSeen[s[i] - 'a'] >= substringStart) {
            count++;
            substringStart = i;
        }
        lastSeen[s[i] - 'a'] = i;
    }
    return count;
}

// Using bit manipulation
int solution(string s) {
    int xr {};
    int ans {1};
    for(int i{}; i < s.size(); i++) {
        if(xr & (1 << (s[i] - 'a'))) {
            xr = 0;
            ans++;
        }
        xr ^= (1 << (s[i] - 'a'));
        // xr |= (1 << (s[i] - 'a'));
    }
    return ans;
}
