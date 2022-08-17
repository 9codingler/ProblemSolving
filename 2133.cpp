#include <iostream>

using namespace std;

long long dp[31];

int main() {
    dp[2] = 3;
    dp[4] = 11;
    int n;  
    cin >> n;

    for(int i = 6; i <= n; i += 2) {
        dp[i] += dp[i - 2] * dp[2];
        for(int j = 2; j <= i - 4; j += 2) {
            dp[i] += dp[j] * 2;
        }
        dp[i] += 2;
    }

    cout << dp[n] << '\n';
    return 0;
}
