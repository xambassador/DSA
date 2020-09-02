#include<bits/stdc++.h>
using namespace std;


bool isPermutation(char* s1, char* s2){
    if(strlen(s1) != strlen(s2)){
        return false;
    }
    sort(s1,s1+strlen(s1));
    sort(s2,s2+strlen(s2));
    int i{},j{};
    while(i < strlen(s1)){
        if(s1[i] != s2[i]){
            return false;
        }
        i++;
    }
    return true;
}

int main(){
    char s1[100],s2[100];
    cin >> s1 >> s2;
    cout << boolalpha << isPermutation(s1,s2) << endl;
}