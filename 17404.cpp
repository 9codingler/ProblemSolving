#include <iostream>
#define MAX 1000001
//MAX를 끝까지 끌고가려면 MAX가 1000 ^ 1000보다 커야한다.
using namespace std;

int n;
int color[1001][4];
int dp[1001][4];
int ans = MAX;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> color[i][1] >> color[i][2] >> color[i][3];
    }

	for (int first = 1; first <= 3; first++) {// first : 1번 집의 색
		// 1번집에 지정된 색 이외의 색은 MAX로 지정하여 dp할때 선택되지 않도록 함
		for (int i = 1; i <= 3; i++) {
            if (i == first)  {
                dp[1][i] = color[1][i];
            }
			else { 
                dp[1][i] = MAX;
            }
        }
		// DP
		for (int i = 2; i <= n; i++) {
            dp[i][1] = color[i][1] + min(dp[i - 1][2], dp[i - 1][3]);
			dp[i][2] = color[i][2] + min(dp[i - 1][1], dp[i - 1][3]);
			dp[i][3] = color[i][3] + min(dp[i - 1][1], dp[i - 1][2]);
        }

		// 1번집 색과 N번집 색이 겹치지 않게 함
        // 이미 n번집까지 색칠 완료된 상태.
		for (int i = 1; i <= 3; i++) {
            if (i == first) {
                continue;
            }
			else {
                ans = min(ans, dp[n][i]);
            }
        }
	}
	cout << ans << '\n';
    return 0;
}
