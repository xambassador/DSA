#include<bits/stdc++.h>
using namespace std;
 
char arr[27]{' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int charToint(char a){
    int ans = a - '0';
    return ans;
}

void printAllCodes(string s, string output){
    if(s.empty()){
        cout << output << endl;
        return;
    }
    int i1{charToint(s[0])},i2{charToint(s[1])};
    i2 = i1*10+i2;
    printAllCodes(s.substr(1),output+arr[i1]);
    if(i2>=1 && i2<=26){
        printAllCodes(s.substr(2),output+arr[i2]);
    }
}

int main(){
    string s;
    cin >> s;
    string output{""};
    printAllCodes(s,output);
}