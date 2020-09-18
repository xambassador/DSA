#include<iostream>
using namespace std;
#include "stackUsingArray.h"

int main(){
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

    /* Modification
     * ---------------------------------
     *  push()
     *  pop()
     *  clean()
    */

}
