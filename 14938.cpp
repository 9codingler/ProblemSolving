// 출발점이 따로 주어지지 않았지만, floid + bfs로 안되더라.. 일단 dikjstra.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int graph[101][101];
int items[101];

vector<pair<int, int>> v[101]; // 인덱스는 현재노드, (거리, 다음노드) pair담는 vec.

int n, m, r, ans = -1;

void dijkstra(int start) {
    int d[101]; // 각 시작점마다의 최단거리를 측정할 것이므로 전역이 아닌 지역변수로 d배열 선언.
    int sum = 0; // 각 시작점마다의 가질 수 있는 item을 담는 지역변수.
    fill(d, d + 101, INF);
    d[start] = 0; //순서 주의하자. INF로 fill 하고 시작점의 거리는 0이다.
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(d[cur_node] < cost) {
            continue;
        }

        for(int i = 0; i < v[cur_node].size(); i++) {
            int next_cost = cost + v[cur_node][i].first;
            int next_node = v[cur_node][i].second;

            // if(next_cost > m) {
            //    continue; 
            // }

            if(next_cost < d[next_node]) {
                pq.push(make_pair(next_cost, next_node));
                d[next_node] = next_cost;
            }
        }
    }
    //위에까지 하면 d배열 setting 완료.

    for(int i = 1; i <= n; i++) {
        if(d[i] <= m) { // start 시작점에서 각 점 i까지의 거리(i에는 시작점도 포함)가 수색범위 m보다 작으면 도달할 수 있다는 말이므로.
            sum += items[i]; // 가질 수 있는 아이템 갯수를 sum에다 더해준다.
        }
    }

    ans = max(ans, sum); // 각점마다의 dijkstra 결과를 비교해서 최종 ans 출력.
}

int main() {
    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    for(int i = 0; i < r; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back(make_pair(cost, to));
        v[to].push_back(make_pair(cost, from)); //양방향 그래프이므로.
    }

    for(int i = 1; i <= n; i++) {
        dijkstra(i);
    }

    cout << ans << '\n';
    return 0;
}
