#include<bits/stdc++.h>
using namespace std;

char highestOccur(char* arr){
    sort(arr,arr+strlen(arr));
    char frequancyArr[128]{};
    int i{};
    int j = strlen(arr);
    while(i<j){
        frequancyArr[arr[i]]++;
        i++;
    }
    int max{INT_MIN};
    int maxIndex{};
    i = 0;
    while(i < 128){
        if(frequancyArr[i] > max){
            max = frequancyArr[i];
            maxIndex = i;
        }
        i++;
    }
    char ans = maxIndex;
    return ans;
}

int main(){
    char arr[100];
    cin >> arr;
    cout << highestOccur(arr) << endl;
}