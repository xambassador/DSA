#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using std::cin;
using std::cout;
using std::end;
using std::vector;
using std::unordered_set;


/*
    Approach - 1 : Using Sort

	Time complexity: O(N * log(N))
	Space complexity: O(1)

	Where N is the length of the array.
*/

int findDuplicate1(vector<int>& arr, int n) {
    // Sort the Array
    sort(arr.begin(), arr.end());

    // Traverse through the array and check for two consecutive equal elements
    for (int i{}; i < n; i++) {

        // Duplicate element found
        if (arr[i] == arr[i+1]) return arr[i];
    }

    return -1;
}


/*
    Approach - 2 : Using Binary Search

	Time complexity: O(N * log(N))
	Space complexity: O(1)

	Where N is the length of the array.

*/

int findDuplicate2(vector<int>& arr, int n) {
    int start{1}, end{n};

    // Find mid
    while (start < end) {
        // Initialize mid element index.
        int midElementIndex {start + (end - start) / 2};

        // Set count variable to count number of elements less than midElementIndex
        int count {};

        // Count the number of elements that are smaller or equal to midElementIndex
        for (int i{}; i<n; i++) {
            if (arr[i] <= midElementIndex) {
                count++;
            }
        }

        // Duplicate element is on left side of mid so
        if (count > midElementIndex) {
            end = midElementIndex;
        }

        // Duplicate element is on right side of mid so
        else {
            start = midElementIndex + 1;
        }
    }

    return start;
}



/*
    Approach - 3 : Using set
	Time complexity: O(N)
	Space complexity: O(N)

	Where N is the length of the array.

*/

int findDuplicate3(vector<int>& arr, int n) {
    unordered_set<int> uset;

    for (int i : uset) {
        // check if current element is already inserted in set
        if (uset.find(i) != uset.end()) {
            // If we reach here that means the element is already present in set. That means current element is duplicate
            return i;
        } else {
            // Otherwise insert into set
            uset.insert(i);
        }
    }

    return -1;
}


/*
    Approach - 4 : Modifyind array in place
	Time complexity: O(N)
	Space complexity: O(1)

	Where N is the length of the array.

*/
int findduplicate4(vector<int>& arr, int n) {
    for (int i{}; i < n; i++) {
        // Use array index to store visited state of each element
        int index {abs(arr[i]) - 1};

        // Mark visited as multiplying by -1
        arr[index] *= -1;

        // In case of duplicate, arr[index] will become positive
        if (arr[index] > 0) return abs(arr[index]);
    }

    return -1;
}


int main () {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;
        for (int i{}; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
    }
}
