#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

/*
Updated Question: Return all pairs.
*/
// ------------- O(n^2) -------------
vector<vector<int>> getPairSum(vector<int> arr, int s) {
    cout << arr[0] << endl;
    const int length {arr.size()};
    sort(arr.begin(), arr.end());
    vector<vector<int>> result {};
    for (int i{}; i < length; i++) {
        const int currentElement {arr[i]};

        /*
            Find element whoes some is equal to `s` in rest of the array.
            If found, push it into the result array.
        */
       for (int j{i + 1}; j < length; j++) {
        // skip current element as it is add for marking purpose.
        if (currentElement == INT_MIN) continue;

        if (currentElement + arr[j] == s) {
            // Push pair into result array
            vector<int> temp {};
            if (currentElement < arr[j]) {
                temp.push_back(currentElement);
                temp.push_back(arr[j]);
            } else {
                temp.push_back(arr[j]);
                temp.push_back(currentElement);
            }
            result.push_back(temp);
        }
       }

       // Mark current element as processed or visited, so it want consider again in next iteration.
       arr[i] = INT_MIN;
    }

    return result;
}


int pairSum(vector<int> &arr, int sum) {
    int ans {};
    const int length {arr.size()};
    for (int i{}; i < length; i++) {
        for (int j{i + 1}; j < length; j++) if (arr[i] + arr[j] == sum) ans++;
    }
    return ans;
}

int main () {
    int size, sum;
    cin >> size >> sum;
    vector<int> arr;
    for (int i{}; i < size; i++) {
        int t;
        cin >> t;
        arr.push_back(t);
    }

    // case 1: Get total number of pairs
    int ans {pairSum(arr, sum)};
    cout << ans << endl;

    // case 2: Get all pairs
    vector<vector<int>> allPairs {getPairSum(arr, sum)};

    for (int i{}; i < allPairs.size(); i++) {
        cout << allPairs[i][0] << " " << allPairs[i][1] << endl;
    }
}
