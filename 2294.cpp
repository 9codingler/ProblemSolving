#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 1e9
using namespace std;
int dp[100001];

int main() {
    int n, m;
    vector<int> money;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        money.push_back(tmp);
    }
    fill(dp, dp + 10001, INF);
    sort(money.begin(), money.end());
    
    for(int i = 0; i < money.size(); i++) {
        dp[money[i]] = 1;
    }

    int first = money[0];
    for(int i = first; i <= m; i++) {
        for(int j = i - 1; j >= first; j--) {
            if(dp[i - j] == INF) { //만들 수 없는 화폐인경우.
                continue;
            }
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
    }

    if(dp[m] == INF) {
        cout << -1 << '\n';
    }

    else {
        cout << dp[m] << '\n';
    }

    return 0;
}
