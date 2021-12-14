#include<iostream>
#define MOD 1000000007
using std::cin;
using std::cout;
using std::endl;

void multiply(long long A[2][2], long long B[2][2]) {
    long long fValue {(((A[0][0]) % MOD * (B[0][0]) % MOD) % MOD + ((A[0][1]) % MOD * (B[1][0]) % MOD) % MOD) % MOD};
    long long sValue {(((A[0][0]) % MOD * (B[0][1]) % MOD) % MOD + ((A[0][1]) % MOD * (B[1][1]) % MOD) % MOD) % MOD};
    long long tValue {(((A[0][0]) % MOD * (B[1][1]) % MOD) % MOD + ((A[1][1]) % MOD * (B[1][0] % MOD)) % MOD) % MOD};
    long long lValue {(((A[1][0]) % MOD * (B[0][1]) % MOD) % MOD + ((A[1][1]) % MOD * (B[1][1]) % MOD) % MOD) % MOD};
    A[0][0] = fValue % MOD;
    A[0][1] = sValue % MOD;
    A[1][0] = tValue % MOD;
    A[1][1] = lValue % MOD;
}

void power(long long matrice[2][2], long long n) {
    if (n == 0 || n == 1) return;
    power(matrice, n/2);
    multiply(matrice, matrice);
    if ((n % 2) != 0) {
        long long temp[2][2] {{1,1}, {1,0}};
        multiply(matrice, temp);
    }
}

long long fibonacci(long long n) {
    long long matrice[2][2] {{1,1},{1,0}};
    if (n == 0) return 0;
    power(matrice, n - 1);
    return matrice[0][0] % MOD;
}

unsigned long long fiboSum(unsigned long long m, unsigned long long n) {
    return (fibonacci(n+2) % MOD - fibonacci(m+1) % MOD + MOD) % MOD;
}

int main() {
    long long n, m;
    cin >> n >> m;
    cout << fiboSum(m,n) << endl;
}
