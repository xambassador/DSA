#include<iostream>
#include<algorithm>


int main(){
    int n;
    std::cin >> n;
    int* arr {new int[n]};
    for(int i{}; i<n; i++) std::cin >> arr[i];
    std::sort(arr,arr+n);
    int start {n-3};
    int mid {n-2};
    int end {n-1};
    while(start+mid <= end) {
        start--;
        mid--;
        end--;
        if(start < 0) {
            std::cout << "-1" << std::endl;
            return 0;
        }
    }
    std::cout << arr[start] << " " << arr[mid] << " " << arr[end] << std::endl;
}