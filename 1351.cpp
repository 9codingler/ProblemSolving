#include <iostream>
#include <map>
typedef long long ll;

using namespace std;

ll p, q;
map<ll, ll> dp;

ll solve(ll n) {
    if(n == 0) {
        return 1;
    }
    if(dp.find(n) != dp.end()) {
        return dp[n];
    }
    return dp[n] = solve(n / p) + solve(n / q);
}

int main() {
    ll n;
    cin >> n >> p >> q;
    cout << solve(n) << '\n';
    return 0;
}
