#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;
int n, m, k;

vector<pair<int, int>> graph[1001];
priority_queue<int> heap[1001]; // k번째 작은수를 top으로 갖는 max heap

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    heap[1].push(0);

    while(!pq.empty()) {
        int cur_node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        
        for(int i = 0; i < graph[cur_node].size(); i++) {
            int cost = dist + graph[cur_node][i].first;
            int next_node = graph[cur_node][i].second;

            if(heap[next_node].size() < k) {
                heap[next_node].push(cost);
                pq.push({cost, next_node});
            }
            else {
                if(heap[next_node].top() > cost) {
                    heap[next_node].pop();
                    heap[next_node].push(cost);
                    pq.push({cost, next_node});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({cost, to});
    }
    
    dijkstra();

    for(int i = 1; i <= n; i++) {
        if(heap[i].size() < k) {
            cout << -1 << '\n';
        }
        else {
            cout << heap[i].top() << '\n';
        }
    }
    return 0;
}
