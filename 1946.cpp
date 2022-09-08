#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--) {
        vector<pair<int, int>> v;
        cin >> n;

        for(int i = 0; i < n; i++) {
            int first, second;
            cin >> first >> second;
            v.push_back({first, second});
        }

        sort(v.begin(), v.end());
        
        int idx = 0;
        int count = 1;

        for(int i = 1; i < v.size(); i++) {
            // 검사하는 사람의 인터뷰 순위가 기존의 뽑힌사람보다 높다면.
            // 이미 위에서 sort해줬기 때문에 서류순위 자체는 무조건 idx의 순위가 높다. 그리고 i의 순위는 i보다 뒤에 있는 사람들보다 높다.
            if(v[i].second < v[idx].second) {
                count++;
                idx = i;
            }
        }

        cout << count << '\n';
    }
    return 0;
}
