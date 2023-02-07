#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int totalFruit(vector<int>& fruits) {
    // If fruits size is 0 then return 0
    if (fruits.size() == 0) return 0;
    // If fruits size is 1 then result is 1
    if (fruits.size() == 1) return 1;
    // If fruits size is 1 then result is 2
    if (fruits.size() == 2) return 2;

    // Set Max to 2 and count to 2.
    // We already handle cases for size 1 and 2.
    // So, we consider first element and second element and put them into basket.
    // Max represent overall maximum fruits we can collect.
    int max {2}, count {2};
    // last set to index 1, and lastlast set to index 0.
    int last {1}, lastlast {0};

    // Start from index 2 element.
    for (int i{2}; i < fruits.size();) {
        // If last and lastlast elements are same. That means, both fruits have same type.
        // So, we can put them in single basket. So, put into single basket and count remain
        // 2. Now add current (ith index) fruite into second basket and increase count by 1.
        // And also, we need to increment our last and lastlast pointers.
        if (fruits[last] == fruits[lastlast]) {
            lastlast = last;
            last++;
            i++;
            count++;
            continue;
        }

        // If current fruite type is one of the type from last and lastlast.
        // Add it into basket and increment count.
        if (fruits[i] == fruits[last] || fruits[i] == fruits[lastlast]) {
            count++;
            i++;
        }

        // If fruite type is different.
        else {
            // We need to update max.
            if (count > max) max = count;
            // Now, increment pointers
            lastlast = last;
            last++;
            // Reste current to last+1
            i = last + 1;
            // Reset count to 2.
            count = 2;
        }
    }
    if (count > max) max = count;
    return max;
}

int main () {
    vector<int> fruits {1, 2, 3, 2, 2, 4, 5, 4, 4, 4};
    cout << totalFruit(fruits) << endl;
    return 0;
}
