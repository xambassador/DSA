#include<iostream>
#include<stack>
#include<queue>
using std::stack;
using std::queue;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

// Solution 1
void reverseQ(queue<int> &q) {
    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

// solution 2
void reverseQueue(queue<int> &q) {
    if (q.empty()) return;
    int myElement{q.front()};
    q.pop();
    reverseQueue(q);
    q.push(myElement);
}

int main() {
    queue<int> q({1,2,3,4});
    cout << "front : " << q.front() << endl;
    // reverseQ(q);
    reverseQueue(q);
    cout << "front : " << q.front() << endl;
}
