#include<bits/stdc++.h>
using namespace std;
#include "LinkedListClass.h"

int main(){
    // int arr[5]{1,2,3,4,5};
    // classNode::LinkedList<int> ll(5,arr);
    // ll.takeInput();
    // ll.print();
    // ll.push(100);
    // ll.print();

    // classNode::LinkedList<int> ll1({1,2,3,4,5});
    // ll1.print();
    // ll1.details();
    // classNode::LinkedList<int> ll2(ll1);
    // ll2.print();
    // ll2.details();

    // classNode::LinkedList<int> l1({10,20,30,40,50,60,70,80,90,100});
    // l1.print();
    // classNode::LinkedList<int> l2 = l1;
    // l2.print();

    // classNode::LinkedList<int> l3({100,200,300,400,500,600,700,800,900,1000});
    // classNode::LinkedList<int> l4({2,4,6,8});
    // l3.print();
    // l4.print();

    // l4 = l3;
    // l3.print();
    // l4.print();

    // classNode::LinkedList<int> l5({100,200,300});
    // classNode::LinkedList<int> l6({2,4,6,8,9,10});
    // l5.print();
    // l6.print();

    // l5 = l6;
    // l5.print();
    // l6.print();
    // classNode::LinkedList<int> ll;
    // ll.takeInput();
    // cout << "List is : ";
    // ll.print();
    // cout << "size of list : " << ll.size() << endl;
    // cout << "length of list : " << ll.length() << endl;
    // cout << "is Empty : " << ll.empty() << endl;
    // ll.push(500);
    // cout << "list is : ";
    // ll.print();
    // cout << "length of list : " << ll.length() << endl;

    // classNode::LinkedList<int> ll({1,2,3,4,5});
    // ll.print();

    // classNode::LinkedList<int> ll;
    // ll.takeInput();
    // ll.print();
    // cout << ll.size() << endl;
    // ll.pop();
    // ll.print();
    // cout << ll.size() << endl;
    // ll.pop();
    // ll.print();
    // cout << ll.size() << endl;
    // ll.pop();
    // ll.print();
    // cout << ll.size() << endl;
    // ll.pop();
    // ll.print();
    // cout << ll.size() << endl;
    // ll.print();
    // ll.remove(3);
    // ll.print();
    // cout << ll.size() << endl;
    // ll.push(10);
    // ll.print();
    // cout << ll.size() << endl;
    // ll.print();
    // cout << ll.size() << endl;
    // cout << "Remove 3 " << endl;
    // ll.removeElement(3);
    // ll.print();
    // cout << ll.size() << endl;
    // cout << "Remove 5 " << endl;
    // ll.removeElement(5);
    // ll.print();
    // ll.push(100);
    // ll.print();
    // cout << ll.size();
    // ll.print();
    // ll.insert(10);
    // ll.print();
    // ll.insert(1,100);
    // ll.print();
    // ll.insert(0,500);
    // ll.print();
    // ll.remove(0);
    // ll.print();
    // cout << "Front and back : " <<  ll.front() << " " << ll.back() << endl;
    // ll.removeElement(10);
    // ll.print();
    // cout << "Front and back : " <<  ll.front() << " " << ll.back() << endl;
    // ll.print();
    // cout << boolalpha << ll.find(5) << endl;

    // ll.print();
    // ll.insertList(2,{100,200,300,400});
    // ll.print();
    // cout << "Size : " << ll.size() << endl;
    // cout << "Back : " << ll.back() << endl;
    // ll.push(5858);
    // cout << "Size : " << ll.size() << endl;
    // cout << "Back : " << ll.back() << endl;
    // cout << ll.front();
    // ll.print();
    // ll.appendNnodeToFirst(3);
    // ll.print();

    // ll.print();
    // cout << "Size : " << ll.size() << endl;
    // ll.removeDuplicates();
    // ll.print();
    // cout << "Size : " << ll.size() << endl;
    // cout << "Back : " << ll.back() << endl;
    
    // ll.print();
    // cout << "Befor reverse : " << endl;
    // cout << "Front : " << ll.front() << endl;
    // cout << "Back : " << ll.back() << endl;
    // ll.preverse();
    // cout << "After reverse : " << endl;
    // cout << "Front : " << ll.front() << endl;
    // cout << "Back : " << ll.back() << endl;

    // cout << "Befor reverse : ";
    // ll.print();
    // cout << "Front : " << ll.front() << endl;
    // cout << "Back : " << ll.back() << endl;
    // cout << endl;
    // ll.details();
    // cout << endl;
    // ll.reverse_i();

    // cout << "After reverse : ";
    // ll.print();
    // cout << "Front : " << ll.front() << endl;
    // cout << "Back : " << ll.back() << endl;


    // cout << "Befor reverse : ";
    // ll.print();
    // cout << "Front : " << ll.front() << endl;
    // cout << "Back : " << ll.back() << endl;
    // cout << endl;
    // ll.details();
    // cout << endl;
    // ll.reverse_rec1();

    // cout << "After reverse : ";
    // ll.print();
    // cout << "Front : " << ll.front() << endl;
    // cout << "Back : " << ll.back() << endl;

    // ll.print();
    // // ll.revrerse_rec2();
    // ll.reverse_rec3();
    // ll.print();
    // ll.details();

    // ll.print();
    // cout << boolalpha << ll.palindrome() << endl;
    // ll.print();
    // cout << ll.back() << endl;

    classNode::LinkedList<int> l1({1,3,2,5,4,7,6,8,9,10});
    // classNode::LinkedList<int> l2({2,4,6,8});
    // l1.print();
    // l2.print();
    // l1.merge(l2);
    // l1.print();
    // l2.print();
    l1.print();
    // l1.sort();
    // l1.print();
    //l1.evenAfterOdd();
    //l1.print();
    //l1.swap(3,4);
    //l1.print();
    // l1.kreverse(4);
    l1.deleteEveryN(2,2);
    l1.print();
}
