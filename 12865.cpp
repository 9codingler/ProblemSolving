#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][100001];
int weight[101];
int value[101];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) { //i번물건의 무게, 가치 입력받음.
        cin >> weight[i] >> value[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(weight[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]); //i번물건을 선택 안하는경우 / 선택하는 경우.
            }          
            else {
                dp[i][j] = dp[i - 1][j];
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }

    cout << dp[n][k] << '\n';
    return 0;
}
