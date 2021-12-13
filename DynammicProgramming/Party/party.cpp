#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::max;
struct Pair {
    int maxFun;
    int maxFees;
};

Pair maxEnjoyMent(int* fees, int* fun ,int start, int end, int budget) {
    if(budget <= 0) {
        Pair p;
        p.maxFees = 0;
        p.maxFun = 0;
        return p;
    }

    if(start > end) {
        Pair p;
        p.maxFun = 0;
        p.maxFees = 0;
        return p;
    }

    Pair ans;

    if(fees[start] <= budget) {
        // i decide to go in this party
        Pair option1{maxEnjoyMent(fees, fun, start + 1, end, budget - fees[start])};
        if(start == 0) cout << option1.maxFees << " " << option1.maxFun << endl;
        option1.maxFees += fees[start];
        option1.maxFun += fun[start];

        // i decline to go in this party
        Pair option2{maxEnjoyMent(fees, fun, start + 1, end, budget)};
        ans.maxFees = max(option1.maxFees, option2.maxFees);
        ans.maxFun = max(option1.maxFun, option2.maxFun);

        if (option1.maxFun == option2.maxFun) {
            if (option1.maxFun < option2.maxFees) ans.maxFees = option1.maxFees;
            else ans.maxFees = option2.maxFees;
        }
    } else {
        Pair option{maxEnjoyMent(fees, fun, start + 1, end, budget)};
        ans.maxFun = option.maxFun;
        ans.maxFees = option.maxFees;
    }

    return ans;
}

int main(){
    int budget, n;
    cin >> budget >> n;
    while(1) {
        if(budget == 0 && n == 0) break;
        int fees[n], fun[n];
        for(int i{}; i < n; i++) {
            int x, y;
            cin >> x >> y;
            fees[i] = x;
            fun[i] = y;
        }

        Pair ans{maxEnjoyMent(fees, fun, 0, n - 1, budget)};
        cout << ans.maxFees << " " << ans.maxFun << endl;
        cin >> budget >> n;
    }
}
