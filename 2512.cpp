#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int budget;
        cin >> budget;
        v.push_back(budget);
    }

    cin >> m;

    sort(v.begin(), v.end());

    int start = 1;
    int end = v[n - 1];
    int ans;

    while(1) {
        if(start > end) {
            break;
        }

        int sum = 0;

        int mid = (start + end) / 2;

        for(int i = 0; i < n; i++) {
            if(v[i] - mid >= 0) { 
                sum += mid;
            }
            else {
                sum += v[i];
            }
        }

        if(sum > m) { // 요구한 예산보다 크면, 예산 줄인다.
            end = mid - 1;
        }

        else {
            ans = mid;
            start = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
