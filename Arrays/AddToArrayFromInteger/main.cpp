#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::reverse;
using std::cin;
using std::cout;
using std::endl;


 vector<int> addToArrayForm(vector<int>& num, int k) {
    vector<int> ans;
    int carry {0};
    int i {num.size() - 1};
    while (i >= 0 || k > 0) {
        int sum {0};
        if (i >= 0) {
            sum += num[i];
        }
        if (k > 0) {
            sum += k % 10;
        }
        sum += carry;
        ans.push_back(sum % 10);
        carry = sum / 10;
        i--;
        k /= 10;
    }
    if (carry > 0) {
        ans.push_back(carry);
    }
    reverse(ans.begin(), ans.end());
    return ans;
 }

int main() {
    vector<int> num {1, 2, 0, 0};
    int k {34};
    vector<int> ans {addToArrayForm(num, k)};
    for (auto i : ans) {
        cout << i << " ";
    }
}
