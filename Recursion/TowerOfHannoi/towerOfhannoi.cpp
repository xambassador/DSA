#include<bits/stdc++.h>
using namespace std;

void towerOfhannoi(int n, char source, char aux, char dest){
    // 1. Base case, if no disk are there
    if(n == 0){
        return;
    }
    // If there is only one disk
    if(n == 1){
        cout << source << "->" << dest << endl;
        return;
    }
    //2. Now there is n number of disks.
    // We take our decision on last disk
    // So we want our last disk should move on destination 
    // So from top disk to n-1 disk should move on auxilary, so this work is for recursion
    towerOfhannoi(n-1,source,dest,aux);
    // Now we move our disk to source to destination
    cout << source << "->" << dest << endl;
    // Now Disk which are on auxilary, it should move on destination,
    // Here we use source as auxilary rod
    towerOfhannoi(n-1,aux,source,dest);
} 

int main(){
    int n;
    cin >> n;
    towerOfhannoi(n,'A','B','C');
}