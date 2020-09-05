#include<bits/stdc++.h>
using namespace std;

int subSequance(string arr, string* output){
    //1. Base case, if string is empty, there is only one substring which is empty
    if(arr.empty()){
        output[0] = ' ';
        return 1;
    }
    //2. We take decision on first charatcer
    // So call recursion and give rest of string, recursion give us integer which represent how many subsequances it added in output array
    // So simply it give us size of output array it fill
    int ans{subSequance(arr.substr(1),output)};
    // Now in output array there is all subsequances which does not contain our first character
    // So we copy all subsequance and attach our character in front of them and add in to output array
    // and then return final size
    for(int i{};i<ans;i++){
        output[ans+i] = arr[0]+output[i];
    }
    return ans*2;
}

int main(){
    string input;
    cin >> input;
    string output[1000];
    int ans{subSequance(input,output)};
    for(int i{};i<ans;i++){
        cout << output[i] << endl;
    }
}