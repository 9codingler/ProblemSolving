// dijkstra ver.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[20001]; //다음 노드까지의 거리, 다음 노드번호.
int d[20001];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (1, 현재노드번호) pair.
    pq.push(make_pair(0, 1));

    while(!pq.empty()) {
        int dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(d[cur_node] < dist) {
            continue;
        }

        for(int i = 0; i < graph[cur_node].size(); i++) {
            int cost = dist + graph[cur_node][i].first;
            int next_node = graph[cur_node][i].second;
            if(cost < d[next_node]) {
                d[next_node] = cost;
                pq.push(make_pair(cost, graph[cur_node][i].second)); //next node까지의 거리와 next node를 우선순위큐 삽입.
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    fill(d, d + 20001, INF);

    for(int i = 0; i < m; i++) {
        int A_i, B_i;
        cin >> A_i >> B_i;
        graph[A_i].push_back(make_pair(1, B_i));
        graph[B_i].push_back(make_pair(1, A_i));
    }

    d[1] = 0;
    dijkstra();

    int ans = -1;
    int sum = 0;
    int ansnode;
    bool flag = false;

    for(int i = 1; i <= n; i++) {
        if(d[i] != INF) {
            ans = max(ans, d[i]);
        }
    } 

    for(int i = 1; i <= n; i++) {
        if(d[i] == ans) {
            sum++;
            if(!flag) {
                ansnode = i;
                flag = true;
            }
        }
    }

    cout << ansnode << ' ' << ans << ' ' << sum << '\n';
    return 0;
}
