#include <iostream>
#include <queue>
#include <vector>
#define INF 3 * 800 * 1000 + 1
using namespace std;

int d[801];
vector<pair<int, int>> graph[801];
int n, e, v1, v2;
int ans = INF;
// 1에서 v1, v1에서 v2, v2에서 n번으로..?
// 1에서 v1 먼저가는경우, 1에서 v2 먼저가는경우 둘다 해보고 최솟값으로 ans.

void dijkstra(int firstpoint, int secondpoint) {
    fill(d, d + 801, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    d[1] = 0;
    
    while(!pq.empty()) {
        int cur = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if(d[cur] < dist) {
            continue;
        }

        for(int i = 0; i < graph[cur].size(); i++) {
            int cost = dist + graph[cur][i].first;
            int next = graph[cur][i].second;

            if(d[next] < cost) {
                continue;
            }

            d[next] = cost;
            pq.push({cost, next});
        }
    }

    int tmpans = 0;
    tmpans += d[firstpoint];

    fill(d, d + 801, INF);
    pq.push({0, firstpoint});
    d[firstpoint] = 0;

    while(!pq.empty()) {
        int cur = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if(d[cur] < dist) {
            continue;
        }

        for(int i = 0; i < graph[cur].size(); i++) {
            int cost = dist + graph[cur][i].first;
            int next = graph[cur][i].second;

            if(d[next] < cost) {
                continue;
            }

            d[next] = cost;
            pq.push({cost, next});
        }
    }

    tmpans += d[secondpoint];

    fill(d, d + 801, INF);
    pq.push({0, secondpoint});
    d[secondpoint] = 0;

    while(!pq.empty()) {
        int cur = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if(d[cur] < dist) {
            continue;
        }

        for(int i = 0; i < graph[cur].size(); i++) {
            int cost = dist + graph[cur][i].first;
            int next = graph[cur][i].second;

            if(d[next] < cost) {
                continue;
            }

            d[next] = cost;
            pq.push({cost, next});
        }
    }

    tmpans += d[n];
    
    ans = min(ans, tmpans);
}

int main() {
    cin >> n >> e;
    for(int i = 0; i < e; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({cost, to});
        graph[to].push_back({cost, from});
    }

    cin >> v1 >> v2;

    dijkstra(v1, v2);
    dijkstra(v2, v1);

    if(ans >= INF) {
        cout << -1 << '\n';
        return 0;
    }

    cout << ans << '\n';
    return 0;
}
