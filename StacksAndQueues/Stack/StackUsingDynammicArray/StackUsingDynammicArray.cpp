#include<iostream>
using namespace std;
#include"StackUsingDynammicArray.h"


int main(){
    // Creating stack
    Stack<char> s1;
    s1.push('a');
    s1.push('b');
    s1.push('c');
    s1.push('d');
    s1.push('e');
    s1.push('f');
    s1.push('g');
    s1.push('h');
    s1.push('i');
    s1.push('j');

    cout << "Top elements : " << s1.top() << endl;
    cout << "Max size : " << s1.max_size() << " " << "Total elements : " << s1.getSize() << endl;

    s1.push('k');
    s1.push('l');
    s1.push('m');

    cout << "Top elements : " << s1.top() << endl;
    cout << "Max size : " << s1.max_size() << " " << "Total elements : " << s1.getSize() << endl;

    Stack<char> s2(s1);

    cout << "Top elements : " << s2.top() << endl;
    cout << "Max size : " << s2.max_size() << " " << "Total elements : " << s2.getSize() << endl;
    
    Stack<char> s3;
    s3 = s2;

    cout << "Top elements : " << s3.top() << endl;
    cout << "Max size : " << s3.max_size() << " " << "Total elements : " << s3.getSize() << endl;

}
