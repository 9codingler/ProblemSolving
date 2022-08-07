#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<pair<int, pair<int, int>>> graph;
int parent[10001];
int v, e;

int findParent(int x) {
    if(parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = findParent(parent[x]);
    }
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
    cin >> v >> e;
    for(int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < e; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph.push_back(make_pair(cost, make_pair(from, to)));
    }

    sort(graph.begin(), graph.end());
    ll ans = 0;

    for(int i = 0; i < graph.size(); i++) {
        int cost = graph[i].first;
        int a = graph[i].second.first;
        int b = graph[i].second.second;

        if(findParent(a) != findParent(b)) {
            unionParent(a, b);
            ans += cost;
        }
    }

    cout << ans << '\n';
    return 0;
}
