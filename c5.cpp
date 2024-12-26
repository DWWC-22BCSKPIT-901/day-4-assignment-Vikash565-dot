#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int poisonousPlants(vector<int>& p) {
    int n = p.size();
    vector<int> days(n, 0); // Array to store the number of days each plant survives before dying
    stack<int> s;           // Stack to track indices of plants
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

int main() {
    vector<int> plants1 = {3, 6, 2, 7, 5};
    cout << "Example 1 Output: " << poisonousPlants(plants1) << endl;

    vector<int> plants2 = {6, 5, 8, 4, 7, 10, 9};
    cout << "Example 2 Output: " << poisonousPlants(plants2) << endl;

    return 0;
}
