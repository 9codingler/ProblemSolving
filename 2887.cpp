#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <tuple>

using namespace std;
int parent[100001];
vector<pair<int, int>> xs;
vector<pair<int, int>> ys;
vector<pair<int, int>> zs;
vector<pair<int, pair<int, int>>> graph;
int n;

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
    cin >> n;
    for(int i = 1; i <= n; i++) {
        pair<int, int> starx;
        pair<int, int> stary;
        pair<int, int> starz;

        int x, y, z;
        cin >> x >> y >> z;
        starx = make_pair(x, i);
        stary = make_pair(y, i);
        starz = make_pair(z, i);

        xs.push_back(starx);
        ys.push_back(stary);
        zs.push_back(starz);
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    sort(zs.begin(), zs.end());

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < n - 1; i++) {
        int distx = abs(xs[i].first - xs[i + 1].first);
        int disty = abs(ys[i].first - ys[i + 1].first);
        int distz = abs(zs[i].first - zs[i + 1].first);

        graph.push_back(make_pair(distx, make_pair(xs[i].second, xs[i + 1].second)));
        graph.push_back(make_pair(disty, make_pair(ys[i].second, ys[i + 1].second)));
        graph.push_back(make_pair(distz, make_pair(zs[i].second, zs[i + 1].second)));
    }

    sort(graph.begin(), graph.end()); //x, y, z 상관없이, 각각 행성간의 거리를 오름차순 정렬 -> 원하는 답 도출.
    int ans = 0;

    for(int i = 0; i < graph.size(); i++) {
        int dist = graph[i].first;
        int from = graph[i].second.first;
        int to = graph[i].second.second;

        if(findParent(from) != findParent(to)) {
            ans += dist;
            unionParent(from, to);
        }
    }

    cout << ans << '\n';
    return 0;
}
