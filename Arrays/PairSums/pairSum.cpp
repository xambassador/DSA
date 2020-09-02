#include<iostream>
using namespace std;

void PairSum(int* arr, int n, int sum){
    int tmp,j;
    for (int i = 0; i < n; i++)
    {
        tmp = arr[i];
        j = i + 1;
        while (j < n){
            if (sum == tmp + arr[j]){
                if (tmp < arr[j]){
                    cout << tmp << " " << arr[j] << endl;
                }
                else{
                    cout << arr[j] << " " << tmp << endl;
                }
            }
            j++;
        }
    }    
}


int main(){
    int n;
    cin >> n;
    int *arr{new int[n]};
    for(int i{}; i<n; i++){
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    PairSum(arr,n,sum);
    
}