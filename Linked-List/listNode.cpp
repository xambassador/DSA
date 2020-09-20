#include<bits/stdc++.h>
using namespace std;
#include "LinkedListClass.h"
using namespace classNode;


int main(){
    // Create list
    // Member functions
    /*
     * Constructor
     * Operator=
     * assign
    */ 

    // Using Deafult constructor
    LinkedList<int> list1;

    // Using parameterized constructor
    LinkedList<int> list2({1,2,3,4,5}); // Take initializer_list, O(n)
    int arr[5]{1,2,3,4,5};
    LinkedList<int> list3(sizeof(arr)/sizeof(arr[0]), arr); // Take array as input, O(size)

    // Using copy constructor
    LinkedList<int> list4(list2); // O(list2.size)

    // Using copy assignment operator
    LinkedList<int> list5 = list3; // copy constructor is called. O(l.size)
    LinkedList<int> l1({100,200,300,400,500,600,700});
    l1 = list2;

    // Using assign function
    LinkedList<int> list6, list7;
    list6.assign({1,2,3,4}); // O(size)
    list7.assign(5,10); // O(size)

    // Taking input from users
    LinkedList<int> list8; // O(n)
    // list8.takeInput();

    // Print list
    // list8.print(); // O(n)

    // Element Access
    /* front() => return first node data
     * back() => return last node data
    */
    //list8.front(); // O(1)
    //list8.back(); // O(1)

    // Capacity
    /* empty() => check if list is empty or not
     * size() => return how many elements are there in list
    */

    //cout << list8.empty() << endl; // O(1)
    //cout << list8.size() << endl; // O(1)

    // Modifiers
    /* push(data) => insert node to last
     * pop() => delete last node
     * insert(data) => insert node at last position
     * insert(position, data) => insert node at specified position
     * insertList(position, initializer_list) => insert more then one node after specified position
     * remove(position) => delete node at give position
     * removeElement(data) => delete specific data node
    */
    LinkedList<int> list9({10,20,30,40});

    list9.push(100); // O(1), 10->20->30->40->100
    list9.pop();     // O(1), 10->20->30->40
    list9.insert(100); // O(1), 10->20->30->40->100
    list9.insert(2,200); // To reach 2nd node O(n) + insert node O(1) = O(n) for wrost case, 10->20->200->30->40
    list9.insertList(1,{-1,-2,-3,-4}); // Wrost case : Traverse for reach given position O(n) + insert list O(list-size) = O(n)+O(size) => O(n+size)
    list9.remove(1); // O(n) for traversing + O(1) for removing = O(n)
    list9.removeElement(10); // O(n) for searching data + O(1) for deleting

    list9.clean();
    list9.print();
    cout << "Front and Back : " << list9.front() << " " << list9.back() << endl;
    cout << "Size : " << list9.size() << endl;

    // Operations
    /* find(data) => search given data node in list and return true or false
     * appendNnodesToFirst(n) => It append last n nodes to first
     * removeDuplicates() => Remove all consecutive duplicates
     * preverse() => It just print reverse List
     * reverse_i() => Reverse list iteratively
     * reverse_rec1(), reverse_rec2(), reverse_rec3() => All are reverse list, implement using recursion
     * palindrome() => Check whether linked list is palindrome or not
     * merge() => Merge two sorted list
     * evenAfterOdd() => Move all odd data node to first
     * sort() => Sort list, Merge sort
     * BubbleSort() => Sort list, BubbleSort
     * swap(position1, position2) => swap given positional nodes
     * kreverse() => reverse k nodes
     * skipMremoveN() => skip M nodes and then delete n nodes
     * deleteEveryNnodes() => delete every n nodes
    */
}