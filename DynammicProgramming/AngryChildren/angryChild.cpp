#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
   
    long arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
   
    sort(arr,arr+n);
    
    long old_cost=0,min_cost,sum=0;
    
    for(int i=0;i<k;i++){
        sum+=arr[i];
        old_cost=old_cost+(i*arr[i])-(k-1-i)*arr[i];
    }
    min_cost=old_cost;
    
    for(int i=k;i<n;i++){
        sum=sum-arr[i-k];
      old_cost=old_cost+(k-1)*(arr[i-k])-(sum)+(k-1)*(arr[i])-sum;  
        sum+=arr[i];
        
        if(old_cost<min_cost)
            min_cost=old_cost;
    }
    cout<<min_cost;
    return 0;
}

