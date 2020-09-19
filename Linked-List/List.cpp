#include<iostream>
using namespace std;
#include "DoublyLinkedList.h"

int main(){
    // Create list
    /* Member functions
     * Constructor
     * Copy constructor
     * Parameterized constructor
     * operator=
     * assign
     * */
    List list1; // Default constructor
    List list2({1,2,3,4,5}); // Parameterized constructor, O(n)
    
    int arr[10]{1,2,3,4,5}; // Parameterized constructor, O(n)
    List list3(sizeof(arr)/sizeof(arr[0]), arr);
    
    List list4, list5;
    list4.assign({1,2,3,4,5});
    list5.assign(5,10);

    // Element Access
    /* front
     * back
    */
    List list6({10,20,30,40,50});
    //cout << list6.front() << endl; // O(1)
    //cout << list6.back() << endl; // O(1)

    // Modifiers
    /* push_back
     * push_front
     * pop_back
     * pop_front
     * insert
     * remove
     * removeElement
     * clean
    */

    list6.push_back(100); // O(1)
    list6.push_front(100); // O(1)
    list6.pop_back(); // O(1)
    list6.pop_front(); // O(1)

    list6.insert(100); // O(1)
    list6.insert(2,500); // Traversing O(n) + Insertion O(1) = O(n), Wrost case
    list6.remove(2); // Traversing O(n) + Insertion O(1) = O(n), Wrost case
    list6.removeElement(100); // Searching(Linear) O(n) + deletion O(1) = O(n), Wrost case
    list6.reverse(); // O(n)
    list6.clean(); // O(n)
    cout << "After cleaning size is" << list6.size() << endl;

    list6.TakeInput(); // O(n)
    list6.print();
    cout << "Front and back : " << list6.front() << " " << list6.back() << endl;
    cout << "Total nodes : " << list6.size() << endl;
}
