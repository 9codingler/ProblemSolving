#include <iostream>
using namespace std;
long long dp[68];

long long koong(int n) {
    if(n < 2) {
        dp[n] = 1;
    }

    if(n == 2) {
        dp[n] = 2;
    }

    if(n == 3) {
        dp[n] = 4;
    }

    if(dp[n] != 0) {
        return dp[n];
    }

    else {
        dp[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
    }

    return dp[n];
}

int main() {
    int t;
    cin >> t;
    for(int test = 0; test < t; test++) {
        int n;
        cin >> n;
        cout << koong(n) << '\n';
    }
    return 0;
}
