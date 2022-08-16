// idea : 남겨놔야 하는 to들은 가장 긴 증가하는 부분수열 형태. -> 답은 (n - 증가하는 부분수열의 크기).
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> v;
int arr[501]; //to 저장 배열.
int dp[501]; //LIS 저장 배열.

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int from, to;
        cin >> from >> to;
        v.push_back(make_pair(from, to));
    }
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; i++) {
        arr[i] = v[i - 1].second; //정렬된 후의 to를 arr배열에 집어넣는다. LIS를 쓰기 위함.
    }

    for(int i = 1; i <= n; i++) {
        dp[i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << n - ans << '\n';
}
