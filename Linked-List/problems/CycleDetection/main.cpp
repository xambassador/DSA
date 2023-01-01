#include <iostream>
#include <unordered_map>
using std::unordered_map;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// -----------------------------------------------------------------------------
ListNode *detectCycle(ListNode *head) {
    unordered_map<ListNode*, bool> map;
    ListNode* tmp {head};
    while (tmp) {
        if (map.find(tmp) == map.end()) {
            map[tmp] = true;
        } else {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

// -----------------------------------------------------------------------------
int main () {
    ListNode* node1{new ListNode(0)};
    ListNode* head {node1};
    ListNode* node2 {new ListNode(1)};
    node1->next = node2;
    ListNode* node3 {new ListNode(2)};
    node2->next = node3;
    ListNode* node4 {new ListNode(3)};
    node3->next = node4;
    ListNode* node5 {new ListNode(4)};
    node4->next = node5;
    node5->next = NULL;

    ListNode* ans {detectCycle(head)};
    if (ans) {
        cout << ans->val << endl;
    } else {
        cout << "No cycle" << endl;
    }
}
