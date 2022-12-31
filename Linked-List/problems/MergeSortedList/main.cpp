#include <iostream>
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// -----------------------------------------------------------------------------
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;
    ListNode* tmp1 {list1}, *tmp2 {list2};
    ListNode* newHead {NULL}, *resultHead {NULL};

    while (tmp1 && tmp2) {
        if (tmp1 -> val <= tmp2 -> val) {
            if (!newHead) {
                newHead = new ListNode();
                resultHead = newHead;
            } else {
                newHead -> next = new ListNode();
                newHead = newHead -> next;
            }
            newHead -> val = tmp1 -> val;
            tmp1 = tmp1 -> next;
        } else {
            if (!newHead) {
                newHead = new ListNode();
                resultHead = newHead;
            } else {
                newHead -> next = new ListNode();
                newHead = newHead -> next;
            }
            newHead -> val = tmp2 -> val;
            tmp2 = tmp2 -> next;
        }
    }

    while (tmp1) {
        newHead -> next = new ListNode();
        newHead = newHead -> next;
        newHead -> val = tmp1 -> val;
        tmp1 = tmp1 -> next;
    }

    while (tmp2) {
        newHead -> next = new ListNode();
        newHead = newHead -> next;
        newHead -> val = tmp2 -> val;
        tmp2 = tmp2 -> next;
    }

    return resultHead;
}

// -----------------------------------------------------------------------------
int main() {
    int n1, n2;
    cin >> n1;
    ListNode* list1 {new ListNode()};
    ListNode* head1 {list1};
    for (int i{}; i < n1; i++) {
        int val;
        cin >> val;
        head1 -> val = val;
        if (i != n1 - 1) {
            head1 -> next = new ListNode();
            head1 = head1 -> next;
        }
    }

    cin >> n2;
    ListNode* list2 {new ListNode()};
    ListNode* head2 {list2};
    for (int i{}; i < n2; i++) {
        int val;
        cin >> val;
        head2 -> val = val;
        if (i != n2 - 1) {
            head2 -> next = new ListNode();
            head2 = head2 -> next;
        }
    }

    ListNode* head {mergeTwoLists(list1, list2)};
    ListNode* tmpHead {head};
    while (tmpHead) {
        cout << tmpHead -> val << " ";
        tmpHead = tmpHead -> next;
    }
    cout << endl;

    // Free memory
    while (list1) {
        ListNode* temp {list1};
        list1 = list1 -> next;
        delete temp;
    }

    while (list2) {
        ListNode* temp {list2};
        list2 = list2 -> next;
        delete temp;
    }

    while (head) {
        ListNode* temp {head};
        head = head -> next;
        delete temp;
    }

    return 0;
}
