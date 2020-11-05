#include<bits/stdc++.h>
using namespace std;
 
int mul(int x, int y){
    //1.Base case, if y is zero or x is zero then answer is zero
    if(x == 0 || y == 0){
        return 0;
    }
    //2.Call recursion, and say find out sum of x for y-1 time
    //3. Add x to recursion answer and return it
    return x+mul(x,y-1);
}

int main(){
    int x, y;
    cin >> x >> y;
    cout << mul(x,y) << endl;
}