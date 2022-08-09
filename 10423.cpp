#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, pair<int, int>>> graph;
int parent[1001];
int n, m, k;

//findParent, unionParent, 사이클 조건 다시보기.
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
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    } 

    for(int i = 0; i < k; i++) {
        int powerstation;
        cin >> powerstation;
        parent[powerstation] = -1; // 발전소끼리 같은 집합으로 합친다.
    }

    for(int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph.push_back(make_pair(cost, make_pair(from, to)));
    }

    sort(graph.begin(), graph.end());
    int ans = 0;

    for(int i = 0; i < graph.size(); i++) {
        int cost = graph[i].first;
        int from = graph[i].second.first;
        int to = graph[i].second.second;

        if(findParent(from) != findParent(to)) {
            unionParent(from, to);
            ans += cost;
        }
    }

    cout << ans << '\n';
    return 0;

}
