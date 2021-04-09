#include<iostream>
using namespace std;

void build_z_array(int* z_array, string str) {
    int l{}, r{};
    int n{str.length()};
    for (int i{1};i<n;i++) {
        if (i > r) {
            l = i;
            r = i;
            while(r < n && str[r-l] == str[r]) {
                r++;
            }

            z_array[i] = r-l;
            r--;
        } else {
            int k{i-l};
            if (z_array[k] <= r-i) z_array[i] = z_array[k];
            else {
                l = i;
                while(r < n && str[r-l] == str[r]) r++;
                z_array[i] = r-l;
                r--;
            }
        }
    }
}

void searchString(string text, string pattern) {
    string str {pattern + "$" + text};
    int n {str.length()};
    int* z_array {new int[n]()};

    for (int i{}; i<n; i++) {
        if (z_array[i] == pattern.length()) cout << i - pattern.length() - 1 << endl;
    }
}

int main() {
    string text;
    cin >> text;
    string pattern;
    cin >> pattern;

}