#include <iostream>
#include <stack>
#include <string>
using std::string;
using std::stack;
using std::cout;
using std::endl;

class BrowserHistory {
    stack<string> history;
    stack<string> future;

public:
    BrowserHistory(string homepage) {
        history.push(homepage);
        future = stack<string>();
    }

    void visit(string url) {
        history.push(url);
        future = stack<string>();
    }

    string back(int steps) {
        while(steps > 0 && history.size() > 1) {
            future.push(history.top());
            history.pop();
            steps--;
        }
        return history.top();
    }

    string forward(int steps) {
        while(steps > 0 && future.size() > 0) {
            history.push(future.top());
            future.pop();
            steps--;
        }
        return history.top();
    }
};


int main() {
    BrowserHistory browserHistory("leetcode.com");
    browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
    browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
    browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
    cout << browserHistory.back(1) << endl;
    cout << browserHistory.back(1) << endl;
    cout << browserHistory.forward(1) << endl;
    browserHistory.visit("linkedin.com");
    cout << browserHistory.forward(2) << endl;
    cout << browserHistory.back(2) << endl;
    cout << browserHistory.back(7) << endl;
}
