#include<iostream>
#include "stackUsingArray.h"
// -----------------------------------------------------------------------------

int main() {
    // Creating stack
    Stack<int> s1;
    Stack<char> s2(20); // Create 20 size stack
    Stack<int> s3({1,2,3,4,5});
    Stack<int> s4(s3); // Copy constructor

    /* Member functions
     *----------------------------------
     * Constructor
     * Copy constructor
     * operator=
    */

    /* getSize() : Return how many elements are inserted in stack. O(1)
     * max_size() : Return size that indicate how many elements can stack store base on it's implement. O(1)
     * empty() : Check stack is empty or not. O(1)
     * */

    /* Element access
     * top() : Return top element present on stack. O(1) */

    /* Modification
     * ---------------------------------
     *  push() : Insert data. O(1)
     *  pop() : Delete data. O(1)
     *  clean() : Clear whole stack. O(n)
    */
}
