#include <iostream>

using namespace std;

int dp[501][501];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> dp[i][j];
        }
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            int rightup, leftup; //출발지점이 오른쪽대각선 위, 왼쪽대각선 위.
            rightup = dp[i - 1][j];
            if(j == 1) { //왼쪽 끝인경우 왼쪽 대각선 위에서 오는건 없다.
                leftup = 0;
            }
            else {
                leftup = dp[i - 1][j - 1];
            }
            if(j == i) { //오른쪽 끝인경우 오른쪽 대각선 위에서 오는건 없다.
                rightup = 0;
            }
            else {
                rightup = dp[i - 1][j];
            }
            dp[i][j] = dp[i][j] + max(leftup, rightup);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[n][i]);
    }

    cout << ans << '\n';
    return 0;
}
