#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;
    vector<int> a;
    vector<int> b;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += a[i] * b[i];
    }

    cout << ans <<'\n';
    return 0;
}
