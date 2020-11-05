#include<bits/stdc++.h>
using namespace std;

// Example : 23
// 2 => abc
// 3 => def

// Solution :
/*
    We take decision on 3, string corresponding to 3 is def
    So we make 3 recursion call(because string length is 3) and pass our decision
    So when we call recursion on 2 we pass decision as first include 'd' character
    then 'e' and then 'f'

                                  "23"
                                /  |  \
                               /   |   \
                              /    |    \
                            2,'d' 2,'e' 2,'f'
*/




string const arr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void printKeypad(int n, string output){
    if(n == 0){
        cout << output << endl;
        return;
    }
    string s{arr[n%10]};
    for(int i{};i<s.length();i++){
        printKeypad(n/10,s[i]+output);
    }
}

int main(){
    int n;
    cin >> n;
    string output{""};
    printKeypad(n,output);
}