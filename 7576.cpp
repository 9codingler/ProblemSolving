#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int map[1001][1001];
bool visited[1001][1001];
int dx[] = {0, 1, 0, -1}; // 동 남 서 북.
int dy[] = {1, 0, -1, 0};
int n, m;
int day = 0;
queue<pair<int, int>> q;

void bfs() {
    int size = q.size();

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        size--;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(map[nx][ny] == -1 || nx < 1 || nx > n || ny < 1 || ny > m || visited[nx][ny]) {
                continue;
            }

            q.push({nx, ny});
            visited[nx][ny] = true;
            map[nx][ny] = 1;
        }

        if(size == 0) {
            size = q.size();
            if(size == 0) { // 애초에 큐가 다 빈경우 == bfs 다 돈 경우.
                break;
            }
            day++;
        }
    }

    bool flag = false;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(map[i][j] == 0) {
                flag = true;
                break;
            }
        }
    }

    if(flag) { //하나라도 안 익은 토마토가 있는 경우.
        cout << -1 << '\n';
        return;
    }

    else {
        cout << day << '\n';
        return;
    }
}

int main() {
    cin >> m >> n;
    bool flag = true;
    pair<int, int> start;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                start = {i, j};
                q.push(start);
                visited[start.first][start.second] = true;
            }
            if(map[i][j] == 0) {
                flag = false;
            }
        }
    }

    if(flag) { //입력때부터 모든 토마토가 익은 상태인 경우.
        cout << 0 << '\n';
        return 0;
    }

    bfs();
    return 0;
}
