#include<bits/stdc++.h>
using namespace std;
 
bool check(char* arr, int start, int end){
    if(arr[start] == '\0'){
        return true;
    }
    if(arr[start] == 'a'){
        if(arr[start+1] == 'a'){
            return check(arr,start+1,end);
        }else if(arr[start+1] == 'b' && arr[start+2] == 'b'){
            return check(arr,start+3,end);
        }
        if(arr[start+1] == '\0'){
            return true;
        }else{
            return false;
        }
    }else if(arr[start] == 'b'){
        if(arr[start+1] == 'b' && arr[start+2] == 'a'){
            return check(arr,start+2,end);
        }else if(arr[start+1] == 'b' && arr[start+2] == '\0'){
            return true;
        }else{
            return false;
        }
    }
}

bool checkAB(char* s){
    if(s[0] == 'a'){    
        return check(s,1,strlen(s)-1);       
    }else{
        return false;
    }
}

int main(){
    char* arr{new char[1000]};
    cin >> arr;
    cout << boolalpha << checkAB(arr) << endl;
    delete arr;
}