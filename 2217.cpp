#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int ans = -1;

    for(int i = 0; i < n; i++) {
        ans = max(ans, v[i] * (n - i));
    }

    cout << ans << '\n';
    return 0;
}
