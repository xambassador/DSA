#include<bits/stdc++.h>
using namespace std;
 
string const arr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int n, string* output){
    // 1. Base case, if n is zero
    if(n == 0){
        output[0] = "";
        return 1;
    }
    int ans{keypad(n/10,output)};
    string s{arr[n%10]};
    for(int i{};i<ans*(s.size()-1);i++){
        output[i+ans] = output[i];
    }
    int k{};
    for(int i{};i<ans*s.size();){
        for(int j{};j<ans;j++){
            output[i++] = output[i]+s[k];
        }
        k++;
    }
    return ans*s.length();
}

int main(){
    int n;
    cin >> n;
    string output[100];
    int ans{keypad(n,output)};
    for(int i{};i<ans;i++){
        cout << output[i] << endl;
    }
}