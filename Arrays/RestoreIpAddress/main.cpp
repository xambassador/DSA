#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------------------

void restoreIPAddresses(string s, int start, int part, string ip, vector<string> &result) {
    if (start == s.size() && part == 4) {
        ip.erase(ip.end() - 1);
        result.push_back(ip);
        return;
    }
    if (s.size() - start > (4 - part) * 3) return;
    if (s.size() - start < (4 - part)) return;
    int num {};
    for (int i{start}; i < start + 3; i++) {
        num = num * 10 + (s[i] - '0');
        if (num <= 255) {
            ip += s[i];
            restoreIPAddresses(s, i + 1, part + 1, ip + '.', result);
        }
        if (num == 0) break;
    }
}

// -----------------------------------------------------------------------------------------
vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    string ip;
    restoreIPAddresses(s, 0, 0, ip, result);
    return result;
}

int main() {
    string s;
    cin >> s;
    vector<string> result {restoreIpAddresses(s)};
    for (auto &i : result) cout << i << endl;
    cout << endl;
    return 0;
}
