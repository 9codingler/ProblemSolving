#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001

using namespace std;

vector<int> map(10001, MAX); // 각 인덱스까지의 거리를 저장하는 vector.
vector<pair<int, int>> v[10001]; // (출발지, 거리)pair 저장하는 vector. 각 인덱스는 도착지점을 의미한다.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    cin >> n >> d;

    for(int i = 0; i < n; i++) {
        int from, to, shortcut;
        cin >> from >> to >> shortcut;
        if(to > d || to - from < shortcut) {
            continue;
        }
        v[to].push_back(make_pair(from, shortcut));
    }

    map[0] = 0;

    for(int i = 1; i <= d; i++) {
        map[i] = map[i - 1] + 1;
        for(int j = 0; j < v[i].size(); j++) {
            map[i] = min(map[i], map[v[i][j].first] + v[i][j].second);
        }
    }

    cout << map[d];

}
