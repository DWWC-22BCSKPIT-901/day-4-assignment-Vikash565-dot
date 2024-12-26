#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int poisonousPlants(vector<int>& p) {
    int n = p.size();
    vector<int> days(n, 0);
    stack<int> s;
    int maxDays = 0;

    for (int i = 0; i < n; ++i) {
        int day = 0;
        while (!s.empty() && p[s.top()] >= p[i]) {
            day = max(day, days[s.top()]);
            s.pop();
        }
        if (!s.empty()) {
            days[i] = day + 1;
        }
        s.push(i);
        maxDays = max(maxDays, days[i]);
    }

    return maxDays;
}
