#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int map[50][50]; // 보니까 위치 0, 0부터 입력받아서 map크기는 딱맞게 써야함.
bool visited[50][50];
int dx[] = {0, 1, 0, -1}; //동 남 서 북
int dy[] = {1, 0, -1, 0};
int n, m, ans = 0;

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    visited[a][b] = true;
    q.push(make_pair(a, b));

    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if(map[nx][ny] == 0 || visited[nx][ny] || nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }

            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
    ans++;
}

int main() {
    int t;
    cin >> t;
    for(int test = 0; test < t; test++) {
        vector<pair<int, int>> v; //테케마다 cabbage 받는 벡터 v 초기화.
        int cabbage;
        cin >> n >> m >> cabbage;
        for(int i = 0; i < cabbage; i++) {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
            v.push_back(make_pair(x, y));
        }
        for(int i = 0; i < v.size(); i++) {
            if(!visited[v[i].first][v[i].second]) {
                bfs(v[i].first, v[i].second);
            }
        }
        cout << ans << '\n';
        ans = 0; //테케마다 ans = 0초기화.
        memset(visited, false, sizeof(visited)); //테케 끝났으면 visited, map도 초기화.
        memset(map, 0, sizeof(map));

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cout << map[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }

    return 0;
}
