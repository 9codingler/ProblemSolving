#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;
int graph[101][101];
int dist[101][101];

int dx[] = {0, 1, 0, -1}; //동 남 서 북.
int dy[] = {1, 0, -1, 0};

int n, m;

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {1, 1}});
    dist[1][1] = 0;

    while(!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > n || ny > m) {
                continue;
            }

            if(dist[nx][ny] < cost) {
                continue;
            }
            
            if(dist[nx][ny] > dist[x][y] + graph[nx][ny]) {
                dist[nx][ny] = dist[x][y] + graph[nx][ny];
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
    }
}

int main() {
    cin >> m >> n;
    
    fill(&dist[1][1], &dist[100][101], INF);

    //가로크기 m, 세로크기 n이면 for문 밑에처럼 받으면 됨.
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    dijkstra();

    cout << dist[n][m] << '\n';
    return 0;
}
