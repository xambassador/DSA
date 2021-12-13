#include<iostream>
using std::cout;
using std::endl;
#include"bst.h"

int main() {
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(30);
    b.insert(15);
    b.insert(200);
    b.print();
    cout << endl;
    b.remove(20);
    b.print();
}
