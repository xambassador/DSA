#include<bits/stdc++.h>
using namespace std;
 
// Example : abc
// subsequances : 
/*
    ""
    c
    b
    bc
    a
    ac
    ab
    abc
*/

// Here we need to print subsequances using recursion
// So we need to pass extra output to recursion, in this output we pass our decision

//Solution of this problem : 
//On "abc" string 
//step 1 : Break the problem in two parts
    // 1. 'a'
    // 2. 'bc'
// On character 'a' we take decision
// On string 'bc' recursion handle it

//step 2 : We need to pass our decision to recursion
// We can see subsequances of "abc" in example, if we notice there are two types of subsequances,
// First some subsequances don't contain 'a' character (ex : "",b,c,bc)
// Second is some contain 'a' character (ex : a,ab,ac,abc)
// So we take decision on 'a', first we say to recursion go and print all subsequance that not contain
// Any 'a' character, then we call recursion again and say go and print all subsequance that contain
// 'a' character
 
void printSubseq(string s, string output){
    // 1. Base case, if string s is empty, print output
    if(s.empty()){
        cout << output << endl;
        return;
    }
    //2. Now we call recursion and pass our decision to recursion
    printSubseq(s.substr(1),output); // without s[0] character
    printSubseq(s.substr(1),output+s[0]);
    return;
}

int main(){
    string s;
    string output{""};
    cin >> s;
    printSubseq(s,output);
}