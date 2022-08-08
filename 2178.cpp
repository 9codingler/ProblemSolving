#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
bool visited[101][101];
int dx[] = {0, 1, 0, -1}; // 동 남 서 북
int dy[] = {1, 0, -1, 0};

int n, m, ans = 1; //시작위치부터 칸을 세기 때문에 ans = 1부터 시작.

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    visited[1][1] = true;
    int tmpsize = q.size();
    int tmpsum = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        tmpsum++;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(visited[nx][ny] || map[nx][ny] == 0 || nx < 1 || ny < 1 || nx > n || ny > m) {
                continue;
            }

            if(nx == n && ny == m) {
                ans++; //44line if문이 실행되지 않으므로, 마지막 도착할때 이동횟수까지 더해줘야 답이다.
                cout << ans << '\n';
                return;
            }

            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
            
        }

        if(tmpsum == tmpsize) { //큐 한번 다 비워내면.
            tmpsum = 0;
            tmpsize = q.size();
            ans++;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    bfs();

    return 0;
}
