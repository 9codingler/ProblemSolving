#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

#define INF 2e9

using namespace std;

vector<int> v;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int left = 0;
    int right = n - 1;

    for(int i = 0; i < n; i++) {
        int liquid;
        cin >> liquid;
        v.push_back(liquid);
    }

    sort(v.begin(), v.end());
    int ans = INF;
    pair<int, int> ansp;

    while(1) {
        if(left >= right) {
            break;
        }

        int tmp = v[left] + v[right];

        if(ans > abs(tmp)) {
            ans = abs(tmp);
            ansp = make_pair(v[left], v[right]);
        }

        if(tmp < 0) { // 합이 음수이므로 더 커지도록 만들어야 함.
            left++;
        }

        else if(tmp > 0) {
            right--;
        }

        else if(tmp == 0){
            cout << ansp.first << ' ' << ansp.second << '\n';
            return 0;
        }
    }

    cout << ansp.first << ' ' << ansp.second << '\n';
    return 0;
}
