#include <iostream>

using namespace std;
int n;
int cost[1001];
int dp[1001];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    dp[1] = cost[1];

    for(int i = 2; i <= n; i++) {
        for(int j = i - 1; j >= i / 2; j--) {
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        }
        dp[i] = max(dp[i], cost[i]);
    }

    cout << dp[n] << '\n';
    return 0;
}
