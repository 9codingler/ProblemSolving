#include <iostream>

using namespace std;

int dp[1000001];
int solve(int x) {
    if(x == 1) {
        return 0;
    }

    if(dp[x] != 0) {
        return dp[x];
    }

    dp[x] = solve(x - 1) + 1;

    if(x % 3 == 0) {
        dp[x] = min(solve(x / 3) + 1, dp[x]);
    }
    
    if(x % 2 == 0) {
        dp[x] = min(solve(x / 2) + 1, dp[x]);
    }

    return dp[x];
}
int main() {
    int n;
    cin >> n;
    // for(int i = 2; i <= n; i++) {
    //     dp[i] = dp[i - 1] + 1;
    //     if(i % 2 == 0) {
    //         dp[i] = min(dp[i / 2] + 1, dp[i]);
    //     }
    //     if(i % 3 == 0) {
    //         dp[i] = min(dp[i / 3] + 1, dp[i]);
    //     }
    // }
    cout << solve(n) << '\n';
    return 0;
}
