#include<iostream>
#include<stack>
using std::stack;
using std::string;
using std::boolalpha;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

bool isBalanced(string s){
    int i{};
    stack<char> _s;
    while (i < s.length() && s[i] != '\0') {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            _s.push(s[i]);
        } else if (s[i] == '}') {
            if (_s.empty()) return false;
            else if (_s.top() == '{') _s.pop();
            else return false;
        } else if (s[i] == ']') {
            if (_s.empty()) return false;
            else if (_s.top() == '[') _s.pop();
            else return false;
        } else if(s[i] == ')') {
            if (_s.empty()) return false;
            else if (_s.top() == '(') _s.pop();
            else return false;
        }
        i++;
    }
    if (!_s.empty()) return false;
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << boolalpha << isBalanced(s) << endl;
}
