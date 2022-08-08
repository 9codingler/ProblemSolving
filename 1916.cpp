#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;
int n, m;
vector<pair<int, int>> graph[1001];
int d[1001];

void dijkstra(int startcity) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(0, startcity));
    d[startcity] = 0;
    while(!pq.empty()) {
        int dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(d[cur_node] < dist) {
            continue;
        }
        for(int i = 0; i < graph[cur_node].size(); i++) {
            int next_dist = dist + graph[cur_node][i].first;
            int next_node = graph[cur_node][i].second;

            if(d[next_node] > next_dist) {
                d[next_node] = next_dist;
                pq.push(make_pair(next_dist, next_node));
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(cost, to));
    }

    fill(d, d + 1001, INF);

    int startcity, arrivecity;
    cin >> startcity >> arrivecity;

    dijkstra(startcity);

    cout << d[arrivecity] << '\n';
    return 0;
}
