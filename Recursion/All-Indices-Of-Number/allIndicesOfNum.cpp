#include<bits/stdc++.h>
using namespace std;

int allIndicesHelp(int* arr, int start, int end , int x, int* output,int nextIndex){
    //1.Base case, if array is empty, there is no 'x'
    if(start>end){
        return 0;
    }
    //2. Our calculation
    //If first element is equl to 'x' then add it's index in output array
    if(arr[start] == x){
        output[nextIndex] = start;
        // Now we give rest array to recursion and say it to hey fill out output array and return me
        // how many indexes you fillout
        // And then we just add 1 in recursion's answer because we fond our element is equal to 'x'
        return 1+allIndicesHelp(arr,start+1,end,x,output,nextIndex+1);
    }
    //If our element is not equal to 'x' then, 'x' is present in rest of array or may be not
    //so now we simply give this problem to recursion and return it's answer
    return allIndicesHelp(arr,start+1,end,x,output,nextIndex);
}

int allIndices(int* arr, int n, int x, int* output){
    return allIndicesHelp(arr,0,n-1,x,output,0);
}

int main(){  
    int n;
    cin >> n;
    int* arr{new int[n]};
    for(int i{};i<n;i++){
        cin >> arr[i];
    }
    int x;
    cin >> x;
    int* output{new int[n]};
    int ans{allIndices(arr,n,x,output)};
    for(int i{};i<ans;i++){
        cout << output[i] << " ";
    }cout << endl;
    delete arr;
    delete output;
}

// int allIndices(int* arr, int n, int x, int* output){
//     //1. Base case if array is empty
//     if(n==0){
//         return 0;
//     }    
//     //2.We take decision on last element,so first we calll recursion and say fill out output array
//     //and return me how many element you fill out
//     int ans{allIndices(arr,n-1,x,output)};
//     //3. Our work is just check that last element is 'x' or not.
//     //if yes then add in output array
//     //remember recursion give us how many element it added,
//     //if it add 3 elementsm, that means indexes are 0 to 2, so our element is go on index 3 which is
//     //equal to ans.
//     if(arr[n-1] == x){
//         output[ans] = n-1;
//         return 1+ans;
//     }
//     return ans;
// }