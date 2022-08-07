#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> v;
int parent[100001];
int n, m;

int findParent(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if(a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v.push_back(make_pair(cost, make_pair(from, to)));
    }

    sort(v.begin(), v.end());
    int ans = 0;
    int last;

    for(int i = 0; i < v.size(); i++) {
        int cost = v[i].first;
        int a = v[i].second.first;
        int b = v[i].second.second;

        if(findParent(a) != findParent(b)) {
            unionParent(a, b);
            ans += cost;
            last = cost;
        }
    }

    cout << ans - last << '\n';
    return 0;
}
