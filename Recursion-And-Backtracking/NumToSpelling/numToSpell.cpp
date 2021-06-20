#include <iostream>
using namespace std;


string spells[10]{"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

void NumberToSpell (int n) {
    // Base case
    if (n == 0) return;

    // Call recursion - Hey go and print all numbers spelling
    NumberToSpell(n / 10);

    // my job
    int lastDigit {n % 10};
    cout << spells[lastDigit] << " ";
    return;
}

int main () {
    int n;
    cin >> n;
    NumberToSpell(n);
}