#include <vector>
#include <algorithm>
using std::vector;
using std::min;

// -----------------------------------------------------------------------------------------
 int mincostTickets(vector<int>& days, vector<int>& costs) {
    int cost {};
    queue<pair<int, int>> last7Days, last30Days;
    for (auto d : days) {
        while (!last7Days.empty() && last7Days.front().first + 7 <= d) last7Days.pop();
        while (!last30Days.empty() && last30Days.front().first + 30 <= d) last30Days.pop();

        last7Days.push({ d, cost + costs[1] });
        last30Days.push({ d, cost + costs[2] });

        cost = min({ cost + costs[0], last7Days.front().second, last30Days.front().second });
    }
    return cost;
}
