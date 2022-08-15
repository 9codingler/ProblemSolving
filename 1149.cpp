#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int cost[1001][1001];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> cost[i][1] >> cost[i][2] >> cost[i][3];
    }

    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];
    dp[1][3] = cost[1][3];

    for(int i = 2; i <= n; i++) {
        dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + cost[i][2];
        dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][3];
    }

    int ans = 0;
    ans = min({dp[n][1], dp[n][2], dp[n][3]});

    cout << ans << '\n';
    return 0;
}
