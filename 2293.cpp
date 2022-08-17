#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> money;
int dp[10001];

int main() {
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        money.push_back(tmp);
    }
    

    dp[0] = 1; // dp점화식을 위해서 dp[0] = 0이 아닌 1로 초기화.

    for(int i = 0; i < n; i++) { //money[0]부터 시작.
        for(int j = money[i]; j <= k; j++) { //2, 5 등등의 기본화폐단위는 절대로 그 이하의 화폐단위를 못 만들기 때문에 j는 화폐단위부터 시작.
            dp[j] = dp[j] + dp[j - money[i]]; // j - money[i] = 화폐를 더하기 이전의 dp index.
        }
    }

    cout << dp[k] << '\n';
    return 0;
}
