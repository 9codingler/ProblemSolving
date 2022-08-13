#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[2001];
int arr[2001];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }


    for(int i = 1; i <= n; i++) { //부분수열의 길이를 1로 초기화.
        dp[i] = 1;
    }

    int ans = 0;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(arr[i] < arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << n - ans << '\n'; //열외해야 하는 병사수이므로 n - ans.
    return 0;
}
