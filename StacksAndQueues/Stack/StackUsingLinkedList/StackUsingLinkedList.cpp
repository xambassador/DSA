#include<iostream>
using namespace std;
#include"StackUsingLinkedList.h"

int main(){
    
    // Create stack
    /* Constructor
     * Copy Constructor
     * operator=
    */

    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout << "Size : " << s1.getSize() << endl;
    cout << "Top : " << s1.top() << endl;
    Stack<int> s2(s1);
    cout << "Size : " << s2.getSize() << endl;
    cout << "Top : " << s2.top() << endl;
    Stack<int> s3 = s2;

    cout << "Size : " << s3.getSize() << endl;
    cout << "Top : " << s3.top() << endl;
}
