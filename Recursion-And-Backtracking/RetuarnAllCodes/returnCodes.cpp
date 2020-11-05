#include<bits/stdc++.h>
using namespace std;

char arr[27]{' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int charToint(char a){
    int ans = a - '0';
    return ans;
}

int allCodes(string s, string* output){
    // 1. Base case
    if(s.empty()){
        output[0] = "";
        return 1;
    }
    if(s.length()==1){
        int i{charToint(s[0])};
        char c{arr[i]};
        output[0] = c;
        return 1;
    }
    // 2. Convert character into integer
    int i1{charToint(s[0])}, i2{charToint(s[1])};
    i2 = i1*10+i2;
    string toutput1[100],toutput2[100];
    int ans1{allCodes(s.substr(1),toutput1)};
    int si{};
    for(int i{};i<ans1;i++){
        output[si++] = arr[i1]+toutput1[i];
    }
    if(i2>=1 && i2<=26){
        int ans2{allCodes(s.substr(2),toutput2)};
        for(int i{};i<ans2;i++){
            output[si++] = arr[i2]+toutput2[i];
        }
        return ans1+ans2;
    }
    return ans1;
}


int main(){
    string s;
    cin >> s;
    string output[100];
    int ans{allCodes(s,output)};
    for(int i{};i<ans;i++){
        cout << output[i] << endl;
    }
}