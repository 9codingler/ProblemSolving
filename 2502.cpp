#include <iostream>

using namespace std;

int dp[31][3];
int d, k;

int main() {
    cin >> d >> k;
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[2][1] = 0;
    dp[2][2] = 1;

    int n = 3;

    // d까지 필요한 dp[1], dp[2]의 갯수 계산.
    while(1) {
        dp[n][1] += dp[n - 1][1] + dp[n - 2][1];
        dp[n][2] += dp[n - 1][2] + dp[n - 2][2];
        if(n == d) {
            break;
        }
        n++;
    }

    int a, b;
    // 3a + 5b = 218 만족하는 a, b 찾는 brute force.
    for(a = 1; a <= k; a++) {
        if((k - (dp[d][1] * a)) % dp[d][2] == 0) {
            b = (k - dp[d][1] * a) / dp[d][2];
            break;
        }
    }

    cout << a << '\n';
    cout << b << '\n';
    return 0;
}
