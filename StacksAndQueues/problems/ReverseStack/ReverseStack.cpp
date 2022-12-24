#include<iostream>
#include<stack>
using std::stack;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

void reverse(stack<int> &s1, stack<int> &s2) {
    if (s1.empty()) return;
    stack<int> tmp;
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }

    while (!s2.empty()) {
        tmp.push(s2.top());
        s2.pop();
    }

    while (!tmp.empty()) {
        s1.push(tmp.top());
        tmp.pop();
    }
}

// -----------------------------------------------------------------------------
int main() {
    stack<int> s1({1,2,3,4}),s2;
    cout << "top : " << s1.top() << endl;
    reverse(s1, s2);
    cout << "top : " << s1.top() << endl;
}
