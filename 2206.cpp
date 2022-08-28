#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int map[1001][1001];
bool visited[1001][1001][2];

int dx[] = {0, 1, 0, -1}; // 동 남 서 북.
int dy[] = {1, 0, -1, 0};
int dist = 1;

int bfs() {
    queue<pair<pair<int, int>, int>> q;
    visited[1][1][1] = true;
    visited[1][1][0] = true;
    q.push({{1, 1}, 0}); // {{x, y} , 벽부숨 유무} push.
    int size = q.size();

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int crashed = q.front().second;
        size--;

        q.pop();

        if(x == n && y == m) {
            return dist;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny][crashed]) {
                if(crashed == 0 && map[nx][ny] == 0) { //벽을 한번도 부순적이 없고, 벽 없는곳을 갈 때.
                    visited[nx][ny][crashed] = true;
                    q.push({{nx, ny}, 0});
                }
                else if(crashed == 0 && map[nx][ny] == 1) { //벽을 한번도 부순적이 없고, 벽 있는곳을 갈 때.
                    visited[nx][ny][crashed] = true;
                    q.push({{nx, ny}, 1});
                }
                else if(crashed == 1 && map[nx][ny] == 0) { //이미 벽을 부쉈고, 벽이 없는 곳을 갈 때.
                    visited[nx][ny][crashed] = true;
                    q.push({{nx, ny}, 1});
                }
                else if(crashed == 1 && map[nx][ny] == 1) { //이미 벽을 부쉈고, 벽이 있는곳을 갈 때 -> 못간다.
                    continue;
                }
            }
        }

        if(size == 0) {
            size = q.size();
            dist++;
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    cout << bfs() << '\n';
}
